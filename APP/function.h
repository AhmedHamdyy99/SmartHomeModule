/*
 * function.h
 *
 *  Created on: Aug 29, 2022
 *      Author: AhmedHamdy
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "StandardTypes.h"
/********************************_MACROS_***************************************/
#define PASS_SIZE  4
#define Null     \0

/*Macros for passwords*/
#define  CHAR_0    '0'
#define  CHAR_1    '1'
#define  CHAR_2    '2'
#define  CHAR_3    '3'
#define  CHAR_4    '4'
#define  CHAR_5    '5'
#define  CHAR_6    '6'
#define  CHAR_7    '7'
#define  CHAR_8    '8'
#define  CHAR_9    '9'
#define  CHAR_A    'A'
#define  CHAR_B    'B'
#define  CHAR_C    'C'
#define  CHAR_D    'D'
#define  CHAR_HASH '#'
#define  CHAR_HASH2    '*'

/****************************_PROTOTYPES_****************************************/
void A_App_void_SystemInit(void);
void A_App_void_GetPassword(void);
void A_App_void_CheckPass(void);
void A_App_void_Welcome(void);
//void A_App_void_SystemOn(void);
void A_App_void_LedOption(void);
void A_App_void_LightControl(u8 Copy_u8_local);
void A_App_void_MotorControl(void);

#endif /* FUNCTION_H_ */
