/*
 * USART_Init.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Islam Ehab
 */

#ifndef USART_INIT_H_
#define USART_INIT_H_

#define UART1    0
#define UART2    1
#define UART3    2

#define DISABLE   0
#define ENABLE    1

#define RXNE      0x20
#define IDLE      0x10

/**************CR1*********/
#define SBK       0x01
#define RWU       0x02
#define RE        0x04
#define TE        0x08
#define IDLEIE    0x10
#define RXNEIE    0x20
#define TCIE      0x40
#define TXEIE     0x80
#define PEIE      0x100
#define PS        0x200
#define PCE       0x400
#define WAKE      0x800
#define M         0x1000
#define UE        0x2000

/*************CR2*********/
#define ADD0      32
#define ADD1      33
#define ADD2      34
#define ADD3      35
#define LBDL      37
#define LBDIE     38
#define LBCL      40
#define CPHA      41
#define CPOL      42
#define CLKEN     43
#define STOP0     44
#define STOP1     45
#define LINEN     46
/***********CR3*********/
#define EIE       0x01
#define IREN      0x02
#define IRLP      0x04
#define HDSEL     0x08
//#define NACK      0x10
#define SCEN      0x20
#define DMAR      0x40
#define DMAT      0x80
#define RTSE      0x100
#define CTSE      0x200
#define CTSIE     0x400


void USART_Init1(u8 usart, u8 value);
void USART_Sendchar(u8 usart, u8 data);
void USART_SendString(u8 usart,u8* str, u8 size);
u8   USART_Getchar(u8 usart);
void USART_GetString (u8 usart);
void String_Rx (u8 usart,u8 size);
#define MAX_BUFFER    ((u32) 128u)


extern	u32 arr[MAX_BUFFER];





#endif /* USART_INIT_H_ */
