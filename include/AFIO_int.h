/*
 * AFIO_int.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */

#ifndef AFIO_INT_H_
#define AFIO_INT_H_

#define SPI1_REMAP      0x1
#define I2C_REMAP       0x2
#define USART1_REMAP    0x4   //TX->PB6  RX->PB7
#define USART2_REMAP    0x8   //CTS->PD3 RTS->PD4 TX->PD5 RX->PD6 CK->PD7

#define PA0    0x00
#define PA1    0x01
#define PA2    0x02
#define PA3    0x03
#define PA4    0x04
#define PA5    0x05
#define PA6    0x06
#define PA7    0x07
#define PA8    0x08
#define PA9    0x09
#define PA10   0x0A
#define PA11   0x0B
#define PA12   0x0C
#define PA13   0x0D
#define PA14   0x0E
#define PA15   0x0F

#define PB0    0x10
#define PB1    0x11
#define PB2    0x12
#define PB3    0x13
#define PB4    0x14
#define PB5    0x15
#define PB6    0x16
#define PB7    0x17
#define PB8    0x18
#define PB9    0x19
#define PB10   0x1A
#define PB11   0x1B
#define PB12   0x1C
#define PB13   0x1D
#define PB14   0x1E
#define PB15   0x1F


#define PC13   0x2D
#define PC14   0x2E
#define PC15   0x2F

#define EVOE   0x80


void AFIO_voidInit(void);
static void AFIO_voidInitMAPR(void);
static void AFIO_voidInitEXTI(void);


void AFIO_SetPin(u8 pin);
void AFIO_EXTI(u8 pin);

#endif /* AFIO_INT_H_ */
