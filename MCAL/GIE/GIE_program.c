/*
 * GIE_program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: AhmedHamdy
 */

#include "GIE_interface.h"
#include "GIE_private.h"

void M_GIE_void_ENABLE(void){

	SET_BIT(SREG_REG,I_BIT);
}


void M_GIE_void_DISABLE(void){

	CLR_BIT(SREG_REG,I_BIT);
}

