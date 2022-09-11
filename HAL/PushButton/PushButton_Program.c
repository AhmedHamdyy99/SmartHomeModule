/*
 * PushButton.c
 *
 *  Created on: Aug 11, 2022
 *      Author: Ahmed Hamdy
 */

/****************************************Includes****************************************/


#include"PushButton_interface.h"
#include"PushButton_configuration.h"
#include "Dio_interface.h"
#include"BitMath.h"
#include <util/delay.h>
/****************************************Functions****************************************/


void H_PushBubtton_void_PushButtonInit(u8 copy_u8_PushButton)
{
	switch(copy_u8_PushButton)
	{
	case PUSH_BUTTON_1: M_Dio_void_PinWrite(PUSH_BUTTON_1_PIN,INPUT);	break;
	case PUSH_BUTTON_2: M_Dio_void_PinWrite(PUSH_BUTTON_2_PIN,INPUT);	break;
	case PUSH_BUTTON_3: M_Dio_void_PinWrite(PUSH_BUTTON_3_PIN,INPUT);	break;
	case PUSH_BUTTON_4: M_Dio_void_PinWrite(PUSH_BUTTON_4_PIN,INPUT);	break;
	default:                                                        break;
	}
}


u8 H_PushBubtton_void_PushButtonRead(u8 copy_u8_PushButton)
{

	u8 local_u8_Reading = RELEASED;

	switch(copy_u8_PushButton)
	{
	case PUSH_BUTTON_1:
		local_u8_Reading = M_Dio_pinRead(PUSH_BUTTON_1_PIN);
		if(M_Dio_pinRead(PUSH_BUTTON_1_PIN)==PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_pinRead(PUSH_BUTTON_1_PIN)==PRESSED)
			{
				local_u8_Reading= PRESSED;
				while(M_Dio_pinRead(PUSH_BUTTON_1_PIN)==PRESSED);
			}
		}
		break;
	case PUSH_BUTTON_2:
		local_u8_Reading = M_Dio_pinRead(PUSH_BUTTON_2_PIN);
		if(M_Dio_pinRead(PUSH_BUTTON_2_PIN)==PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_pinRead(PUSH_BUTTON_2_PIN)==PRESSED)
			{
				local_u8_Reading= PRESSED;
				while(M_Dio_pinRead(PUSH_BUTTON_2_PIN)==PRESSED);
			}
		}

		break;
	case PUSH_BUTTON_3:
		local_u8_Reading= M_Dio_pinRead(PUSH_BUTTON_3_PIN);
		if(M_Dio_pinRead(PUSH_BUTTON_3_PIN)==PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_pinRead(PUSH_BUTTON_3_PIN)==PRESSED)
			{
				local_u8_Reading= PRESSED;
				while(M_Dio_pinRead(PUSH_BUTTON_3_PIN)==PRESSED);
			}
		}

		break;
	case PUSH_BUTTON_4:
		local_u8_Reading = M_Dio_pinRead(PUSH_BUTTON_4_PIN);
		if(M_Dio_pinRead(PUSH_BUTTON_4_PIN)==PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_pinRead(PUSH_BUTTON_4_PIN)==PRESSED)
			{
				local_u8_Reading= PRESSED;
				while(M_Dio_pinRead(PUSH_BUTTON_4_PIN)==PRESSED);
			}
		}

		break;
	default:break;
	}
	return local_u8_Reading;

}
