/*
 * ADC_Private.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Eng.Hazem
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
#include "StandardTypes.h"
#define ADMUX_REG  (*(volatile char *) 0x27)
#define ADCSRA_REG (*(volatile char *) 0x26)
#define ADCH_REG   (*(volatile char *) 0x25)
#define ADCL_REG   (*(volatile u16 *)  0x24) //U16 TO READ BYTE 24 AND BYTE 25


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
