/*
 * GccApplication1.cpp
 *
 * Created: 2023-04-17 13:31:52
 * Author : Student
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRA = 0xFF;
   while (1)
   {
	   PORTA = (1<<0);
	   _delay_ms(1000);
	   PORTA  |= (1<<1);
	   _delay_ms(1000);
	    PORTA = 0b01111111;
	    _delay_ms(1000);
   }
 
}

