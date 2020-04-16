/*
 * DMA_REG.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Islam Ehab
 */

#ifndef DMA_REG_H_
#define DMA_REG_H_


#include "STD_TYPES.h"

typedef struct {
	u32 ISR;
	u32 IFCR;

	u32 CCR1;
	u32 CNDTR1;
	u32 CPAR1;
	u32 CMAR1;
	const u32 reserved1; //because there are reserved place in data sheet
	u32 CCR2;
	u32 CNDTR2;
	u32 CPAR2;
	u32 CMAR2;
	const u32 reserved2; //because there are reserved place in data sheet
	u32 CCR3;
	u32 CNDTR3;
	u32 CPAR3;
	u32 CMAR3;
	const u32 reserved3; //because there are reserved place in data sheet
	u32 CCR4;
	u32 CNDTR4;
	u32 CPAR4;
	u32 CMAR4;
	const u32 reserved4; //because there are reserved place in data sheet
	u32 CCR5;
	u32 CNDTR5;
	u32 CPAR5;
	u32 CMAR5;
	const u32 reserved5; //because there are reserved place in data sheet
	u32 CCR6;
	u32 CNDTR6;
	u32 CPAR6;
	u32 CMAR6;
	const u32 reserved6; //because there are reserved place in data sheet
	u32 CCR7;
	u32 CNDTR7;
	u32 CPAR7;
	u32 CMAR7;
	const u32 reserved7; //because there are reserved place in data sheet


}DMA_TYPES;
#define  DMA1_I ((volatile DMA_TYPES*) 0x40020000)
#endif /* DMA_REG_H_ */
