#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "keyboard.h"

void Zadanie1(){
	char port = 'D';
	bool isSmall = true;
	
	DDRB = 0xff;
	configPort(port);
	while(1){
		PORTB = getkey(port, isSmall);
		_delay_ms(20);
	}
}
int main(void)
{
	while (1)
	{
		Zadanie1();
	}
}