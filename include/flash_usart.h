/*
 * flash_usart.h
 *
 *  Created on: Sep 26, 2019
 *      Author: Islam Ehab
 */

#ifndef FLASH_USART_H_
#define FLASH_USART_H_

#define MAX_BUFFER_LENGTH                     ((u32) 128u)


void RCC_DIO_NVIC_Init(void);

void FLASH_SPEED (void);


void FLASH_USART1_RCC_GPIO_CONFIG(void);

void FLASH_USART1_Init(void);

void FLASH_USART1_ENABLE(void);









void Flash_Main(void);


#endif /* FLASH_USART_H_ */
