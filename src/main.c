/*
 * main.c
 *
 *  Created on: Sep 23, 2019
 *      Author: Islam Ehab
 */

#include "STD_TYPES.h"
#include "RCC_Int.h"
#include "RCC_registers.h"

#include "DIO_Int.h"
#include "flash_usart.h"
#include "FLASH_Init.h"
#include "NVIC_int1.h"

void main (void)
{

	/*RCC Initialization
	  PLL Configuration
	  To Get MC CLK To 72 MHz
	*/
	RCC_voidInit();

	/* Enable GPIOA Clock */
	RCC_voidEnableClock(RCC_CLK_IOPA);

	/* Enable Alternative Function Clock */
	RCC_voidEnableClock(RCC_CLK_AFIO);

	/* Enable USART1 Clock
	   USART1 Is Responsible to
	   Manipulation Through Serial Program
	   (Tera Term, Putty, etc)
	   And Burning Code into Flash using USART1
	*/
	RCC_voidEnableClock(RCC_CLK_USART1);

	/* Enable DMA Clock */
	RCC_AHBENR |= RCC_CLK_DMA1;

	/* Enable SRAM Clock */
	RCC_AHBENR |= RCC_CLK_SRAM;

	/* DIO Initialization
	   Registers Reset Value, etc
	*/
	DIO_Init();
	/* Activate PIN 9 in PORTA as USART1_TX */
	DIO_SetPinConfig(PORTA,PIN9,OUT_50_AF_PP);

	/* Activate PIN10 in PortA as USART1_RX */
	DIO_SetPinConfig(PORTA,PIN10,IN_PULL);

	/* Enable DMA1 Channel 4 Interrupt
	   Used in USART1_TX
	 */
	NVIC_voidEnableInt(NVIC_DMA1_CHANNEL4_IDX);

	/* Enable DMA1 Channel 5 Interrupt
	   Used in USART1_RX
	*/
	NVIC_voidEnableInt(NVIC_DMA1_CHANNEL5_IDX);

	/* Enable USART1 Interrupt */
	NVIC_voidEnableInt(NVIC_USART1_IDX);

	/* Set DMA1 Channel 4 Interrupt Priority */
	NVIC_voidSetIntPriority(NVIC_DMA1_CHANNEL4_IDX,0x10);

	/* Set DMA1 Channel 5 Interrupt Priority */
	NVIC_voidSetIntPriority(NVIC_DMA1_CHANNEL5_IDX,0x10);

	/* Set USART1 Interrupt Priority */
	NVIC_voidSetIntPriority(NVIC_USART1_IDX,0x10);

	/* DMA1 Channel 4 Initialization*/
	FLASH_USART1_TX_DMA_CONFIG();

	/* DMA1 Channel 5 Initialization*/
	FLASH_USART1_RX_DMA_CONFIG();

	/* USART1 Initialization */
	FLASH_USART1_ENABLE();

	/* Flash Initialization */
	Flash_Init();



	while(1){

		Flash_Main();


	}


}
