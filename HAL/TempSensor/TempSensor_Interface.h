/*
 * TempSensor_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Eng.Hazem
 */

#ifndef HAL_TEMPSENSOR_TEMPSENSOR_INTERFACE_H_
#define HAL_TEMPSENSOR_TEMPSENSOR_INTERFACE_H_
#include "Dio_Interface.h"
#include "StandardTypes.h"
#include "Tempsensor_Private.h"
#include<util/delay.h>
#include "TempSensor_Configration.h"
#include "ADC_Interface.h"
void H_TempSensor_void_TempSensorInit(void);
u16 H_TempSensor_void_TempSensorRead(void);

#endif /* HAL_TEMPSENSOR_TEMPSENSOR_INTERFACE_H_ */
