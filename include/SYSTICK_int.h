/*
 * SYSTICK_int.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */

#ifndef SYSTICK_INT_H_
#define SYSTICK_INT_H_

#include "STD_TYPES.h"

#define SYSTICK_CSR *((volatile u32*) 0xE000E010)

#define SYSTICK_LOAD *((volatile u32*) 0xE000E014)

#define SYSTICK_VAL *((volatile u32*) 0xE000E018)

void _delay_ms(u32 u32DelayCPY);


ERROR_status SYSTICK_voidInit(u32 u32LoadCPY);



#endif /* SYSTICK_INT_H_ */
