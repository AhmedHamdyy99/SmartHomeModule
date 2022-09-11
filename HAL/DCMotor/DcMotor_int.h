/*
 * DcMotor_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: AhmedHamdy
 */

#ifndef DCMOTOR_DCMOTOR_INT_H_
#define DCMOTOR_DCMOTOR_INT_H_

#include "StandardTypes.h"

void H_DcMotor_void_DcMotorInit(void);
void H_DcMotor_void_ClockWise(void);
void H_DcMotor_void_CounterClockWise(void);
void H_DcMotor_void_DcMotorStop(void);
void H_DcMotor_void_SpeedControl(u8 Local_u8_Speed);

#endif /* DCMOTOR_DCMOTOR_INT_H_ */
