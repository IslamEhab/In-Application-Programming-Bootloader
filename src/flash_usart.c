/*
 * flash_usart.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Islam Ehab
 */

#include <stddef.h>

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FLASH_REG.h"
#include "flash_usart.h"
#include "FLASH_Init.h"
#include "RCC_registers.h"
#include "DIO_registers.h"
#include "USART_REG.h"
#include "DMA_REG.h"
#include "DMA_Int.h"
#include "RCC_Int.h"
#include "USART_Init.h"
#include "DIO_Int.h"
#include "SYSTICK_Int.h"

/* Global Arrays Used in Serial Terminal */
static u8 hello[] = "Welcome to Flash Controller !";
static u8 select_cmd[] = "Select command from the following: ";
static u8 lock[] = "1: Flash Lock";
static u8 unlock[] = "2: Flash Unlock";
static u8 write_data[] = "3: Write Data";
static u8 read_data[] = "4: Read Data";
static u8 erase[] = "5: Sector Erase";

static u8 jump[] = "6: Direct Jump";


static u8 error_WRPERR[] = "Write protection error";

static u8 ACK[] = "ACK";
static u8 NACK[] = "NACK";
static u8 line[] = "**********************************************";

static u8 error_PGSERR[] = "Programming sequence error";



typedef enum
{
	FLASH_IDLE,
	FLASH_WAIT_FOR_CMD

}FLash_State;

extern char RxBuffer[MAX_BUFFER_LENGTH];
extern char RxDMABuffer[MAX_BUFFER_LENGTH];

static FLash_State currentState = FLASH_IDLE;

extern u8 RxMessageLength = 0;
static void check_errors(void);
static void process_command (void);


/*Function Description
 * Static Function To Check Errors
 * And Print out this Error on Serial Terminal
 * */
static void check_errors(void)
{
	if(PGERR == (FLASH1 -> SR & PGERR))
	{
		// Programming sequence error
		strTransmit(NACK, sizeof(NACK));
		strTransmit(error_PGSERR, sizeof(error_PGSERR));
		strTransmit(line, sizeof(line));

		//clear
		FLASH1 ->SR |= PGERR;
	}
	else if (WRPRTERR == (FLASH1 -> SR & WRPRTERR))
	{
		// Write protection error
		strTransmit(NACK, sizeof(NACK));
		strTransmit(error_WRPERR, sizeof(error_WRPERR));
		strTransmit(line, sizeof(line));

		FLASH1 -> SR |= WRPRTERR;
	}
	else
	{
		/* No Errors */
		strTransmit(ACK, sizeof(ACK));
	}

}

/* Function Description
 * Static Function Used to Take User Input
 * and then Proceed To the appropriate Function
 * To interact with this input */
