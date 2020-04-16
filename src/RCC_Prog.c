/*
simple driver for RCC
Using PLL and HSE 
HSE CLOCK = 8MHZ
by using PLL CLK will be 8MHZ*9 = 72MHZ
*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_registers.h"

//#define HSI  0
//#define HSE  1
//#define PLL  2


void RCC_voidInit(void)
{
	SET_BIT(RCC_CR,16); //to enable HSE
	
	while (!((RCC_CR) & 0x00020000));  // wait untill HSE Stable
		
	SET_BIT (RCC_CFGR,16); //HSE I/P TO PLL
	
	CLR_BIT (RCC_CFGR,17); // ALL HSE I/P TO PLL
	
	RCC_CFGR |= 0x001C0000; // MUL BY 9
	
	
}

void RCC_voidDeInit(u8 PeripheralIdx)
{


}


void RCC_voidEnableClock(u8 PeripheralIdx)
{
	if ((PeripheralIdx > 0) && (PeripheralIdx < 32))
	{
		SET_BIT(RCC_AHBENR,PeripheralIdx);
	}
	
	else if ((PeripheralIdx >= 32) && (PeripheralIdx < 64))
	{
		PeripheralIdx -= 32;
		SET_BIT(RCC_APB2ENR,PeripheralIdx);
	}
	
	else if ((PeripheralIdx >= 64) && (PeripheralIdx < 96))
	{
		PeripheralIdx -= 64;
		SET_BIT(RCC_APB1ENR,PeripheralIdx);
	}
	
	else
	{
		//do nothing
	}
	
}

void RCC_VoidDisableClock(u8 PeripheralIdx)
{
	
	if ((PeripheralIdx > 0) && (PeripheralIdx < 32))
	{
		CLR_BIT(RCC_AHBENR,PeripheralIdx);
	}
	
	else if ((PeripheralIdx >= 32) && (PeripheralIdx < 64))
	{
		PeripheralIdx -= 32;
		CLR_BIT(RCC_APB2ENR,PeripheralIdx);
	}
	
	else if ((PeripheralIdx >= 64) && (PeripheralIdx < 96))
	{
		PeripheralIdx -= 64;
		CLR_BIT(RCC_APB1ENR,PeripheralIdx);
	}
	
	else
	{
		//do nothing
	}
	
}
