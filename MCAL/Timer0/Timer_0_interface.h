/*
 * Timer_0_interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: AhmedHamdy
 */

#ifndef MCAL_TIMER_0_TIMER_0_INTERFACE_H_
#define MCAL_TIMER_0_TIMER_0_INTERFACE_H_

/*************************_includes_**************************************/
#include "StandardTypes.h"
#include "avr/interrupt.h"
#include "GIE_interface.h"
#include "Timer_0_configuration.h"
#include "stdlib.h"
void M_Timer_0_void_Init(void);
void M_Timer_0_void_SetTime(u32);
void M_Timer_0_void_Stop(void);
void M_Timer_0_SetCallBack(void (*Copy_Ptr)(void),u8 Copy_u8_IntID);
void M_Timer_0_void_Start(void);
void M_Timer_0_void_Start(void);
void M_Timer_0_void_EnableInt(u8 Copy_u8_IntID);
void M_Timer_0_void_DisableInt(u8 Copy_u8_IntID);
void M_Timer_0_void_SetFastPWM(u8 Copy_u8_DutyCycle);
void M_Timer_0_void_PhaseCorrectPWM(u8 Copy_u8_DutyCycle);
/*to select interrupt for which mode*/
#define TIMER0_OVF_INT_ID  0
#define TIMER0_COMP_MATCH_INT_ID  1

#endif /* MCAL_TIMER_0_TIMER_0_INTERFACE_H_ */
