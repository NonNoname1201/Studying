/*
 * GccApplication1.c
 *
 * Created: 17.10.2023 8:22:49
 * Author : User
 */ 

#include <avr/io.h>
#include "klawiatura.h"
#include "klawiatura.c"



int main(void)
{
	INPUT = 0b11111111; //ustawienie pinow INPUT(PORTB) na wyjscie
	OUTPUT = 0b11110000; //ustawienie pinow KEYBOARD(PORTA) na wejscie
	KEYBOARD = 0b00001111; //podlaczenie rezystora podci?gaj?cego na 0,1,2,3 pin KEYBORD(PORTA)

	while (1)
	{
		LED = klawiatura(); // zapisanie wyniku funkcji klawiatura w LED(PORTB)
	}
}
