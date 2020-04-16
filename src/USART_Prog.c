/*
 * USART_Prog.c
 *
 *  Created on: Aug 28, 2019
 *      Author: Islam Ehab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_Int.h"
#include "DMA_REG.h"
#include "USART_REG.h"
#include "USART_Init.h"
//#define MAX_BUFFER    ((uint32_t) 128u)

  u8 RxBuffer[MAX_BUFFER+1];
static	u8 result = 0;
  u8 RxMessageLength1 =0;
 u32 arr[MAX_BUFFER];

 void FLASH_USART1_ENABLE(void)
 {


 	//Baud rate 115200
 	USART1_I -> USART_BRR = 72000000/115200;


 	//Enable Tx
 	USART1_I ->USART_CR1 |= TE;

 	//Enable Rx
 	USART1_I ->USART_CR1 |= RE;

 	//Enable DMA1_I MODE FOR TX,RX
 	USART1_I ->USART_CR3 |= DMAR;
 	USART1_I ->USART_CR3 |= DMAT;

 	USART1_I ->USART_CR1 |= IDLEIE;

 	//Enable USART1_I
 	USART1_I ->USART_CR1 |= UE;


 	//ENABLE DMA1_I CH5 (RX)
 	DMA1_I -> CCR5 |= EN;
 }

 void USART1_IRQHandler(void)
 {
 	//CHECK if idle line detected
 	if ((USART1_I -> USART_SR & IDLE) == IDLE)
 	{
 		//read data reg to clear idle line flag
 		(void)USART1_I -> USART_SR;
 		(void)USART1_I -> USART_DR;

 		//disable DMA1_I RX
 		DMA1_I -> CCR5 &= ~EN;
 	}
 	else
 	{

 	}
 	//	DMA1_I -> IFCR = 0x80000;
 	DMA1_Channel5_Do();
 }




void USART_Init1(u8 usart, u8 value)
{
	if ((usart <= UART3) && (value <= ENABLE))
	{
		switch(usart)
		{
		case UART1:
			if (value == ENABLE)
			{


				SET_BIT(USART1_I -> USART_CR1 ,UE);
				SET_BIT(USART1_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART1_I -> USART_BRR = 0X271;

				SET_BIT(USART1_I -> USART_CR1 ,TE);
				SET_BIT(USART1_I -> USART_CR1 ,RE);
				SET_BIT(USART1_I -> USART_CR1 ,PCE); // PARITY EVEN

				//	SET_BIT(USART1_I -> USART_CR1 ,RXEIE); //RX INT ENABLE




			}
			else if (value == DISABLE)
			{

				CLR_BIT(USART1_I -> USART_CR1 ,UE);
				CLR_BIT(USART1_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART1_I -> USART_BRR = 0x753;

				CLR_BIT(USART1_I -> USART_CR1 ,TE);
				CLR_BIT(USART1_I -> USART_CR1 ,RE);
			}
			break;
		case UART2:
			if (value == ENABLE)
			{

				SET_BIT(USART2_I -> USART_CR1 ,UE);
				SET_BIT(USART2_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART2_I -> USART_BRR = 0x753;

				SET_BIT(USART2_I -> USART_CR1 ,TE);
				SET_BIT(USART2_I -> USART_CR1 ,RE);

			}
			else if (value == DISABLE)
			{

				CLR_BIT(USART2_I -> USART_CR1 ,UE);
				CLR_BIT(USART2_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART2_I -> USART_BRR = 0x753;

				CLR_BIT(USART2_I -> USART_CR1 ,TE);
				CLR_BIT(USART2_I -> USART_CR1 ,RE);
			}
			break;
		case UART3:
			if (value == ENABLE)
			{


				SET_BIT(USART3_I -> USART_CR1 ,UE);
				SET_BIT(USART3_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART1_I -> USART_BRR = 0x753;

				SET_BIT(USART3_I -> USART_CR1 ,TE);
				SET_BIT(USART3_I -> USART_CR1 ,RE);

			}
			else if (value == DISABLE)
			{

				CLR_BIT(USART3_I -> USART_CR1 ,UE);
				CLR_BIT(USART3_I -> USART_CR1 ,M); // 9 BIT TRANSFER 8 DATA 1 STOP
				//baud rate 9600
				USART3_I -> USART_BRR = 0x753;

				CLR_BIT(USART3_I -> USART_CR1 ,TE);
				CLR_BIT(USART3_I -> USART_CR1 ,RE);
			}
			break;
		}

	}
	else
	{

	}
}

void USART_Sendchar(u8 usart, u8 data)
{
	if (usart <= UART3)
	{
		switch(usart)
		{
		case UART1:
			while(!(USART1_I -> USART_SR & 0x80));
			USART1_I -> USART_DR = (data);
			break;

		case UART2:
			while(!(USART2_I -> USART_SR & 0x80));
			USART2_I -> USART_DR = (data &0x1FF);
			break;

		case UART3:
			while(!(USART3_I -> USART_SR & 0x80));
			USART3_I -> USART_DR = (data &0x1FF);
			break;
		}
	}
	else
	{

	}

}

void USART_SendString(u8 usart,u8* str, u8 size)
{
	u8 i =0;

	if (0 != str)
	{
		for(i=0; i<size; i++)
		{
		USART_Sendchar(usart,str[i]);
		}
	}
}


u8   USART_Getchar(u8 usart)
{
	if (usart <= UART3)
	{
		switch(usart)
		{
		case UART1:
			CLR_BIT(USART1_I -> USART_DR,0xFF);
			while(!(USART1_I -> USART_SR & 0x20));
			result = (USART1_I -> USART_DR);
			CLR_BIT(USART1_I -> USART_SR,0x20);//to clEAr RXNE
			return result;
			break;
		case UART2:
			while(!(USART2_I -> USART_SR & 0x20));
			result = (USART2_I -> USART_DR & 0x1FF);

			CLR_BIT(USART2_I -> USART_SR,0x20);//to clEAr RXNE
			return result;
			break;
		case UART3:
			while(!(USART3_I -> USART_SR & 0x20));
			result = (USART3_I -> USART_DR & 0x1FF);

			CLR_BIT(USART3_I -> USART_SR,0x20);//to clEAr RXNE
			return result;
			break;
		}
	}
	else
	{

	}
	return result;
}



void USART_GetString (u8 usart)
{
	u8 arr[MAX_BUFFER];
	u8 i =0;
	u8 RxIndex =0;

	if (result == '\0')
	{
		if (RxIndex != 0)
		{
			for (i=0; i < RxIndex; i++)
			{
				RxBuffer[i] = arr[i];
			}
			RxBuffer[RxIndex] = 0;

			RxMessageLength1 = RxIndex + 1;

			RxIndex = 0;
		}
		else
		{
		}
	}
	else
	{
		if (MAX_BUFFER == RxIndex)
		{
			RxIndex =0;
		}
		else
		{

		}
		arr[RxIndex] = result;

		RxIndex++;

	}


}

void String_Rx (u8 usart,u8 size)
{
	u8 i;
	for(i=0; i< size; i++)
	{
		USART1_I -> USART_DR = 0x00;
	//CLR_BIT(USART1_I -> USART_DR,0xFFF);
	while(!(USART1_I -> USART_SR & 0x20));
	arr[i] = (USART1_I -> USART_DR & 0x000000FF);
	CLR_BIT(USART1_I -> USART_SR,0x20);//to clEAr RXNE

	}


}


