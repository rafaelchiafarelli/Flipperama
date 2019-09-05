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
	STROBE,
	STROBE_TRAIN,
	RAMDOM,

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
private:
	uint8_t control[GROUPS+1];
	uint8_t time[GROUPS+1];
	fx type[GROUPS+1];
	uint8_t speed[GROUPS+1]; //0 is stopped and the bigger the slower
public:
	void setFrameDisplayed(int i);
	void update(screen *c_frame, screen* l_frame);
	void setSpeed(uint8_t s,uint8_t g){speed[g] = s;}
	uint8_t getSpeed(uint8_t g){return speed[g];}
	effects(int i){setFrameDisplayed(i);}
	effects(){setFrameDisplayed(0);}
	~effects(){}
};

class sequence
{
private:
	effects Efx; //must be equivalent to number_of_seeds * number of groups
	int seq_number; // number of the sequence being displayed
	Adafruit_NeoPixel *pixels; //pixels being displayed in the hardware;
	screen cur_frame; //must be defined in memory, because, the effects will use this as variables.
	screen last_frame;

public:

	void setFrameDisplayed(int i);

	void setSpeed(uint8_t i, uint8_t g){Efx.setSpeed(i,g);}
	void incSpeed(uint8_t g){Efx.setSpeed(((Efx.getSpeed(g)==UINT8_MAX) ? UINT8_MAX : Efx.getSpeed(g)+1),g);}
	void decSpeed(uint8_t g){Efx.setSpeed(((Efx.getSpeed(g)==0) ? 0 : Efx.getSpeed(g)-1),g);}

	void handler(); //must be called every 16milliseconds;
	sequence();
	~sequence();
};


#endif /* SEQUENCE_H_ */
