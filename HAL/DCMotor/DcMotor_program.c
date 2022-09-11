/*
 * DcMotor_prog.c
 *
 *  Created on: Aug 31, 2022
 *      Author: AhmedHamdy
 */

#include "DcMotor_config.h"
#include "DcMotor_int.h"
#include "DcMotor_private.h"
#include "Dio_interface.h"
#include "Timer_0_interface.h"
void H_DcMotor_void_DcMotorInit(void)
{
	M_Dio_void_PinMode(DC_MOTOR_IN_1_PIN,OUTPUT);
	M_Dio_void_PinMode(DC_MOTOR_IN_2_PIN,OUTPUT);
	M_Dio_void_PinMode(PB3_PIN,OUTPUT);
	M_Timer_0_void_Init();
}

void H_DcMotor_void_ClockWise(void)
{

	M_Dio_void_PinWrite(DC_MOTOR_IN_1_PIN,HIGH);
	M_Dio_void_PinWrite(DC_MOTOR_IN_2_PIN,LOW);

}


void H_DcMotor_void_CounterClockWise(void)
{

	M_Dio_void_PinWrite(DC_MOTOR_IN_1_PIN,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_IN_2_PIN,HIGH);
}


void H_DcMotor_void_DcMotorStop(void)
{
	M_Dio_void_PinWrite(DC_MOTOR_IN_1_PIN,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_IN_2_PIN,LOW);
}


void H_DcMotor_void_SpeedControl(u8 Local_u8_Speed)
{
	M_Timer_0_void_SetFastPWM(Local_u8_Speed);
}

