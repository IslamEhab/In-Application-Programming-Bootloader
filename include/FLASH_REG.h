/*
 * FLASH_REG.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Islam Ehab
 */

#ifndef FLASH_REG_H_
#define FLASH_REG_H_

//typedef unsigned int u32;
typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 RES1;
	u32 OBR;
	u32 WRPR;
}flash_reg;

#define FLASH1 ((volatile flash_reg*) 0x40022000)


#endif /* FLASH_REG_H_ */
