/*
 * UART_prg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: AhmedHamdy
 */

#include "StandardTypes.h"
#include "BitMath.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_int.h"
void M_UART_void_Init(void)
{
   //step 1 : config mode as Asynchrounce
	//select register UCSRC
	SET_BIT(UCSRC,URSEL);
    CLR_BIT(UCSRC,UMSEL);
   //step 2 : Enable Tx and Rx
    SET_BIT(UCSRB,TXEN);
    SET_BIT(UCSRB,RXEN);
   //step 3 : config data length
    UCSRC &= UART_DATA_SIZE_MASK;
    UCSRC |= UART_DATA_SIZE << 1;
    CLR_BIT(UCSRB,UCSZ2);
   //step 4 : config stop bits
    UCSRC &= UART_STOP_BITS_MASK;
    UCSRC |= UART_STOP_BITS << 3;
   //step 5 : config parity bits
    UCSRC &= UART_PARITY_MASK;
    UCSRC |= UART_PARITY << 4;
   //step 6 : config BR
    // select UBRRH
    CLR_BIT(UBRRH,URSEL);
    UBRRH = UART_BAUD_RATE >> 8;

    UBRRL = UART_BAUD_RATE;
}
void M_UAR_void_sendByte(u8 copy_u8Byte)
{
  while(GET_BIT(UCSRA,UDRE) == 0);//busy waiting
  UDR = copy_u8Byte;

}
u8 M_UART_u8_receiveByte(void)
{
	 while(GET_BIT(UCSRA,RXC) == 0);// busy waiting until flag = 1

	 return UDR;
}
void M_UART_void_sendString(u8 * str )
{
  u32 i = 0;
  while(str[i] != '\0')
  {
	  M_UAR_void_sendByte(str[i]);
	  i++;
  }
 // M_UAR_void_sendByte('\0');
}
