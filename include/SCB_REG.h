/*
 * SCB_REG.h
 *
 *  Created on: Sep 23, 2019
 *      Author: Islam Ehab
 */

#ifndef SCB_REG_H_
#define SCB_REG_H_
typedef unsigned int u32;

typedef struct
{
	u32 ACTLR;
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;

};

#endif /* SCB_REG_H_ */
