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
	pixels = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
	pixels->begin();
}

void sequence::setFrameDisplayed(int j)
{
	seq_number = j;
	for(int i =0;i<NUMPIXELS;i++)
	{
		cur_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
		cur_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
		cur_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));

		last_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
		last_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
		last_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));
	}
	Efx.setFrameDisplayed(j);
}

void sequence::handler()
{
	Efx.update(&cur_frame,&last_frame);
		for(int i =0 ; i< NUMPIXELS;i++)
		{
		  pixels->setPixelColor(i, cur_frame.color[i].red,
				  cur_frame.color[i].green,
				  cur_frame.color[i].blue,255);
		}
	pixels->show();   // Send the updated pixel colors to the hardware.
}

void effects::setFrameDisplayed(int i)
{
	for (int j =0; j<GROUPS;j++){
		time[j] = 0;
		control[j] = 0;
		speed[j] = (uint8_t)pgm_read_byte(&(effects_and_groups[i][j][0]));
		type[j] = (uint8_t)pgm_read_byte(&(effects_and_groups[i][j][1]));
	}
}
void effects::update(screen *c_frame, screen* l_frame)
{
	pixel tmp;
	for(int i =0 ;i<GROUPS;i++)
	{
		if(speed[i] == 0) break;
		time[i]++;
		if (time[i] >= (UINT8_T_MAX - speed[i]))
		{
		time[i]=0;
		switch(type[i])
			{
			case TRAIN_BACK:
				memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
				tmp = c_frame->color[0];
				memmove(c_frame,c_frame+1,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
				c_frame->color[NUMPIXELS] = tmp;
				break;

			case TRAIN_FWRD:
				memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
				tmp = c_frame->color[NUMPIXELS];
				memmove(c_frame+1,l_frame,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
				c_frame->color[0] = tmp;
				break;

			case FLASH:
				memset(c_frame,0,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
				break;

			case STROBE:
				control[i] = (control[i] == 0)? 1:0;
				memset(c_frame,UINT8_MAX*control[i],(size_t)((NUMPIXELS-1)*sizeof(pixel)));
				break;

			case STROBE_TRAIN:
				if (control[i] == 0)
				{
					memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
					tmp = c_frame->color[NUMPIXELS];
					memmove(c_frame+1,l_frame,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
					c_frame->color[0] = tmp;
					control[i] = 1;
				}
				else
				{
					memset(c_frame,0,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
					control[i] = 0;
				}
				break;

			case SMOTH_BLINK:
				for(int k = 0; k<NUMPIXELS;k++)
					{
						if(control[i] == 0 )
						{
							memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
						}else if (control[i] == 1)
						{
						  (c_frame[i].color[k].red < l_frame[i].color[NUMPIXELS].red)? c_frame[i].color[k].red++ : c_frame[i].color[k].red;
						  (c_frame[i].color[k].green < l_frame[i].color[NUMPIXELS].green)? c_frame[i].color[k].green++ : c_frame[i].color[k].green;
						  (c_frame[i].color[k].blue < l_frame[i].color[NUMPIXELS].blue)? c_frame[i].color[k].blue++ : c_frame[i].color[k].blue;
						  if((c_frame[i].color[k].red == l_frame[i].color[NUMPIXELS].red) &&
								  (c_frame[i].color[k].green == l_frame[i].color[NUMPIXELS].green) &&
									  (c_frame[i].color[k].blue == l_frame[i].color[NUMPIXELS].blue) )
						  control[i] = 2;
						}
						else if (control[i] == 2)
						{
							(c_frame[i].color[k].red > 0)? c_frame[i].color[k].red-- : c_frame[i].color[k].red;
							(c_frame[i].color[k].green > 0)? c_frame[i].color[k].green-- : c_frame[i].color[k].green;
							(c_frame[i].color[k].blue > 0)? c_frame[i].color[k].blue-- : c_frame[i].color[k].blue;
							  if((c_frame[i].color[k].red == 0) &&
									  (c_frame[i].color[k].green == 0) &&
										  (c_frame[i].color[k].blue == 0) )
							  control[i] = 1;
						}
					}
				break;
			case RAMDOM:
				for(int k =0 ;k<NUMPIXELS;k++)
				{
					c_frame[i].color[k].red = rand();
					c_frame[i].color[k].green = rand();
					c_frame[i].color[k].blue = rand();
				}
				break;
			case NONE:
			default:
				break;
			}
		}
	}
}



