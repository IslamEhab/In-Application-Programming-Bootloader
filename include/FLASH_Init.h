/*
 * FLASH_Init.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Islam Ehab
 */

#ifndef FLASH_INIT_H_
#define FLASH_INIT_H_

typedef enum
{
	TRUE =0,
	NOT_ERASED,
	WRITE_PROTECTION_ERROR
}Status;

/*typedef enum
{
	FLASH_IDLE = -1,
	FLASH_WAIT_FOR_CMD,
	FLASH_LOCK,
	FLASH_UNLOCK,
	WRITE_DATA,
	READ_DATA,
	SECTOR_ERASE,
	WRITE_PROTECTION,
	REMOVE_WRITE_PROTECTION,
	OPTIONAL_BYTE_UNCLOCK,
	OPTIONAL_BYTE_LOCK,
	DIRECT_JUMP

}FLash_state;*/

#define KEY1  0x45670123
#define KEY2  0xCDEF89AB

#define BSY       0x01
#define PGERR     0x04
#define WRPRTERR  0x10

#define PG     0x01
#define PER    0x02
#define MER    0x04
#define STRT   0x40
void Flash_Init(void);
void Flash_Lock(void);
void Flash_Unlock(void);

Status Write_Sector(u32 address, void * val, u16 size);

void Erase_Sector(u32 address, u8 num);

void Read_Sector(u32 address, void* val, u16 size);


#endif /* FLASH_INIT_H_ */
