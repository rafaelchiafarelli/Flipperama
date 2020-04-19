#include <inotify-cpp/NotifierBuilder.h>

#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/ioctl.h>
#include "Measure.h"
#include <dirent.h>
#include <mosquitto.h>

#include <stdio.h>
#include <mosquitto.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace inotify;
using namespace std;

#define RAW_FILE_SIZE 3499217
//todo: investigate if this size can get bigger
#define FILE_SIZE RAW_FILE_SIZE + 500000 //put some chars into the size... just in case
#define MAX_MEASURE_ROI 50

typedef struct{
	Measure *measure[MAX_MEASURE_ROI];
	char memblock[FILE_SIZE];
	char *configFile;
	char ramdiskPath[200];
	int number_of_rois;

}ROI_TYPE;

ROI_TYPE ROIs;

void mqtt_send(int idx, int th);

bool Reader(const char *p)
{
/**
 * Read the contents of the file.
 * Create the new ROI´s
 * copy the memory into all free measure
 * leave
 * */
	int location = 0, size = 0, width = 0, height = 0;
	ifstream file (p, ios::binary);
	if (!file.is_open())
		return false;
	string str_P6;
	string str_FrameSize;
	getline(file,str_P6);
	getline(file,str_FrameSize);
	istringstream s2(str_FrameSize);
	s2 >> height;
	s2 >> width;
	location = file.tellg();
	file.seekg (0, file.end);
	size = file.tellg();
	file.seekg (location);
	file.read (ROIs.memblock, size);
	file.close();
	for(int i =0; i< ROIs.number_of_rois; i++)
	{
		ROIs.measure[i]->set_mem(ROIs.memblock,width, height);
	}
	return true;
}

bool kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}


bool Setup(int argc, char** argv)
{
    int path_size = (int)strlen(argv[1])+1;

	ROIs.configFile = new char[path_size];
	memset(ROIs.configFile,0,path_size);
	memcpy(ROIs.configFile, argv[1],path_size);

	ifstream file (ROIs.configFile, ios::binary);

	if (!file.is_open())
		return false;

	string str_Dir;
	string str_Number_of_ROIs;
	getline(file,str_Dir);
	strncpy(ROIs.ramdiskPath,str_Dir.c_str(),str_Dir.length()-1);

	DIR *pDir;
    pDir = opendir(ROIs.ramdiskPath);
    if (pDir != NULL)
    {
        (void) closedir (pDir);
    }
    else
    {
    	return false;
    }

	getline(file,str_Number_of_ROIs);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	istringstream s2(str_Number_of_ROIs);

	s2 >> ROIs.number_of_rois;

	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	if(ROIs.number_of_rois>MAX_MEASURE_ROI)
		return false;

    for (int i = 0; i<ROIs.number_of_rois;i++)
    {
    	int th, w, h, s_w, s_h, id;
    	string l;
    	getline(file,l);
    	istringstream s3(l);
    	s3 >> id;
    	s3 >> h;
    	s3 >> w;
    	s3 >> s_w;
    	s3 >> s_h;
    	s3 >> th;
    	ROIs.measure[i] = new Measure(th,id,s_w,s_h,w,h);
    	ROIs.measure[i]->set_callback(mqtt_send);
    }

    memset(ROIs.memblock,127,FILE_SIZE);
    return true;
}

void mosq_log_callback(struct mosquitto *mosq, void *userdata, int level, const char *str)
{
	/* Pring all log messages regardless of level. */

  switch(level){
    //case MOSQ_LOG_DEBUG:
    //case MOSQ_LOG_INFO:
    //case MOSQ_LOG_NOTICE:
    case MOSQ_LOG_WARNING:
    case MOSQ_LOG_ERR: {
      printf("%i:%s\n", level, str);
    }
  }


}

struct mosquitto *mosq = NULL;
char *topic = NULL;
void mqtt_setup(){

	char *host = "localhost";
	int port = 1883;
	int keepalive = 60;
	bool clean_session = true;
  topic = "/pimbal/point";

  mosquitto_lib_init();
  mosq = mosquitto_new(NULL, clean_session, NULL);
  if(!mosq){
		fprintf(stderr, "Error: Out of memory.\n");
		exit(1);
	}

  mosquitto_log_callback_set(mosq, mosq_log_callback);

  if(mosquitto_connect(mosq, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		exit(1);
	}
  int loop = mosquitto_loop_start(mosq);
  if(loop != MOSQ_ERR_SUCCESS){
    fprintf(stderr, "Unable to start loop: %i\n", loop);
    exit(1);
  }
}

void mqtt_send(int idx, int th){
	cout<<"got here and the idx is:"<<idx<<" will publish it in topic: "<<topic<<endl;
	char msg[10];
	sprintf(msg, "%d %d",idx,th);
	mosquitto_publish(mosq, NULL, topic, strlen(msg), msg, 0, 0);
}




int main(int argc, char** argv)
{
    if (argc <= 1) {
        std::cout << "Erro! Uso: ./EventROI /path/to/config_file " << std::endl;
        exit(0);
    }
    if(!Setup(argc, argv)){
        std::cout << "Erro! arquivo de configuração inválido!" << std::endl;
        exit(0);
    }


    mqtt_setup();



    // Parse the directory to watch
    // Set the event handler which will be used to process particular events
    auto handleNotification = [&](Notification notification) {
        if (notification.event == Event::close_write)
        		if (!Reader(notification.path.c_str()))
        			cout<<"not possible to create ROI"<<endl;
    };

    // Set the events to be notified for
    auto events = {	Event::remove,
                    Event::close_write  };

    // The notifier is configured to watch the parsed path for the defined events. Particular files
    // or paths can be ignored(once).
    boost::filesystem::path path(ROIs.ramdiskPath);
    auto notifier = BuildNotifier()
                        .watchPathRecursively(path)
                        .ignoreFileOnce("fileIgnoredOnce")
                        .ignoreFile("fileIgnored")
                        .onEvents(events, handleNotification);

    // The event loop is started in a separate thread context.
    std::thread thread([&](){ notifier.run(); });




    while(1)
    {
    	if (kbhit())
        {
    		cout<<"Good bye"<<endl;
            break;
        }
    	 std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    for(int i =0; i< ROIs.number_of_rois;i++)
    {
    	delete ROIs.measure[i];
    }
    notifier.stop();
    thread.join();
    return 0;
}
