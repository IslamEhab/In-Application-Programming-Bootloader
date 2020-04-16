/*

 * FLASH_Prog.c
 *
 *  Created on: Sep 5, 2019
 *      Author: Islam Ehab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FLASH_REG.h"
#include "FLASH_Init.h"





void Flash_Init(void)
{
	FLASH1 -> KEYR = KEY1;
	FLASH1 -> KEYR = KEY2;

	FLASH1 -> CR   = 0x80; // LCK FLASH1

}


void Flash_Lock(void)
{
	FLASH1 -> CR   = 0x80; // LCK FLASH1
}

void Flash_Unlock(void)
{
	FLASH1 ->KEYR = KEY1;
	FLASH1 ->KEYR = KEY2;

}



Status Write_Sector(u32 address, void * val, u16 size)
{
	u16 *AddressPtr;
	u16 *ValuePtr;

	AddressPtr = (u16*)address;
	ValuePtr = (u16*)val;
	size /=2;

	while(size)
	{
		FLASH1 ->KEYR |= KEY1;
		FLASH1 ->KEYR |= KEY2;

		FLASH1 ->CR &= ~0x02;
		FLASH1 ->CR |=  0x01;

		*(AddressPtr) = *(ValuePtr);

		while (FLASH1 ->SR &0x01);

		if (FLASH1 ->SR & 0x04)
			return NOT_ERASED;

		if(FLASH1 ->SR & 0x10)
			return WRITE_PROTECTION_ERROR;

		AddressPtr++;
		ValuePtr++;
		size--;
	}
	return TRUE;
}

void Erase_Sector(u32 address, u8 num)
{
	u8 i =0;
	for(i=0; i<num; i++)
	{
		FLASH1 ->KEYR |= 0x45670123;
		FLASH1 ->KEYR |= KEY2;


		FLASH1 ->CR &=~0x01;
		FLASH1 ->CR |=  0x02;

		FLASH1 ->AR = address;
		FLASH1 ->CR |= 0x42;

		while (FLASH1 ->SR & 0x01);

		address += 0x400;
		FLASH1 ->CR &=~0x02;
		FLASH1 ->AR = 0x00;

	}
}

void Read_Sector(u32 address, void* val, u16 size)
{
	u16 *AddressPtr;
	u16 *ValuePtr;

	AddressPtr = (u16*)address;
	ValuePtr   = (u16*)val;

	size/=2;

	while(size)
	{
		*((u16*)ValuePtr) = *((u16*)AddressPtr);
		ValuePtr++;
		AddressPtr++;
		size--;

	}
}






