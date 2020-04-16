/*


 * AFIO_Prog.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */




#include "STD_TYPES.h"
#include "AFIO_int.h"
#include "AFIO_registers.h"

static void AFIO_voidInitEXTI(void)
{
	AFIO -> EXTICR1 = 0x0;
	AFIO -> EXTICR2 = 0x0;
	AFIO -> EXTICR3 = 0x0;
	AFIO -> EXTICR4 = 0x0;
}

//simple


static void AFIO_voidInitMAPR(void)
{
	AFIO -> MAPR |=  USART1_REMAP;
}

void AFIO_voidInit(void)
{
	AFIO -> EVCR = 0x0;
	AFIO_voidInitMAPR();
	AFIO_voidInitEXTI();


}

void AFIO_SetPin(u8 pin)
{
	AFIO -> EVCR = pin;

	AFIO -> EVCR |= EVOE;

}

//simple one
void AFIO_EXTI(u8 pin)
{
	if(pin == PA0)
	{
		AFIO -> EXTICR1 = pin;

	}
}
