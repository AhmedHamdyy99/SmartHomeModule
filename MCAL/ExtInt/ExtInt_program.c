/*
 * ExtInt_program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: AhmedHamdy
 */

#include"ExtInt_private.h"
#include "ExtInt_interface.h"

void (*Call_Back)(void);





void M_ExtInt_void_Init(u8 Copy_u8_Intterupt){

	switch(Copy_u8_Intterupt){
	case EXT_INT_0 :
#if EXT_INT0_SENSE_CONTROL == FALLING_EDGE  //considred as prebulid configuration
		SET_BIT(MCUCR_REG,ISC01_BIT);           //dont change during runtime
		CLR_BIT(MCUCR_REG,ISC00_BIT);           //use switch if the code changes during run time
#elif EXT_INT0_SENSE_CONTROL == RISING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#elif EXT_INT0_SENSE_CONTROL == LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif EXT_INT0_SENSE_CONTROL == LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#endif
		SET_BIT(GICR_REG,INT0_BIT);
		break;

	case EXT_INT_1:
#if EXT_INT1_SENSE_CONTROL == FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC11_BIT);
		CLR_BIT(MCUCR_REG,ISC10_BIT);
#elif EXT_INT0_SENSE_CONTROL == RISING_EDGE
		SET_BIT(MCUCR_REG,ISC11_BIT);
		SET_BIT(MCUCR_REG,ISC10_BIT);
#elif EXT_INT0_SENSE_CONTROL == LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC11_BIT);
		CLR_BIT(MCUCR_REG,ISC10_BIT);
#elif EXT_INT0_SENSE_CONTROL == LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC11_BIT);
		SET_BIT(MCUCR_REG,ISC10_BIT);
#endif
		SET_BIT(GICR_REG,INT1_BIT);
		break;

	case EXT_INT_2:
#if EXT_INT2_SENSE_CONTROL == FALLING_EDGE
		CLR_BIT(MCUCSR_REG,ISC2_BIT);
#elif EXT_INT0_SENSE_CONTROL == RISING_EDGE
		SET_BIT(MCUCSR_REG,ISC2_BIT);


#endif
		SET_BIT(GICR_REG,INT2_BIT);
		break;

	}
	M_GIE_void_ENABLE();
}


void M_Ext_void_SetCallBack(void(*Copy_Ptr)(void)){
	Call_Back=Copy_Ptr;
}





ISR(INT0_vect){
	Call_Back();
}
