/*
 * Led_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Led_interface.h"

void H_Led_void_LedInit(u8 Copy_u8_Led)
{
	switch(Copy_u8_Led)
	{
	case BLU_LED: M_Dio_void_PinMode(BLU_LED_PIN,OUTPUT); break;
	case GRN_LED: M_Dio_void_PinMode(GRN_LED_PIN,OUTPUT); break;
	case RED_LED: M_Dio_void_PinMode(RED_LED_PIN,OUTPUT); break;
	default:                                              break;
	}
}
void H_Led_void_LedOn(u8 Copy_u8_Led)
{
	switch(Copy_u8_Led)
	{
	case BLU_LED: M_Dio_void_PinWrite(BLU_LED_PIN,HIGH); break;
	case GRN_LED: M_Dio_void_PinWrite(GRN_LED_PIN,HIGH); break;
	case RED_LED: M_Dio_void_PinWrite(RED_LED_PIN,HIGH); break;
	default:                                             break;
	}
}
void H_Led_void_LedOff(u8 Copy_u8_Led)
{
	switch(Copy_u8_Led)
	{
	case BLU_LED: M_Dio_void_PinWrite(BLU_LED_PIN,LOW); break;
	case GRN_LED: M_Dio_void_PinWrite(GRN_LED_PIN,LOW); break;
	case RED_LED: M_Dio_void_PinWrite(RED_LED_PIN,LOW); break;
	default:                                            break;
	}
}
/*void H_Led_void_LedToggle_Once(u8 Copy_u8_Led){
	switch (Copy_u8_Led) {
	case LEDBLUE:
		 M_Dio_void_PinWrite(BLU_PIN,High);
		 _delay_ms(1000);
		 M_Dio_void_PinWrite(BLU_PIN,LOW);
		 _delay_ms(1000);
		break;
	case LEDGREEN:
		M_Dio_void_PinWrite(GRN_PIN,High);
		_delay_ms(1000);
		M_Dio_void_PinWrite(GRN_PIN,LOW);
		_delay_ms(1000);
		break;
	case LEDRED:
		M_Dio_void_PinWrite(RED_PIN,High);
		_delay_ms(1000);
		M_Dio_void_PinWrite(RED_PIN,LOW);
		_delay_ms(1000);
		break;
	default:
		break;
	}


}*/
void H_Led_void_LedBlinkOnce(u8 Copy_u8_Led)
{
	switch(Copy_u8_Led)
	{
	case BLU_LED:
		M_Dio_void_PinWrite(BLU_LED_PIN,HIGH);
		_delay_ms(LED_TIME_ON);
		M_Dio_void_PinWrite(BLU_LED_PIN,LOW);
		break;
	case GRN_LED:
		M_Dio_void_PinWrite(GRN_LED_PIN,HIGH);
		_delay_ms(LED_TIME_ON);
		M_Dio_void_PinWrite(GRN_LED_PIN,LOW);
		break;
	case RED_LED:
		M_Dio_void_PinWrite(RED_LED_PIN,HIGH);
		_delay_ms(LED_TIME_ON);
		M_Dio_void_PinWrite(RED_LED_PIN,LOW);
		break;
	default:                           break;
	}
}
void H_Led_void_LedBlinkTwice(u8 Copy_u8_Led)
{
	H_Led_void_LedBlinkOnce(Copy_u8_Led);
	_delay_ms(100);
	H_Led_void_LedBlinkOnce(Copy_u8_Led);
}
