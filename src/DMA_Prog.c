/*
 * DMA_Prog.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Islam Ehab
 */

#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_REG.h"
#include "USART_Init.h"
#include "flash_usart.h"


#include "DMA_Int.h"
#include "DMA_REG.h"
char RxBuffer[MAX_BUFFER_LENGTH];
char RxDMABuffer[MAX_BUFFER_LENGTH];



extern u8 RxMessageLength;

void DMA_Init(void)
{
	DMA1_I -> CCR1 = 0x0007AD2;


}

/* Function Description
   Function Used to Send Data
   By USART
   Here used to show data on
   Serial Terminal Program
*/
void strTransmit(const u8* str, u8 size)
{
	if (NULL != str)
	{
		//CLEAR INT FLAGS
		DMA1_I -> IFCR = DMA_IFCR_CGIF4;
		DMA1_I->CCR4 &= ~EN;
		while(EN == (EN&DMA1_I->CCR4))
		{
			//ENABLE FLAG WILL RESET

		}

		//set memory address
		DMA1_I -> CMAR4 = (u32)str;

		//set num of data
		DMA1_I -> CNDTR4 = size;
		//		DMA1_I -> CNDTR5 = size;

		DMA1_I -> IFCR = DMA_IFCR_CGIF4;

		//		DMA1_I->CCR4 &= ~EN;

		DMA1_I -> CCR4 |= EN;
	}
	else
	{

	}
}

/* Function Description
 * DMA1 Channel 4 Initialization (Used in USART1 TX)
 * Priority : Very High
 * Data Flow: Memory To Peripheral
 * Data Size: 8 Bit in Memory & Peripheral
 * Increment: Memory Increment
 * Circular Mode     : OFF
 * Peripheral Address: USART1 Data Register
 * */
void FLASH_USART1_TX_DMA_CONFIG(void)
{

	//check if channel 4 (tx) is enabled
	if (EN == (EN & DMA1_I -> CCR4 ))
	{
		//disable channel
		DMA1_I -> CCR4 &= ~EN;

		while (EN == (EN & DMA1_I -> CCR4))
		{
			//wait until channel disabled
		}
	}
	else
	{
		//DO NOTHING DMA1_I CH4 IS ALREADY DISABLED
	}

	DMA1_I -> CCR4 &= ~EN;

	//priority very high
	DMA1_I -> CCR4 |= PL_H;

	//read from MEMORY
	DMA1_I -> CCR4 |= DIR;

	//MEM TO PER
	DMA1_I -> CCR4 &= ~MEM2MEM;

	//Data size 8 bit
	DMA1_I -> CCR4 &= ~MBYTE;
	DMA1_I -> CCR4 &= ~PBYTE;

	//Memory Inc
	DMA1_I -> CCR4 |= MINC;

	//Peripheral address
	DMA1_I -> CPAR4 = (u32)(&(USART1_I->USART_DR));
}

/* Function Description
 * DMA1 Channel 5 Initialization (Used in USART1 RX)
 * Priority : Very High
 * Data Flow: Peripheral To Memory
 * Increment: Memory Increment
 * Circular Mode     : ON
 * Peripheral Address: USART1 Data Register
 * Memory Address	 : RxDMABuffer (Global Array)
 * Interrupt		 : When Transfer Complete
 * */
void FLASH_USART1_RX_DMA_CONFIG(void)
{
	//check if channel 5 (Rx) is enabled
	if (EN == (EN & DMA1_I -> CCR5 ))
	{
		//disable channel
		DMA1_I -> CCR5 &= ~EN;

		while (EN == (EN & DMA1_I -> CCR5))
		{
			//wait until channel disabled
		}
	}
	else
	{
		//DO NOTHING DMA1_I CH5 IS ALREADY DISABLED
	}
	// Clear Global Interrupt Flag
	DMA1_I -> IFCR |= DMA_IFCR_CGIF5;

	//Peripheral address
	DMA1_I -> CPAR5 = (u32)(&(USART1_I->USART_DR));

	//Memory Address
	DMA1_I -> CMAR5 = (u32)(RxDMABuffer);

	//Memory Inc
	DMA1_I -> CCR5 |= MINC;

	//Enable Circular Mode
	DMA1_I -> CCR5 |= CIRC;

	//priority very high
	DMA1_I -> CCR5 |= PL_VH;

	//Data size 8 bit
	DMA1_I -> CCR5 &= ~MBYTE;
	DMA1_I -> CCR5 &= ~PBYTE;

	//Read from PER
	DMA1_I -> CCR5 &= ~DIR;
	DMA1_I -> CCR5 &= ~MEM2MEM;



	//Transfer complete INT
	DMA1_I -> CCR5 |= TCIEE;


	USART1_I ->USART_CR3 |= DMAR;
	DMA1_I -> CNDTR5 = MAX_BUFFER_LENGTH;


	//ENABLE IRQ
	asm("MOV R0,#0");
	asm("MSR PRIMASK,R0");

	DMA1_I -> CCR5 |= EN;

}

/* Function Description
 * DMA1 Channel 4 IRQ Handler
*/
void DMA1_Channel4_IRQHandler(void)
{
	//check if transfer complete flag
	if (TCIF4 == (TCIF4 & DMA1_I -> ISR))
	{
		//CLEAR INT FLAGS
		DMA1_I -> IFCR = DMA_IFCR_CGIF4;
		DMA1_I->CCR4 &= ~EN;
	}
	else
	{

	}

}

/* Function Description
 * DMA1 Channel 5 CallBack */
void DMA1_Channel5_Do(void)
{
	u32 i = 0;
	//Check transfer complete flag
	if(TCIF4 == (TCIF4 & DMA1_I -> ISR))
		//	if(res != 0)
	{
		DMA1_I ->IFCR = 0xF0000;


		//Calculate AMOUNT OF DATA
		RxMessageLength = MAX_BUFFER_LENGTH - DMA1_I -> CNDTR5;

		//copy data to rx buffer


		for(i=0; i < RxMessageLength; i++)
		{
			RxBuffer[i] = RxDMABuffer[i];
			RxDMABuffer[i] = 0;
		}

		//Clear all interrupt flags for RX

		DMA1_I -> CNDTR5 = MAX_BUFFER_LENGTH;

		//ENABLE DMA1_I rx
		DMA1_I -> CCR5 |= EN;
	}
	else
	{

	}
}



void DMA_Transfer (u32 source, u32 destination, u32 count)
{
	DMA1_I -> CNDTR1 = count;

	DMA1_I -> CPAR1  = destination;

	DMA1_I -> CMAR1  = source;

	DMA1_I -> CCR1  |=1; //ENABLE CHANNEL
}
