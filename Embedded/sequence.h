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
#include "bin.h"
class pixel
{
public:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

class screen
{
public:
	pixel color[NUMPIXELS];
};

class sequence
{
public:
	screen frame[FPS];
	sequence();
};


#endif /* SEQUENCE_H_ */
