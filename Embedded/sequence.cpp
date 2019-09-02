/*
 * sequence.cpp
 *
 *  Created on: 30 de ago de 2019
 *      Author: rafae
 */
#include "sequence.h"



sequence::sequence()
{
	get_frame(0);
}

void sequence::get_frame(int j)
{
	for(int i =0;i<NUMPIXELS;i++)
	{
		cur_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
		cur_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
		cur_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));

		last_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
		last_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
		last_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));
	}
}

void effects::update(screen *c_frame, screen* l_frame)
{
	pixel tmp;
	memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
	switch(type)
	{
	case TRAIN_BACK:
		tmp = c_frame->color[0];
		memmove(c_frame,c_frame+1,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
		c_frame->color[NUMPIXELS] = tmp;
		break;
	case TRAIN_FWRD:
		tmp = c_frame->color[NUMPIXELS];
		memmove(c_frame+1,l_frame,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
		c_frame->color[0] = tmp;
		break;
	case FLASH:
		break;
	case SMOTH_BLINK:
		break;
	default:
		break;
	}
}

