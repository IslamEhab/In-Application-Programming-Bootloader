/*
 * EXTI_registers.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Islam Ehab
 */

#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_

#define EXTI_IMR    *((volatile u32*) 0x40010400)
#define EXTI_EMR    *((volatile u32*) 0x40010404)
#define EXTI_RTSR   *((volatile u32*) 0x40010408)
#define EXTI_FTSR   *((volatile u32*) 0x4001040C)
#define EXTI_SWIER  *((volatile u32*) 0x40010410)
#define EXTI_PR     *((volatile u32*) 0x40010414)



#endif /* EXTI_REGISTERS_H_ */
