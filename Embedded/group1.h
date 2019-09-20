/*
 * group1.h
 *
 *  Created on: 18 de set de 2019
 *      Author: rafae
 */

#ifndef GROUP1_H_
#define GROUP1_H_
#include "bin.h"
#include "screen.h"

class group_1
{
public:
	color pixel[G_1_AMOUNT];
	uint8_t speed;
	fx Efx;
	uint8_t control;
	uint8_t time;
	uint8_t position[G_1_AMOUNT];
	void SetCurrentGroup(int j, screen *c_frame=0, screen *l_frame=0);
	void handler(screen *l_frame, screen *c_frame);
	group_1();
};
#endif /* GROUP1_H_ */
