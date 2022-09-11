/*
 * TempSensor_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Ahmed Hamdy
 */
#include "TempSensor_Interface.h"
void H_TempSensor_void_TempSensorInit()
{
	M_ADC_void_Init();

}
u16 H_TempSensor_void_TempSensorRead()
{
	u16 Local_u16_TempSensor_value;
	Local_u16_TempSensor_value=(M_ADC_u8_void_ReadValue()*(u32)500)/1023;
	return Local_u16_TempSensor_value;
}
