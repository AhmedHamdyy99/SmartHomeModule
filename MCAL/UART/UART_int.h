/*
 * UART_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: aya_enan
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

void M_UART_void_Init(void);
void M_UAR_void_sendByte(u8 copy_u8Byte);
u8 M_UART_u8_receiveByte(void);
void M_UART_void_sendString(u8 * str );

#endif /* UART_UART_INT_H_ */
