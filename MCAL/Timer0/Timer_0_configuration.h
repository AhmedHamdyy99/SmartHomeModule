/*
 * Timer_0_configuration.h
 *
 *  Created on: Aug 17, 2022
 *      Author: AhmedHamdy
 */

#ifndef MCAL_TIMER_0_TIMER_0_CONFIGURATION_H_
#define MCAL_TIMER_0_TIMER_0_CONFIGURATION_H_

/*select TIMER_0_PRESCALAR*/
#define TIMER_0_PRESCALAR TIMER_0_PRESCALAR_1024

/*
 * choose from:
 * Timer 0 normal mode
 * timer0 ctc mode
 * fast PWM
 * phase correct mode
 *
 */
#define TIMER_0_MODE  TIMER0_FASTPWM_MODE


/*
 * CHOOSE FROM
 * DISCONNECTED
 * TOGGLE
 * CLEAR
 * SET
 * pwm
 * TIMER0_OC0_PWM_NON_INVERTING
 * TIMER0_OC0_PWM_INVERTING
 *
 */




#define TIMER_0_OC0_MODE   TIMER0_OC0_PWM_INVERTING

#define F_OSC 16


#endif /* MCAL_TIMER_0_TIMER_0_CONFIGURATION_H_ */
