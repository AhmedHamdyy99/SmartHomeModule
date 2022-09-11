/*
 * ssd_interface.h
 *
 *  Created on: Aug 14, 2022
 *      Author: AhmedHamdy
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_
#include "ssd_configuration.h"
void H_Ssd_void_SsdInit(void);
void H_Ssd_void_SsdDisplay(u8 );
//static void H_Ssd_void_SsdDigitDisplay(u8 Copy_u8_Value);
void H_Ssd_void_SsdCountDown(u8 Copy_u8_Value);
void H_Ssd_void_SsdCountUp(u8 Copy_u8_Value);
#endif /* HAL_SSD_SSD_INTERFACE_H_ */
