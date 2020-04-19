#ifndef MEASURE_H
#define MEASURE_H
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;


class Measure{
private:
	mutex _m; //allow or not allow thing to be written in this object;
	int pos_x;
	int pos_y;
	int size_w;
	int size_h;
	int idx;
	char *data;
	Ptr<BackgroundSubtractor> pBackSub;
	Mat fgMask;
	int threshold;

	int mem_size;

	void runner();
	int countPixels(Mat &image, Scalar color);
	bool is_busy; //must be thread-save protected
	void  (*callback_fcn)(int, int);

	thread *t;

public:
	void set_callback(void (*fcn)(int, int)){callback_fcn = fcn; }; //callback function to set the points records in the next abstraction
	bool set_mem(char *d, int w, int h); // try to lock the mutex, return false if busy

	Measure(int th, int id,int s_w, int s_h, int x, int y);
	~Measure();
};


#endif
