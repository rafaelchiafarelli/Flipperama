#include "Measure.h"
#include <iostream>
#include <map>
#include <string.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <cstddef>
#include <fstream>


int Measure::countPixels(Mat &image, Scalar color) {

    Mat binary_image;
    Scalar Zero(0,0,0);
    inRange(image, Zero, color, binary_image);
        return countNonZero(binary_image);
}
void Measure::runner()
{
	is_busy = true;
	//start the ROI processing to see if there is a passage

	Mat frame =  Mat(size_w,size_h, CV_8UC3, data);


	pBackSub->apply(frame, fgMask);

	Mat gray;
	cvtColor(frame,gray,COLOR_RGB2GRAY);
	Mat bw;
    cv::threshold(gray, bw, 40, 255, THRESH_BINARY_INV | THRESH_OTSU);
    vector<Point> black_pixels;   // output, locations of non-zero pixels
    cv::findNonZero(bw, black_pixels);
    int b_p= black_pixels.size();

    if(b_p>threshold){
    	cout<<"PONTO: idx:"<<idx<<"; th: "<<b_p<<";"<<endl;
		if (callback_fcn)
		{
			callback_fcn(idx, b_p);
		}
    }
	is_busy = false;
}

bool Measure::set_mem(char *d, int w, int h){
	static int counter=0;
	if (is_busy)
		return false;
	if(w<pos_x || h<pos_y)
		return false;

	//get line by line of frame
	for(int i =pos_y,j=0; i< pos_y+size_h ; i++,j++)
	{
		memcpy(&data[j*size_w*3], &d[(i*w*3)+pos_x], size_w*3);
	}

	if(t->joinable()){
		t->join();
		delete t;
		t = new thread(&Measure::runner,this);
	}
	return true;
}


Measure::Measure(int th, int id, int s_w, int s_h, int p_x, int p_y)
{
	//creates the image data space
	mem_size = s_w * s_h * 3; // size of a RGB'like image
	data = new char[mem_size];
	pBackSub = createBackgroundSubtractorKNN();
	memset(data,127,mem_size);
	pos_x = p_x;
	pos_y = p_y;
	size_w = s_w;
	size_h = s_h;
	idx = id;
	threshold = th;
	// clear callback_fucntion to protect a call
	callback_fcn = NULL;
	t = new thread(&Measure::runner,this);
}
Measure::~Measure(){
	t->join();
	delete data;
}




