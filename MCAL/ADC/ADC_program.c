/*
 * ADC_Program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Ahmed Hamdy
 */

#include "ADC_Interface.h"
void M_ADC_void_Init(void)
{
#if ADC_V_REF==AVCC
	CLR_BIT(ADMUX_REG,REFS1_BIT);
	SET_BIT(ADMUX_REG,REFS0_BIT);
#elif ADC_V_REF==AREF_PIN
	CLR_BIT(ADMUX_REG,REFS1_BIT);
	CLR_BIT(ADMUX_REG,REFS0_BIT);
#elif ADC_V_REF==_2v56
	SET_BIT(ADMUX_REG,REFS1_BIT);
	SET_BIT(ADMUX_REG,REFS0_BIT);
#endif
	CLR_BIT(ADMUX_REG,ADLR_BIT); //to select right adjust
	//TO SELECT ADC0 CHANNAL
	CLR_BIT(ADMUX_REG,MUX4_BIT);
	CLR_BIT(ADMUX_REG,MUX3_BIT);
	CLR_BIT(ADMUX_REG,MUX2_BIT);
	CLR_BIT(ADMUX_REG,MUX1_BIT);
	CLR_BIT(ADMUX_REG,MUX0_BIT);
	//TO SELLECT DIVISION FACTOR 128 AND PRESCALLER
	SET_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
	//enable ADC in ADCSRA REGISTER
	SET_BIT(ADCSRA_REG,ADATE_BIT);// TO ENABLE AUTOTRIGGER
	SET_BIT(ADCSRA_REG,ADEN_BIT);

}
u16 M_ADC_u8_void_ReadValue(void)
{
	//TO START CONVERSION
	SET_BIT(ADCSRA_REG,ADCS_BIT);
	while(GET_BIT(ADCSRA_REG,ADIF_BIT)==0);

	//_delay_ms(200);

	return ADCL_REG;
}
