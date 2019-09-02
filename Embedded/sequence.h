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


typedef enum {
	TRAIN_BACK,
	TRAIN_FWRD,
	FLASH,
	SMOTH_BLINK,
	NONE

}fx;


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

class effects
{
public:
	void update(screen *c_frame, screen* l_frame);
	fx type;
	int speed; //0 is stopped and the bigger the slower
};

class sequence
{
private:
	effects Efx;

public:
	screen cur_frame; //must be defined in memory, because, the effects will use this as variables.
	screen last_frame;
	void get_frame(int i);
	void update() {Efx.update(&cur_frame,&last_frame);};
	sequence();
};


#endif /* SEQUENCE_H_ */
