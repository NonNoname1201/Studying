#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>

char getkey(){
	char read = 0;
	char output = 0;
	char rowresult[4] = {0, 0, 0, 0};
	char isPressed = 0;
	char x = PINA;
	_delay_ms(20);
	while(x == PINA){
		output = 0;
		isPressed = 0;
		for(char k = 4; k < 8; k++){
			read = 0;
			PORTA = ~_BV(k);
			_delay_ms(2);

			x = PINA & 0x0f;

			switch(x){
				case 0x0f:{
					read = 0;
					break;
				}
				case 0b00001110:{ //1
					read = 1;
					break;
				}
				case 0b00001101:{ //2
					read = 2;
					break;
				}
				case 0b00001011:{ //3
					read = 3;
					break;
				}
				case 0b00000111:{ //4
					read = 4;
					break;
				}
				default:{
					read = 5;
					break;
				}
			}
			rowresult[k-4] = read;
		}

    for(char i = 0; i < 4; i ++){
    	if(isPressed == 1 && rowresult[i] != 0){
    		output = 255;
			}
			if(isPressed == 0 && rowresult[i] != 0){
				isPressed = 1;
				if(rowresult[i] == 5){
					output = 255;
				}else{
					output = rowresult[i] + i * 4;
				}
			}
		}
		return output;
	}
	return 0x00;
}

void cala_klawiatura(){
	DDRB = 0xff; //led na port B
	DDRA = 0xf0;
	PORTA = 0x0f;
	while(1){
		PORTB = getkey();
		_delay_ms(20);
	}
}


void klawiatura_rzend(){
	DDRA = 0;
	PORTA = 255;
	
	DDRB = 255;
	
	DDRD = 255;
	PORTD = 0;
	
	while(1){
		PORTB = 0b11111110;
		_delay_ms(10);
		if (!(PIND & (1<<PA0))){
			_delay_ms(5);
			PORTD = 1;
		}
		if (!(PIND & (1<<PA1))){
			_delay_ms(5);
			PORTD = 2;
		}
		if (!(PIND & (1<<PA2))){
			_delay_ms(5);
			PORTD = 4;
		}
		if (!(PIND & (1<<PA3))){
			_delay_ms(5);
			PORTD = 8;
		}
	}
}

int main(void)
{
	while (1)
	{
		//klawiatura_rzend();
		cala_klawiatura();
	}
}