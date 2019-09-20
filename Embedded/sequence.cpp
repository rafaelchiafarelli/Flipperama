/*
 * sequence.cpp
 *
 *  Created on: 30 de ago de 2019
 *      Author: rafae
 */
#include <Adafruit_NeoPixel.h>
#include "sequence.h"


sequence::~sequence()
{
	delete pixels;
}
sequence::sequence()
{
	setFrameDisplayed(0);
	pixels = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB);
	pixels->begin();
}

void sequence::setFrameDisplayed(int j)
{
	seq_number = j;

	G1.SetCurrentGroup(j,&curr_frame,&last_frame);
	G2.SetCurrentGroup(j,&curr_frame,&last_frame);
	G3.SetCurrentGroup(j,&curr_frame,&last_frame);
	G4.SetCurrentGroup(j,&curr_frame,&last_frame);
}

void sequence::handler()
{
	G1.handler(&last_frame,&curr_frame);
	G2.handler(&last_frame,&curr_frame);
	G3.handler(&last_frame,&curr_frame);
	G4.handler(&last_frame,&curr_frame);
		for(int i =0 ; i< NUMPIXELS;i++)
		{
		  pixels->setPixelColor(i, curr_frame.pixel[i].red,
				  curr_frame.pixel[i].green,
				  curr_frame.pixel[i].blue);
		}
	pixels->show();   // Send the updated pixel colors to the hardware.
}






