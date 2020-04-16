/*
 * SYSTICK_Prog.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */

#include "STD_TYPES.h"

#include "SYSTICK_int.h"

volatile u32 DELAY_x;


void __attribute__ ((section(".after_vectors"),weak))
SysTick_Handler (void)
{
	if(DELAY_x != 0)
	{
		DELAY_x--;
	}
}




void _delay_ms(u32 u32DelayCPY)
{
	DELAY_x = u32DelayCPY;
	while(DELAY_x != 0);
}


ERROR_status SYSTICK_voidInit(u32 u32LoadCPY)
{
	if(u32LoadCPY <= 0 || u32LoadCPY > 0x00FFFFFF)
	{
		return NOK;
	}
	SYSTICK_LOAD = u32LoadCPY;
	SYSTICK_VAL = 0x00;
	SYSTICK_CSR = 0x00000007;
	return OK;
}


