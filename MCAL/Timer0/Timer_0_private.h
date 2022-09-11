/*
 * Timer_0_private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: AhmedHamdy
 */

#ifndef MCAL_TIMER_0_TIMER_0_PRIVATE_H_
#define MCAL_TIMER_0_TIMER_0_PRIVATE_H_
#include "StandardTypes.h"

#define TCCR0_REG (*((volatile u8*)0x53))
#define TIMSK_REG (*((volatile u8*)0x59))
#define  TCNT0_REG (*((volatile u8*)0x52))
#define  OCR0_REG (*((volatile u8*)0x5C))

#define F_OSC 16
#define WGM00_BIT  6
#define WGM01_BIT  3

/*prescalar bits*/
#define CS00_BIT 0
#define CS01_BIT 1
#define CS02_BIT 2
#define TOIE0_BIT 0
#define OCIE0_BIT 1
/**********************************/

/*timer modes*/
#define TIMER0_NORMAL_MODE       0
#define TIMER0_CTC_MODE          1
#define TIMER0_FASTPWM_MODE      2
#define TIMER0_PHASECORRECT_MODE 3

/*Timer prescalar mode*/
#define TIMER_0_PRESCALAR_1                 1
#define TIMER_0_PRESCALAR_8                 2
#define TIMER_0_PRESCALAR_64                3
#define TIMER_0_PRESCALAR_256               4
#define TIMER_0_PRESCALAR_1024              5
#define TIMER_0_PRESCALAR_EXTCLK_FALLEDGE   6
#define TIMER_0_PRESCALAR_EXTCLK_RISEEDGE   7

/*timer OC0 mode*/
#define TIMER0_OC0_DISCONNECTED  0
#define TIMER0_OC0_TOG           1
#define TIMER0_OC0_CLEAR         2
#define TIMER0_OC0_SET           3


#define TIMER0_OC0_PWM_NON_INVERTING  0b00100000
#define TIMER0_OC0_PWM_INVERTING      0b00110000

#define TIMER0_PRESCALAR_MASK  0b11111000
#define TIMER0_OC0_MODE_MASK   0b11001111

#define TIMER_OC0_SHIFT 4
#endif /* MCAL_TIMER_0_TIMER_0_PRIVATE_H_ */
