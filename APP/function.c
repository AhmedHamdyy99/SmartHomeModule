/*
 * function.c
 *
 *  Created on: Aug 29, 2022
 *      Author: AhmedHamdy
 */

#include "StandardTypes.h"
#include "BitMath.h"
#include "keypad_interface.h"
#include "Lcd_interface.h"
#include "DcMotor_int.h"
#include "TempSensor_Interface.h"
#include "ADC_interface.h"
#include "Timer_0_interface.h"
#include "Led_interface.h"
#include "function.h"
#include "util/delay.h"
#include "Dio_interface.h"
#include "ExtInt_interface.h"
static u8 App_u8_PassFlag = 0;  //flag to check whether pw is written correct or not
u8 Local_u8_PasswordChar;

//static u16 App_u16_Temp = 0;
//function to initialize the system
void A_App_void_SystemInit(void)
{
	H_Keypad_void_KeypadInit();
	H_Lcd_void_LcdInit();
	H_DcMotor_void_DcMotorInit();
	//	M_ADC_void_ADCInit();
	H_TempSensor_void_TempSensorInit();
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(GRN_LED);
	H_Led_void_LedInit(RED_LED);
	M_Timer_0_void_Init();
	M_Timer_0_void_Start();
	//M_ExtInt_void_Init(INT0);
}

//function to get password from user
void A_App_void_GetPassword(void)
{

	s8 Local_u8_buff[PASS_SIZE] = {0};
	u8 Local_u8_Counter = 0;

	//step1 -> show enter password message
	//H_Lcd_void_LcdSendString("Enter Password:");
	H_Lcd_void_LcdGoTo(1,0);
	H_Lcd_void_LcdSendString("      ----      ");
	H_Lcd_void_LcdGoTo(1,6);
	//H_Lcd_void_LcdSendString("----");
	//step2 -> get password and store it in array
	while (Local_u8_Counter < PASS_SIZE && Local_u8_buff[Local_u8_Counter] != 'Null')
	{
		//Still in loop while user does not press on any button
		while ((Local_u8_PasswordChar = H_Keypad_void_KeypadRead())==0);

		switch (Local_u8_PasswordChar)
		{

		case CHAR_0 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_1 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_2 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_3 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_4 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_5 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_6 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_7 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_8 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_9 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_A :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_B :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_C :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_D :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_HASH :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;

		case CHAR_HASH2 :
			Local_u8_buff[Local_u8_Counter] = Local_u8_PasswordChar;
			H_Lcd_void_LcdSendCharacter('*');
			Local_u8_Counter++;
			break;
		default :                                break;
		}


	}
	if ( Local_u8_buff[0]=='1' && Local_u8_buff[1] == '2'
			&& Local_u8_buff[2] == '8'&& Local_u8_buff[3] == '9')  //password = 1489
	{
		App_u8_PassFlag = 1;  //flag =1 if pw is written correctly
	}
	else
	{
		App_u8_PassFlag = 0;
	}
	return;
}

//function to check password
void A_App_void_CheckPass(void)
{
	static u8 Local_u8_FaultCounter = 0;
	s8 Local_s8_SecondDelay = 0;
	s8 Local_s8_MinDelay = 0;

	while(App_u8_PassFlag ==0){  //password does not written correctly
		if (Local_u8_FaultCounter>=0 && Local_u8_FaultCounter <2)
		{
			H_Lcd_void_LcdClear();
			H_Led_void_LedBlinkTwice(RED_LED);
			H_Lcd_void_LcdSendString("Wrong Password");
			_delay_ms(1000);
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdSendString("Enter Password:");
			A_App_void_GetPassword();
			Local_u8_FaultCounter++;
		}
		if (Local_u8_FaultCounter == 2) //make a delay when user enters pw 3 times wrong
		{
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdGoTo(0,4);
			H_Lcd_void_LcdSendString("Wait for");
			H_Buzzer_void_BuzzerShortSound();
			for (Local_s8_MinDelay=0;Local_s8_MinDelay>=0;Local_s8_MinDelay--){
				for(Local_s8_SecondDelay=59;Local_s8_SecondDelay>=0;Local_s8_SecondDelay--)
				{
					H_Lcd_void_LcdGoTo(1,5);
					H_Lcd_void_LcdSendString("01:00");
					H_Lcd_void_LcdGoTo(1,6);
					H_Lcd_void_LcdSendNumber(Local_s8_MinDelay);
					H_Lcd_void_LcdGoTo(1,8);
					if(Local_s8_SecondDelay >= 10)
					{
						H_Lcd_void_LcdSendNumber(Local_s8_SecondDelay);
					}
					else
					{
						H_Lcd_void_LcdSendCharacter('0');
						H_Lcd_void_LcdGoTo(1,9);
						H_Lcd_void_LcdSendNumber(Local_s8_SecondDelay);
					}
					_delay_ms(1000);
				}
				H_Lcd_void_LcdGoTo(1,6);  //decrement mins to 0
				H_Lcd_void_LcdSendNumber(Local_s8_MinDelay);
			}
			Local_u8_FaultCounter = 0;  //make counter equals zero again
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdSendString("Enter Password:");
			A_App_void_GetPassword();
		}
	}
}