static void process_command (void)
{
	volatile u32 address = 0;
	uint16_t data = 0;
	u32 val = 0;
	u8 num = 0;
	u8 i =0;
	switch(RxBuffer[0])
	{
	case 1: //FLASH1 unlock
		Flash_Lock();
		break;

	case 2: //FLASH1 unlock
		Flash_Unlock();
		break;

	case 3: //write Data

		//WAIT FOR FLAG BSY
		while(0 != (FLASH1 -> SR & BSY))
		{

		}

		FLASH1 ->KEYR |= 0x45670123;
		FLASH1 ->KEYR |= KEY2;
		//ENABLE FLASH1 PROGRAMMING
		FLASH1 ->CR &= ~0x02;

		FLASH1 -> CR |= PG;

		//write data into FLASH1
		address = * (uint32_t *) &RxBuffer[1];


		for(i=0; i < 8; ++i)
		{
			FLASH1 -> CR |= PG;

			data = * (u32 *) &RxBuffer[5 + (i * 2)];
			*(volatile u16*)(address) = data;
			FLASH1 -> CR &= ~PG;

			//
			address += 2;

			//wait for flag
			while(FLASH ->SR &0x01);
		}

		FLASH1 -> CR &= ~PG;
		break;

	case 4: //read data
		FLASH1 ->KEYR |= 0x45670123;
		FLASH1 ->KEYR |= KEY2;
		address = * (u32 *) &RxBuffer[1];

		val = * (u32 *) address;

		strTransmit((u8 *)&val, sizeof(val));
		break;

	case 5: //PAGE erase
		address = * (u32 *) &RxBuffer[1];
		num = *(u8*)&RxBuffer[5];
		Erase_Sector(address, num);


		break;

	case 6: //jump

		//get jump address
		address = * (u32 *) &RxBuffer[1];
		val = * (u32 *)address;

		//check if valid stack pointer
		if(0x20000000 == (val & 0x20000000))
		{
			//disable IRQ
			asm("MOV R0,#1");
			asm("MSR PRIMASK,R0");

			//reset DMA1_I
			RCC_AHBENR &= ~RCC_CLK_DMA1;

			//RESET GPIOA, AFIO, USART1_I
			RCC_APB2RSTR = 0x4005;

			RCC_APB2RSTR = 0;

			//RESET CLOCK TO HSI
			RCC_CR |= RCC_CR_HSION;

			//WAIT
			while(RCC_CR_HSIRDY != (RCC_CR_HSIRDY & RCC_CR))
			{

			}

			RCC_CFGR = 0;

			while(0 != (RCC_CFGR_SWS & RCC_CFGR))
			{

			}

			// Clear HSEON, HSEBYP and CSSON bits
			RCC_CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP | RCC_CR_CSSON);

			// Wait till HSE is disabled
			while(0 != (RCC_CR_HSERDY & RCC_CR))
			{
				// Waiting
			}

			/* Clear PLLON bit */
			RCC_CR &= ~RCC_CR_PLLON;

			/* Wait till PLL is disabled */
			while(0 != (RCC_CR_PLLRDY & RCC_CR))
			{
				/* Waiting */
			}

			/* Reset SysTick */
			SYSTICK_CSR = 0;
			SYSTICK_LOAD = 0;
			SYSTICK_VAL = 0;

			//check jump

			if (0x1FFFF000 == address)
			{
				/* Set jump to the reset handler */
				void (*jump_address)(void) = (void *)(*((u32 *)(address + 4)));



				/* Jump */
				jump_address();
			}
			else
			{

			}

			/* Set jump to the reset handler */
			void (*jump_address)(void) = (void *)(*((u32 *)(address + 4)));



			/* Jump */
			jump_address();

		}
		else
		{
			strTransmit(NACK, sizeof(NACK));
		}
		break;

	default:
		break;
	}


}


void FLASH_SPEED (void){
	FLASH1->ACR |= 0x02;
	FLASH1->ACR &= ~(0x04+0x01);
	// Turn on pre-fetch buffer to speed things up
	FLASH1->ACR |= 0x10;
}

void RCC_DIO_NVIC_Init(void)
{
	RCC_voidInit();
	DIO_Init();



}

void FLASH_USART1_RCC_GPIO_CONFIG(void)
{
	RCC_voidEnableClock(RCC_CLK_IOPA);

	DIO_SetPinConfig(PORTA,PIN9,OUT_50_AF_PP);
	DIO_SetPinConfig(PORTA,PIN10,IN_PULL);

	RCC_voidEnableClock(RCC_CLK_AFIO);

}


void FLASH_USART1_Init(void)
{
	//	RCC_voidEnableClock(RCC_CLK_USART1);
	//	RCC_APB2ENR |= 0x4000;


	//Baud rate 115200
	USART1_I -> USART_BRR = 0x271;

}






void Flash_Main(void)
{
	// check current USART VALUE

	switch (currentState)
	{
	case FLASH_IDLE:
		//trans data
		//strTransmit(line,sizeof (line));
		strTransmit("ELShater", 9);
		strTransmit(select_cmd, sizeof(select_cmd));
		strTransmit(line, sizeof(line));
		strTransmit(lock, sizeof(lock));
		strTransmit(unlock, sizeof(unlock));
		strTransmit(write_data, sizeof(write_data));
		strTransmit(read_data, sizeof(read_data));
		strTransmit(erase, sizeof(erase));

		strTransmit(jump, sizeof(jump));
		strTransmit(line, sizeof(line));
		strTransmit(hello,sizeof(hello));


		currentState = FLASH_WAIT_FOR_CMD;
		break;

	case FLASH_WAIT_FOR_CMD:

		if (0 != RxMessageLength)
		{

			//process comm
			process_command();

			//check errors
			check_errors();

			//reset RxML
			RxMessageLength = 0;
		}
		else
		{

		}
		currentState = FLASH_WAIT_FOR_CMD;
		DMA1_I -> CNDTR5 = MAX_BUFFER_LENGTH;
		//		DMA1_I -> CCR5 &= ~EN;
		//		DMA1_I -> CCR5 |= EN;

		break;

	default:
		break;

	}
}


