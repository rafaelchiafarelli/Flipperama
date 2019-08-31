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
static int j =0;

for(int i =0 ; i< NUMPIXELS;i++){
	  pixels->setPixelColor(i, s.frame[j].color[i].red,
			  s.frame[j].color[i].green,
			  s.frame[j].color[i].blue,255);
	}
pixels->show();   // Send the updated pixel colors to the hardware.
j++;
if(j>FPS)j=0;
}
