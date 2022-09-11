/*
 * Lcd_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "Lcd_configuration.h"
#include "Dio_interface.h"
#include <util/delay.h>


void H_Lcd_void_LcdInit(void);
void H_Lcd_void_LcdSendCommand(u8 Local_u8_Command);
void H_Lcd_void_LcdSendCharacter(u8 Local_u8_Character);
void H_Lcd_void_LcdSendString(u8 *Copy_u8_Ptr);
void H_Lcd_void_LcdSendNumber(s32 Local_f32_Number);
void H_Lcd_void_LcdGoTo(u8 Local_u8_Row,u8 Local_u8_Col);
void H_Lcd_void_LcdClear(void);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
