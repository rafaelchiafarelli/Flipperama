/*
 * Image.h
 *
 *  Created on: 29 de ago de 2019
 *      Author: rafae
 */

#ifndef IMAGE_H_
#define IMAGE_H_
#include <Adafruit_NeoPixel.h>
#include "sequence.h"

class Image {
private:
	Adafruit_NeoPixel *pixels;
	sequence s;
public:
	void handler();
	Image();
	virtual ~Image();
};

#endif /* IMAGE_H_ */
