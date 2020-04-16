#ifndef _DIO_INT_H
#define _DIO_INT_H


#define HIGH 1
#define LOW  0

#define PORTA  1
#define PORTB  2
#define PORTC  3

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13 
#define PIN14  14
#define PIN15  15

//#define I/P_ANALOG

#define IN_ANALOG    0x0
#define IN_FLOAT     0x4
#define IN_PULL      0x8



#define OUT_10       0x1
#define OUT_10_OD    0x5
#define OUT_10_AF_PP 0x9
#define OUT_10_AF_OD 0xD

#define OUT_2        0x2
#define OUT_2_OD     0x6
#define OUT_2_AF_PP  0xA
#define OUT_2_AF_OD  0xE

#define OUT_50       0x3
#define OUT_50_OD    0x7
#define OUT_50_AF_PP 0xB
#define OUT_50_AF_OD 0xF



void DIO_Init(void);

//void Test (u8 port, u8 pin, u8 value);

void DIO_SetPortValue(u8 port, u8 value);

void DIO_SetPinValue(u8 port, u8 pin, u8 value);

void DIO_SetPinConfig(u8 port, u8 pin, u32 config);

u8 DIO_GetpinValue(u8 port, u8 pin);




#endif
