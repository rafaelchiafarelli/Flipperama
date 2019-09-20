/*
 * images.h
 *
 *  Created on: 29 de ago de 2019
 *      Author: rafae
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_


#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "group1.h"
#include "group2.h"
#include "group3.h"
#include "group4.h"
#include "bin.h"
#include "screen.h"

class sequence
{
private:
public:
	screen curr_frame;
	screen last_frame;
	group_1 G1;
	group_2 G2;
	group_3 G3;
	group_4 G4;
	int seq_number; // number of the sequence being displayed
	Adafruit_NeoPixel *pixels; //pixels being displayed in the hardware;


	void setFrameDisplayed(int i);
	void handler(); //must be called every 16milliseconds;
	sequence();
	~sequence();
};


#endif /* SEQUENCE_H_ */
