#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string>
#include <termios.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

using namespace std;


#define NUMBER_OF_FRAMES 80

bool fexists(const char *filename)
{
	bool ret = true;
	ifstream file(filename);
	if(!file)
		ret = false;
	file.close();
	return ret;
}

bool deleteFiles(char *dir)
{
    DIR *dp;
    struct dirent *dirp;
    char FilePath[100];
    memset(FilePath,0,100);

    if((dp  = opendir(dir)) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return false;
    }

    while ((dirp = readdir(dp)) != NULL) {

    	sprintf(FilePath,"%s/%s",dir,dirp->d_name);
		cout<<"remove file: "<< FilePath<<endl;
        remove(FilePath);
    }
    closedir(dp);
    return true;
}

void enable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}

bool kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}

int main ( int argc,char **argv ) {
	char CompletePath[NUMBER_OF_FRAMES][100]; //all the files managed by this program
	char *FileDir;
	int Period_ms;
	bool clearDisk = false;
	int counter =0;
	double secondsElapsed;
	int millisec;
	struct tm* tm_info;
	struct timeval tv;
	char ch;
    if (argc <= 2) {
        std::cout << "Erro! Uso: ./continuous /path/to/ramdisk FrameRate clearDisk" << std::endl;
        exit(0);
    }
    //get the file
    int path_size = (int)strlen(argv[1])+1;
	FileDir = new char[path_size];
	memset(FileDir,0,path_size);
	memcpy(FileDir, argv[1],path_size);
	//get the FrameRate and transform it to Period
	Period_ms = (int)1000/atoi(argv[2]) - 33;
	if(Period_ms > 200 || Period_ms < 0){
        std::cout << "Erro! FrameRate deve ser entre 5 e 30 frames por segundo" << std::endl;
        exit(0);
	}

	clearDisk = (bool)(atoi(argv[3]));
	if(clearDisk)
		if(!deleteFiles(FileDir))
		{
	        std::cout << "Erro! Diretório não existente!" << std::endl;
	        exit(0);
		}


	for(int i = 0; i<NUMBER_OF_FRAMES;i++)
		memset(CompletePath[i],0,100);
    time_t timer_begin,timer_end;
    raspicam::RaspiCam Camera; //Camera object
    Camera.setWidth(1280);
    Camera.setHeight(960);

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //capture,
    enable_raw_mode();
    while(1)
    {
    	if (kbhit())
        {
    		cout<<"Good bye"<<endl;
            break;
        }

        //delete the file if it exists
        if (fexists(CompletePath[counter])){
        	remove(CompletePath[counter]);
        }

        gettimeofday(&tv, NULL);
        millisec = lrint(tv.tv_usec/1000.0); // Round to nearest millisec
        if (millisec>=1000) { // Allow for rounding up to nearest second
          millisec -=1000;
          tv.tv_sec++;
        }

        tm_info = localtime(&tv.tv_sec);
        char FileName[40];

        int pos = strftime(FileName,100,"/image_%Y-%m-%d %H-%M-%S-",tm_info);
        sprintf(FileName+pos,"%03d.ppm", millisec);
        sprintf(CompletePath[counter],"%s%s",FileDir,FileName);

        cout<<CompletePath[counter]<<endl;
        Camera.grab();
    	//extract the image in bgr format
    	Camera.retrieve_file ( CompletePath[counter], raspicam::RASPICAM_FORMAT_RGB );//get camera image

    	counter+=1;
        if(counter >= NUMBER_OF_FRAMES)
        	counter=0;
        std::this_thread::sleep_for(std::chrono::milliseconds(Period_ms));

    }
    if(clearDisk)
		for(int i=0; i< NUMBER_OF_FRAMES; i++)
		{
			if (fexists(CompletePath[i])){
				remove(CompletePath[i]);
			}
		}
    disable_raw_mode();
    Camera.release();
    return 0;
}
