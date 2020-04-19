#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

#define NUMBER_OF_PICTURES 100

int main ( int argc,char **argv ) {
	char file_name[100];
	memset(file_name,0,100);
    time_t timer_begin,timer_end;
    raspicam::RaspiCam_Cv Camera;
    cv::Mat image[NUMBER_OF_PICTURES];
    int nCount=NUMBER_OF_PICTURES;
    //set camera params
    Camera.set( CAP_PROP_FORMAT, CV_8UC1 );
    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
    //Start capture
    cout<<"Capturing "<<nCount<<" frames ...."<<endl;
    time ( &timer_begin );
    for ( int i=0; i<nCount; i++ ) {

        if(Camera.grab()){
        	Camera.retrieve ( image[i]);
        }
        else{
        	cout<<"not grabed "<<i<<endl;
        }
    }
    cout<<"Stop camera..."<<endl;
    Camera.release();

    cout<<"show picture statistics"<<endl;
    time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
    double secondsElapsed = difftime ( timer_end,timer_begin );
    cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;


    cout<<"save image"<<endl;
    time ( &timer_begin );

    for ( int i=0; i<nCount; i++ ) {
		sprintf(file_name, "/home/pi/cpp_cam/ramdisk/img_%d_cv.jpg",i);
		cout<<file_name<<endl;
		cv::imwrite(cv::String(file_name),image[i]);
    }

    cout<<"show record statistics"<<endl;
    time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
    secondsElapsed = difftime ( timer_end,timer_begin );
    cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;


}
