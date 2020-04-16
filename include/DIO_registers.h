#ifndef _DIO_REG_H
#define _DIO_REG_H

//typedef unsigned int u32;
typedef struct
 {
		u32  CRL;
		u32  CRH;
		u32  IDR;
		u32  ODR;
		u32  BSRR;
		u32  BRR;
		u32  LCKR;
	
}GPIO;

#define GPIOA  ((GPIO*) 0x40010800) 
#define GPIOB  ((GPIO*) 0x40010C00)
#define GPIOC  ((GPIO*) 0x40011000)


#endif
