/*
 * group1.h
 *
 *  Created on: 18 de set de 2019
 *      Author: rafae
 */

#ifndef GROUP4_H_
#define GROUP4_H_
#include "bin.h"
#include "screen.h"

class group_4
{
public:
	color pixel[G_4_AMOUNT];
	uint8_t speed;
	fx Efx;
	uint8_t control;
	uint8_t time;
	unsigned int position[G_4_AMOUNT];
	void SetCurrentGroup(int j, screen *c_frame=0, screen *l_frame=0);
	void handler(screen *l_frame, screen *c_frame);
	group_4();
};
#endif /* GROUP1_H_ */
