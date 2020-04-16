/*
 * USART_REG.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Islam Ehab
 */

#ifndef USART_REG_H_
#define USART_REG_H_

#include "STD_TYPES.h"
typedef struct{

	u32 USART_SR;
	u32 USART_DR;
	u32 USART_BRR;
	u32 USART_CR1;
	u32 USART_CR2;
	u32 USART_CR3;
	u32 USART_GTPR;
}USART;

#define USART1_I ((volatile USART*)0x40013800)
#define USART2_I ((volatile USART*) 0x40004400)
#define USART3_I ((volatile USART*) 0x40004800)

#endif /* USART_REG_H_ */
