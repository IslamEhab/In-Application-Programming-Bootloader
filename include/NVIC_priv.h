/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY    Modified by Islam ElShater                  */
/* DESCRIPTION : NVIC DRIVER    [ NVIC_priv.h]              */
/* DATE        : AUGUST 23, 2019                            */
/************************************************************/
#ifndef _NVIC_PRIV_H
#define _NVIC_PRIV_H

/************************ Registers *************************/
/* interrupt set enable registers */
#define NVIC_ISER   ((volatile u32*)0xE000E100)
/* interrupt clear enable registers */
#define NVIC_ICER   ((volatile u32*)0xE000E180)

/* interrupt set pending registers */
#define NVIC_ISPR   ((volatile u32*)0xE000E200)
/* interrupt clear pending registers */
#define NVIC_ICPR   ((volatile u32*)0xE000E280)

/* interrupt active bit registers */
#define NVIC_IABR   ((volatile u32*)0xE000E300)

/* interrupt priority registers */
#define NVIC_IPR    ((volatile u8*)0xE000E400)

/* interrupt software trigger register */
#define NVIC_STIR   *((volatile u32*)0xE000EF00)

/************************************************************/

#endif
