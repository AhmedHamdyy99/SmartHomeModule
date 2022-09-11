/*
 * ExtInt_private.h
 *
 *  Created on: Aug 15, 2022
 *      Author: AhmedHamdy
 */

#ifndef MCAL_EXT_INT_EXTINT_PRIVATE_H_
#define MCAL_EXT_INT_EXTINT_PRIVATE_H_

#define MCUCR_REG    (*((volatile u8*)0x55))
#define GICR_REG     (*((volatile u8*)0x5B))
#define MCUCSR_REG     (*((volatile u8*)0x54))

#define FALLING_EDGE   1
#define RISING_EDGE    2
#define LOW_LEVEL      3
#define LOGICAL_CHANGE 4
#endif /* MCAL_EXT_INT_EXTINT_PRIVATE_H_ */
