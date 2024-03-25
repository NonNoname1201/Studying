/*
 * Lab1.c
 *
 * Created: 2023-04-13 15:31:16
 * Author : Volodymyr Dobrohorskyi
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define _BV(x) (1 << x)

void pingpong(){
	PORTB = 0x03; //c0 60 30 18 0c 06 03
	char way = 0;
	char counter = 1;
	while (1){
		if(way == 0){
			counter++;
			PORTB ^= _BV(counter);
			PORTB ^= _BV(counter - 2);
			if(counter == 7){
				way=1; counter=6;
			}
		}
		else{
			counter--;
			PORTB ^= _BV(counter);
			PORTB ^= _BV(counter + 2);
			if(counter == 0){
				way=0; counter = 1;
			}
		}
		_delay_ms(50);
	}
}

void wave(){
	PORTB = 0x01;
	char isRising = 1;
	char counter = 0;
	while (1){
		if (isRising == 1){
			counter++;
			PORTB ^= _BV(counter);
			if(counter == 3) {
				isRising = 0;
				counter=4;
			}
		}
		else{
			counter--;
			PORTB ^= _BV(counter);
			if(counter == 1){
				 isRising = 1;
				 counter = 0;
			}
		}
		_delay_ms(250);
	}
}

void overload(){
	PORTB = 0x01;
	char counter = 0;
	while(1){
		counter++;
		PORTB ^= _BV(counter);
		if(counter == 8){
			PORTB ^= 0xfe;
			counter = 0;
		}
		_delay_ms(125);
	}
}

void stairsInsideOut(){
	PORTB= 0x08;
	char way = 1;
	char counter = 3;
	while(1){
		if(way == 1){
			counter--;
			PORTB^= _BV(counter);
			_delay_ms(250);
			if(counter == 0){
				PORTB= 0x10;
				counter = 4;
				way = 0;
			}
		}
		else{
			counter++;
			PORTB^= _BV(counter);
			_delay_ms(250);
			if(counter == 7){
				PORTB= 0x08;
				counter = 3;
				way = 1;
			}
		}
		_delay_ms(250);
	}
}

void stairsOutsideIn(){
	PORTB= 0x01;
	
	char way = 1;
	char counter = 0;
	while(1){
		if(way == 1){
			counter++;
			PORTB^= _BV(counter);
			_delay_ms(250);
			if(counter == 3){
				PORTB= 0x80;
				counter = 7;
				way = 0;
			}
		}
		else{
			counter--;
			PORTB^= _BV(counter);
			_delay_ms(250);
			if(counter == 4){
				PORTB= 0x01;
				counter = 0;
				way = 1;
			}
		}
		_delay_ms(250);
	}
}

int main(void)
{
	DDRB=0xff;
	
    /* Replace with your application code */
    pingpong();
}


