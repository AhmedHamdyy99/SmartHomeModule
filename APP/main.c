/*
 * main.c
 *
 *  Created on: Aug 29, 2022
 *      Author: AhmedHamdy
 */

#include "function.h"
#include "StandardTypes.h"
#include "Dio_interface.h"
#include "util/delay.h"
extern u8 Local_u8_PasswordChar;

int main(){
	A_App_void_SystemInit();
	M_Dio_void_PinMode(PA0_PIN,INPUT);
	volatile u16 READ;
	//M_Dio_void_PinMode(PB3_PIN,OUTPUT);
	//M_Adc_void_SetCallBack(A_App_void_MotorControl);
	while(1)
	{

		A_App_void_MotorControl();
		H_Lcd_void_LcdSendString("Enter Password");
		A_App_void_GetPassword();
		A_App_void_CheckPass();
		A_App_void_Welcome();
		A_App_void_LedOption();

		/* u16 App_u16_Temp;
							App_u16_Temp = H_TempSensor_u16_Read();

							if(App_u16_Temp<25)
							{
								H_DcMotor_void_DcMotorStop();

							}
							else if(App_u16_Temp>25 && App_u16_Temp<30)
							{
								H_DcMotor_void_CounterClockWise();
								H_DcMotor_void_SpeedControl(50);


							}
							else
							{
								H_DcMotor_void_CounterClockWise();
								H_DcMotor_void_SpeedControl(100);


							}*/
					}

	return 0;
}

