/*
 * keypad_program.c
 *
 *  Created on: Aug 14, 2022
 *      Author: AhmedHamdy
 */

#include "keypad_interface.h"
#include <util/delay.h>

void H_Keypad_void_KeypadInit(void){

	M_Dio_void_PinMode(KEYPAD_R0_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R1_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R2_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R3_PIN,OUTPUT);

	M_Dio_void_PinWrite(KEYPAD_R0_PIN,HIGH); //set 4 pins to high to switch between them high and low
	M_Dio_void_PinWrite(KEYPAD_R1_PIN,HIGH);
	M_Dio_void_PinWrite(KEYPAD_R2_PIN,HIGH);
	M_Dio_void_PinWrite(KEYPAD_R3_PIN,HIGH);

	M_Dio_void_PinMode(KEYPAD_C0_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C1_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C2_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C3_PIN,INPUT);

}



u8 H_Keypad_void_KeypadRead(void){
	u8 Local_u8_Reading =0;
	u8 Local_u8_Col=0;
	u8 Local_u8_Row=0;

	u8  Local_u8_Arr [4][4] = {{'1','2','3','A'},
			{'4','5','6','B'},
			{'7','8','9','C'},
			{'*','0','#','D'}};  //ASCII VALUES
	//for loop to loop for rows
	for (Local_u8_Row=KEYPAD_R0_PIN;Local_u8_Row<=KEYPAD_R3_PIN;Local_u8_Row++){

		M_Dio_void_PinWrite(Local_u8_Row,LOW);
		// for loop to know the switch in the column
		for (Local_u8_Col=KEYPAD_C0_PIN;Local_u8_Col<=KEYPAD_C3_PIN;Local_u8_Col++)
		{
			//Local_u8_Reading = M_Dio_pinRead(Local_u8_Col);
			if (M_Dio_pinRead(Local_u8_Col) == 0){ //button is pressed
				_delay_ms(100); //for bouncing
				if (M_Dio_pinRead(Local_u8_Col) == 0){ //check for button
					Local_u8_Reading = Local_u8_Arr [Local_u8_Row - KEYPAD_R0_PIN][Local_u8_Col - KEYPAD_C0_PIN];
					while (M_Dio_pinRead(Local_u8_Col)==0);  //stay in while till the push button is released
					//return Local_u8_Reading;

				}
			}
		}
		M_Dio_void_PinWrite(Local_u8_Row,HIGH);

	}
	return Local_u8_Reading;
}