//function to show welcome screen
void A_App_void_Welcome(void)
{
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0,2);
	H_Lcd_void_LcdSendString("Welcome Ahmed");
	H_Buzzer_void_BuzzerShortSound();
	H_Led_void_LedBlinkTwice(GRN_LED);
	_delay_ms(1000);
	H_Lcd_void_LcdClear();
}

/*void A_App_void_SystemOn(void)
{
	//M_ADC_void_ADCInit();
	M_Adc_void_SetCallBack(A_App_void_MotorControl);
}*/
// led control screen
void A_App_void_LedOption(void)
{
	//u8 Local_u8_Control = 0;

	H_Lcd_void_LcdGoTo(0,0);
	//while
	H_Lcd_void_LcdSendString("1- LEDs ON      ");
	H_Lcd_void_LcdGoTo(1,0);
	H_Lcd_void_LcdSendString("2- LEDs OFF     ");
	while((Local_u8_PasswordChar = H_Keypad_void_KeypadRead())==0);
	switch(Local_u8_PasswordChar)
	{
	case '1':A_App_void_LightControl(Local_u8_PasswordChar);
	break;
	case'2':
		A_App_void_LightControl(Local_u8_PasswordChar);
		break;
	default :break;
	}

}
void A_App_void_LightControl(u8 Copy_u8_local)
{
	switch(Copy_u8_local){
	case '1':
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString("1-Red Led 2-Blu Led");
		H_Lcd_void_LcdGoTo(1,0);
		H_Lcd_void_LcdSendString("3-GRN Led 4-ALL");
		while((Local_u8_PasswordChar = H_Keypad_void_KeypadRead())==0);
		switch(Local_u8_PasswordChar){
		case '1':
			H_Led_void_LedOn(RED_LED);
			break;
		case '2':
			H_Led_void_LedOn(BLU_LED);
			break;
		case '3':
			H_Led_void_LedOn(GRN_LED);
			break;
		case '4':
			H_Led_void_LedOn(BLU_LED);
			H_Led_void_LedOn(RED_LED);
			H_Led_void_LedOn(GRN_LED);
			break;
		default :break;
		}
		break;
		case '2':
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdGoTo(0,0);
			H_Lcd_void_LcdSendString("1-Red Led 2-Blu Led");
			H_Lcd_void_LcdGoTo(1,0);
			H_Lcd_void_LcdSendString("3-GRN Led 4-ALL");
			while((Local_u8_PasswordChar = H_Keypad_void_KeypadRead())==0);
			switch(Local_u8_PasswordChar){
			case '1':
				H_Led_void_LedOff(RED_LED);
				break;
			case '2':
				H_Led_void_LedOff(BLU_LED);
				break;
			case '3':
				H_Led_void_LedOff(GRN_LED);
				break;
			case '4':
				H_Led_void_LedOff(BLU_LED);
				H_Led_void_LedOff(RED_LED);
				H_Led_void_LedOff(GRN_LED);
				break;
			default :break;
			}
	}

	A_App_void_LedOption();
}




void A_App_void_MotorControl(void)
{
	//M_Adc_void_SetCallBack(A_App_void_MotorControl);


	volatile u16 App_u16_Temp;
	App_u16_Temp=	H_TempSensor_void_TempSensorRead();
	//H_Lcd_void_LcdSendNumber(App_u16_Temp);

	if(App_u16_Temp<25)
	{
		H_DcMotor_void_DcMotorInit();
		H_DcMotor_void_DcMotorStop();
		//M_Timer_0_void_Start();
	}
	else if(App_u16_Temp>25 && App_u16_Temp<30)
	{
		H_DcMotor_void_DcMotorInit();
		H_DcMotor_void_CounterClockWise();
		H_DcMotor_void_SpeedControl(50);
//M_Timer_0_void_Start();

	}
	else
	{
		H_DcMotor_void_CounterClockWise();
		H_DcMotor_void_SpeedControl(90);
		//M_Timer_0_void_Start();

	}


}
