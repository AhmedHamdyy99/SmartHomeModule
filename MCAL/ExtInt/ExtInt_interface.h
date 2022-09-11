/*
 * ExtInt_interface.h
 *
 *  Created on: Aug 15, 2022
 *      Author: AhmedHamdy
 */

#ifndef MCAL_EXT_INT_EXTINT_INTERFACE_H_
#define MCAL_EXT_INT_EXTINT_INTERFACE_H_
/****************************_INCLUDES_*****************************************/
#include "BitMath.h"
#include "StandardTypes.h"
#include "Led_interface.h"
#include <avr/interrupt.h>
#include "GIE_interface.h"
#include "ExtInt_configuration.h"
/*****************************_MACROS_******************************************/
#define EXT_INT_0   0
#define EXT_INT_1   1
#define EXT_INT_2   2

//MCUCR Bits
#define ISC01_BIT 1
#define ISC00_BIT 0
//GICR BIT
#define INT0_BIT  6

#define ISC10_BIT 2
#define ISC11_BIT 3

#define ISC2_BIT 6

#define INT0_BIT 6

#define INT1_BIT 7

#define INT2_BIT 5

void M_ExtInt_void_Init(u8 Copy_u8_Intterupt);

void M_Ext_void_SetCallBack(void(*Copy_Ptr)(void));

#endif /* MCAL_EXT_INT_EXTINT_INTERFACE_H_ */
