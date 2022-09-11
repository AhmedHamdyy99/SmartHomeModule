/*
 * PushButton_interface.h
 *
 *  Created on: Aug 11, 2022
 *      Author: AhmedHamdy
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

#include "Dio_interface.h"
#include "PushButton_configuration.h"

#define  PUSH_BUTTON_1 1
#define  PUSH_BUTTON_2 2
#define  PUSH_BUTTON_3 3
#define  PUSH_BUTTON_4 4

#define PRESSED 0
#define RELEASED 1
#define PUSH_BUTTON_DEBOUNCING_TIME 100

void H_PushBubtton_void_PushButtonInit(u8 copy_u8_PushButton);
u8 H_PushBubtton_void_PushButtonRead(u8 copy_u8_PushButton);


#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
