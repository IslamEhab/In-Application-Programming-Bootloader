/*
 * DMA_Int.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Islam Ehab
 */

#ifndef DMA_INT_H_
#define DMA_INT_H_



#define DMA_IFCR_CGIF5         0x00010000
#define DMA_IFCR_CGIF4        0x00001000
#define EN      0x01
#define PL_VH   0x3000
#define PL_H    0x2000
#define MEM2MEM 0x4000
#define MBYTE   0xC00
#define PBYTE   0x300
#define MINC    0x80
#define TCIEE    0x2
#define TEIE    0x08
#define DIR     0x10
#define CIRC    0x20


#define TCIF5  0x20000
#define TCIF7  0x2000000
#define TCIF4  0x2000


void DMA_Init1(void);

void DMA_Transfer (u32 source, u32 destination, u32 count);
void strTransmit(const u8* str, u8 size);
void FLASH_USART1_TX_DMA_CONFIG(void);
void FLASH_USART1_RX_DMA_CONFIG(void);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel5_Do(void);







#endif /* DMA_INT_H_ */
