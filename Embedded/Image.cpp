/*
 * Image.cpp
 *
 *  Created on: 29 de ago de 2019
 *      Author: rafae
 */

#include "Image.h"


Image::Image() {
pixels = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
}

Image::~Image() {
delete pixels;
}

void Image::handler()
{
static int j = 0;
s.update();
	for(int i =0 ; i< NUMPIXELS;i++)
	{
	  pixels->setPixelColor(i, s.cur_frame.color[i].red,
							  s.cur_frame.color[i].green,
							  s.cur_frame.color[i].blue,255);
	}
pixels->show();   // Send the updated pixel colors to the hardware.
j++;
if(j>FPS)j=0;
}

