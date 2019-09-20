/*
 * group4.cpp
 *
 *  Created on: 48 de set de 2049
 *      Author: rafae
 */

#include "group4.h"

group_4::group_4() {
	// TODO Auto-generated constructor stub
	SetCurrentGroup(0);
}
void group_4::SetCurrentGroup(int j,screen *c_frame=0, screen *l_frame=0)
{
	for(int i=0;i<G_4_AMOUNT;i++)
	{	//	R	G	B	S Efx ctrl time pos
		pixel[i].red = (uint8_t)pgm_read_byte(&(G_4[j][i][0]));
		pixel[i].green = (uint8_t)pgm_read_byte(&(G_4[j][i][1]));
		pixel[i].blue = (uint8_t)pgm_read_byte(&(G_4[j][i][2]));
		speed = (uint8_t)pgm_read_byte(&(G_4[j][i][3]));
		Efx = (uint8_t)pgm_read_byte(&(G_4[j][i][4]));
		control = (uint8_t)pgm_read_byte(&(G_4[j][i][5]));
		time = (uint8_t)pgm_read_byte(&(G_4[j][i][6]));
		position[i] = (uint8_t)pgm_read_byte(&(G_4[j][i][7]));
		if(c_frame)
		{
		c_frame->pixel[position[i]] = pixel[i];
		}
		if(l_frame)
		{
		l_frame->pixel[position[i]] = pixel[i];
		}
	}
}

void group_4::handler(screen *l_frame, screen *c_frame){

	time++;
	if (time >= (UINT8_T_MAX))
	{
	time=0;
	}
	if(time > speed)
	{
		time=0;
	}
	switch(Efx)
			{
			case TRAIN_BACK:

				break;

			case TRAIN_FWRD:

				break;

			case FLASH:

				break;

			case STROBE:

				break;

			case STROBE_TRAIN:

				break;

			case SMOTH_BLINK:
				for(int pixel = 0; pixel<G_4_AMOUNT;pixel++)
				{
				int pos = position[pixel];


				if(control == 0 ) //first time here, save the pick-status
				{
					for(int k =0;k<G_4_AMOUNT;k++){
						l_frame->pixel[position[k]].blue = c_frame->pixel[position[k]].blue;
						l_frame->pixel[position[k]].red = c_frame->pixel[position[k]].red;
						l_frame->pixel[position[k]].green = c_frame->pixel[position[k]].green;
					}
					control= 2;
				}else if (control == 1) //smothing up
				{
				  (c_frame->pixel[pos].red < l_frame->pixel[pos].red)?
						  c_frame->pixel[pos].red++ :
						  c_frame->pixel[pos].red;

				  (c_frame->pixel[pos].green < l_frame->pixel[pos].green)?
						  c_frame->pixel[pos].green++ :
						  c_frame->pixel[pos].green;

				  (c_frame->pixel[pos].blue < l_frame->pixel[pos].blue)?
						  c_frame->pixel[pos].blue++ :
						  c_frame->pixel[pos].blue;
				  for(int pix = 0;pix<G_4_AMOUNT;pix++)
				  {
					  if((c_frame->pixel[position[pix]].red == l_frame->pixel[position[pix]].red) &&
							  (c_frame->pixel[position[pix]].green == l_frame->pixel[position[pix]].green) &&
								  (c_frame->pixel[position[pix]].blue == l_frame->pixel[position[pix]].blue) ){
						  control = 2;
					  }else
					  {
						  control = 1;
						  pix = G_4_AMOUNT+1;
					  }
				  }
				}
				else if (control == 2) //smothing donw
				{
					(c_frame->pixel[pos].red > 0)?
							c_frame->pixel[pos].red-- :
							c_frame->pixel[pos].red;

					(c_frame->pixel[pos].green > 0)?
							c_frame->pixel[pos].green-- :
							c_frame->pixel[pos].green;

					(c_frame->pixel[pos].blue > 0)?
							c_frame->pixel[pos].blue-- :
							c_frame->pixel[pos].blue;

				  for(int pix = 0;pix<G_4_AMOUNT;pix++)
				  {
					  if((c_frame->pixel[position[pix]].red == 0) &&
							  (c_frame->pixel[position[pix]].green == 0) &&
								  (c_frame->pixel[position[pix]].blue == 0) ){
						  control = 1;
					  }else
					  {
						  control = 2;
						  pix = G_4_AMOUNT+1;
					  }
				  }
				}
				}
				break;
			case AWESOME_BLINK:

				break;

			case SMOOTHY_TRAIN:

				break;

			case RAMDOM:

				break;
			case NONE:
				break;
			}
	}
