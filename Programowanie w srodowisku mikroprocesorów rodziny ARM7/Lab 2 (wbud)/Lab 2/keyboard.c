#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "keyboard.h"

volatile uint8_t *_PORT;
volatile uint8_t *_DDR;
volatile uint8_t *_PIN;

void selectPort(char port)
{
	switch (port)
	{
	case 'A':
	{
		_PORT = &PORTA;
		_DDR = &DDRA;
		_PIN = &PINA;
		break;
	}
	case 'B':
	{
		_PORT = &PORTB;
		_DDR = &DDRB;
		_PIN = &PINB;
		break;
	}
	case 'C':
	{
		_PORT = &PORTC;
		_DDR = &DDRC;
		_PIN = &PINC;
		break;
	}
	case 'D':
	{
		_PORT = &PORTD;
		_DDR = &DDRD;
		_PIN = &PIND;
		break;
	}
	}
}

unsigned char getkey(char port, bool isSmall)
{
	if (port != 'A' && port != 'B' && port != 'C' && port != 'D')
	{
		return 255;
	}
	char read = 0;
	char output = 0;
	char rowresult[4] = {0, 0, 0, 0};
	char isPressed = 0;
	char x = *_PIN, base = *_PIN;

	while (x == base)
	{
		output = 0;
		isPressed = 0;
		if (isSmall)
		{
			*_PORT = ~_BV(4);
			_delay_ms(2);
			x = *_PIN & 0x0f;
			switch (x)
			{
			case 0x0f:
			{
				return 0;
				break;
			}
			case 0b00001110:
			{ // 1
				return 1;
				break;
			}
			case 0b00001101:
			{ // 2
				return 2;
				break;
			}
			case 0b00001011:
			{ // 3
				return 3;
				break;
			}
			case 0b00000111:
			{ // 4
				return 4;
				break;
			}
			default:
			{
				return 5;
				break;
			}
			}
		}

		for (char k = 4; k < 8; k++)
		{
			read = 0;
			*_PORT = ~_BV(k);
			_delay_ms(2);
			x = *_PIN & 0x0f;

			switch (x)
			{
			case 0x0f:
			{
				read = 0;
				break;
			}
			case 0b00001110:
			{ // 1
				read = 1;
				break;
			}
			case 0b00001101:
			{ // 2
				read = 2;
				break;
			}
			case 0b00001011:
			{ // 3
				read = 3;
				break;
			}
			case 0b00000111:
			{ // 4
				read = 4;
				break;
			}
			default:
			{
				read = 5;
				break;
			}
			}
			rowresult[k - 4] = read;
		}

		for (char i = 0; i < 4; i++)
		{
			if (rowresult[i] != 0)
			{
				if (isPressed == 0)
				{
					isPressed = 1;
					if (rowresult[i] == 5)
					{
						output = 255;
					}
					else
					{
						output = rowresult[i] + i * 4;
					}
				}
				else
				{
					output = 255;
				}
			}
		}
		return output;
	}
	return 0x00;
}

void configPort(char port)
{
	if (port != 'A' && port != 'B' && port != 'C' && port != 'D')
	{
		return;
	}
	selectPort(port);
	*_DDR = 0xf0;
	*_PORT = 0x0f;
}
