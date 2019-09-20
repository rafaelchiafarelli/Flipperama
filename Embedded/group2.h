/*
 * group2.h
 *
 *  Created on: 28 de set de 2029
 *      Author: rafae
 */

#ifndef GROUP2_H_
#define GROUP2_H_
#include "bin.h"
#include "screen.h"

class group_2
{
public:
	color pixel[G_2_AMOUNT];
	uint8_t speed;
	fx Efx;
	uint8_t control;
	uint8_t time;
	uint8_t position[G_2_AMOUNT];
	void SetCurrentGroup(int j, screen *c_frame=0, screen *l_frame=0);
	void handler(screen *l_frame, screen *c_frame);
	group_2();
};
#endif /* GROUP2_H_ */
