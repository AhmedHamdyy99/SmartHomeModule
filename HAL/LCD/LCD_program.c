/*
 * Lcd_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "Lcd_interface.h"
#include "Lcd_private.h"


void H_Lcd_void_LcdInit(void)
{
#if    LCD_MODE   ==   _8_BIT_MODE
	M_Dio_void_PinMode(LCD_D0_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D1_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D2_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D3_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D7_PIN,OUTPUT);

	M_Dio_void_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_EN_PIN,OUTPUT);

	H_Lcd_void_LcdSendCommand(LCD_8_BIT_MODE_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);

#elif LCD_MODE   ==   _4_BIT_MODE

	M_Dio_void_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_DATA7_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_RS_PIN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_void_LcdSendCommand(_4_BIT_MODE_COMAND_1);
	H_Lcd_void_LcdSendCommand(_4_BIT_MODE_COMAND_2);
	H_Lcd_void_LcdSendCommand(_4_BIT_MODE_COMAND_3);
	H_Lcd_void_LcdSendCommand(DISPLAY_ON_CURSOR_OFF);
	H_Lcd_void_LcdSendCommand(LCD_RETURN_HOME);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR);
#endif

}
void H_Lcd_void_LcdSendCommand(u8 Local_u8_Command)
{
	M_Dio_void_PinWrite(LCD_RS_PIN,LOW);
#if   LCD_MODE   ==   _8_BIT_MODE

	M_Dio_void_PinWrite(LCD_D0_PIN,Copy_u8_Command >> 0 & 0x01); //Hishof l harf l enta ba3to k ascii
	M_Dio_void_PinWrite(LCD_D1_PIN,Copy_u8_Command >> 1 & 0x01);
	M_Dio_void_PinWrite(LCD_D2_PIN,Copy_u8_Command >> 2 & 0x01);
	M_Dio_void_PinWrite(LCD_D3_PIN,Copy_u8_Command >> 3 & 0x01);
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);

	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_Dio_void_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT =((LCD_DATA_PORT)& 0b10000111) |(((Local_u8_Command)>>1) & 0b01111000);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(1);
	LCD_DATA_PORT =((LCD_DATA_PORT)& 0b10000111) |(((Local_u8_Command)<<3) & 0b01111000);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#endif
	_delay_ms(5);
}
void H_Lcd_void_LcdSendCharacter(u8 Local_u8_Character)
{
	M_Dio_void_PinWrite(LCD_RS_PIN,HIGH);
#if   LCD_MODE   ==   _8_BIT_MODE

	M_Dio_void_PinWrite(LCD_D0_PIN,Copy_u8_Character >> 0 & 0x01);
	M_Dio_void_PinWrite(LCD_D1_PIN,Copy_u8_Character >> 1 & 0x01);
	M_Dio_void_PinWrite(LCD_D2_PIN,Copy_u8_Character >> 2 & 0x01);
	M_Dio_void_PinWrite(LCD_D3_PIN,Copy_u8_Character >> 3 & 0x01);
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);

	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE // send binary of character
	M_Dio_void_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT =((LCD_DATA_PORT)& 0b10000111) |(((Local_u8_Character)>>1) & 0b01111000);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(1);
	LCD_DATA_PORT =((LCD_DATA_PORT)& 0b10000111) |(((Local_u8_Character)<<3) & 0b01111000);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);

#endif
	_delay_ms(5);
}
void H_Lcd_void_LcdSendString(u8 *Copy_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Copy_u8_Ptr[Local_u8_Counter] != '\0')
	{
		H_Lcd_void_LcdSendCharacter(Copy_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}
void H_Lcd_void_LcdSendNumber(s32 Local_f32_Number)
{
	u8 Local_u8_Arr [10]={0};
		s8 Local_s8_Counter=0;
		s8 Local_s8_Decimal_Point=0;
		s32 Local_s32_Number;

		if(Local_f32_Number<0)
		{
			Local_f32_Number *= -1;
			H_Lcd_void_LcdSendCharacter('-');
		}

		Local_s32_Number=Local_f32_Number;

		if (Local_s32_Number==0)H_Lcd_void_LcdSendCharacter(48);

		while (Local_s32_Number != Local_f32_Number)
		{
			Local_f32_Number=Local_f32_Number * 10;
			Local_s32_Number=Local_f32_Number;
			Local_s8_Decimal_Point++;
		}


		while (Local_s32_Number !=0)
		{
			Local_u8_Arr[Local_s8_Counter] =Local_s32_Number %10;
			Local_s32_Number = Local_s32_Number/10;
			Local_s8_Counter ++;
		}

		Local_s8_Counter --;

		while (Local_s8_Counter >=0 )
		{
			if((Local_s8_Decimal_Point>0)&&(Local_s8_Decimal_Point -1 == Local_s8_Counter))
			{
				H_Lcd_void_LcdSendCharacter('.');
			}
			H_Lcd_void_LcdSendCharacter(Local_u8_Arr[Local_s8_Counter]+48);
			Local_s8_Counter --;
		}

}
void H_Lcd_void_LcdClear(void)
{
	H_Lcd_void_LcdSendCommand(LCD_CLEAR);
}
void H_Lcd_void_LcdGoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr[2]={LCD_R0_C0_COMAND,LCD_R1_C0_COMAND};
	H_Lcd_void_LcdSendCommand(Local_u8_arr[Local_u8_Row]+Local_u8_Col);

}
