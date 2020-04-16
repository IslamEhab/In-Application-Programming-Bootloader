/*
 * AFIO_registers.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */

#ifndef AFIO_REGISTERS_H_
#define AFIO_REGISTERS_H_
#include "STD_TYPES.h"

typedef struct{

	u32 EVCR;
	u32 MAPR;
	u32 EXTICR1;
	u32 EXTICR2;
	u32 EXTICR3;
	u32 EXTICR4;
	u32 MAPR2;

}Afio_REG;

#define AFIO ((volatile Afio_REG*) 0x40010000)



#endif /* AFIO_REGISTERS_H_ */
