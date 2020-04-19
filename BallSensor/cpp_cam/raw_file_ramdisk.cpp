#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
#include <chrono>
#include <thread>

using namespace std;
#define NUMBER_OF_FRAMES 1
int main ( int argc,char **argv ) {
	char fileName[100];
	bool dummy;
	memset(fileName,0,100);
    time_t timer_begin,timer_end;
    raspicam::RaspiCam Camera; //Cmaera object
    Camera.setWidth(1080);
    Camera.setHeight(1080);

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //capture
    time ( &timer_begin );

    for(int i =0; i< NUMBER_OF_FRAMES; i++)
    {
        Camera.grab();
        //allocate memory
        sprintf(fileName,"/home/pi/cpp_cam/ramdisk/image_%d_.ppm",i);
        //extract the image in rgb format
        Camera.retrieve_file ( fileName, raspicam::RASPICAM_FORMAT_BGR );//get camera image
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
    cout<<"Stop camera..."<<endl;
    Camera.release();
    cout<<"show picture statistics"<<endl;
    time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
    double secondsElapsed = difftime ( timer_end,timer_begin );
    cout<< secondsElapsed<<" seconds for "<< NUMBER_OF_FRAMES<<"  frames : FPS = "<<  ( float ) ( ( float ) ( NUMBER_OF_FRAMES ) /secondsElapsed ) <<endl;
    return 0;
}
