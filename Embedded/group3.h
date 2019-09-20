/*
 * group1.h
 *
 *  Created on: 18 de set de 2019
 *      Author: rafae
 */

#ifndef GROUP3_H_
#define GROUP3_H_
#include "bin.h"
#include "screen.h"

class group_3
{
public:
	color pixel[G_3_AMOUNT];
	uint8_t speed;
	fx Efx;
	uint8_t control;
	uint8_t time;
	unsigned int position[G_3_AMOUNT];
	void SetCurrentGroup(int j, screen *c_frame=0, screen *l_frame=0);
	void handler(screen *l_frame, screen *c_frame);
	group_3();
};
#endif /* GROUP1_H_ */
