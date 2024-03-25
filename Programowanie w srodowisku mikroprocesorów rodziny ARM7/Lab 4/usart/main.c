#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 4000000UL									  // okre�lenie cz�stotliwo�ci pracy mikrokontrolera
#define BAUDRATE 9600									  // okre�lenie pr�dko�ci przesy�ania
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1) // obliczenie preskalera

volatile char tempchar;
volatile char isset = 0;
volatile char counter = 0;

void usart_init()
{
	UBRRH = (BAUD_PRESCALE >> 8); // wpisanie starszego baitu
	UBRRL = BAUD_PRESCALE;		  // wpisanie mlodszego baitu

	UCSRB = (1 << RXCIE) | (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0)
		;
	return (UDR);
}

void UART_TxChar(char znak)
{
	while (!(UCSRA & (1 << UDRE)))
		;

	UDR = znak;
}

void USART_putchar(unsigned char data)
{
	UART_TxChar(data);
}

void UartString(char *s)
{
	while (*s)
	{
		USART_putchar(*s);
		s++;
	}
}

void timer0_init(void)
{
	// praca w przerwaniu od przepelnienia, preskaler 256 wysylanie danych co 3,5ms
	TCCR0 |= (1 << CS02);
	TIMSK |= (1 << TOIE0);
}

ISR(TIMER0_OVF_vect)
{
	if (counter == 100)
	{
		PORTA ^= 0x01; // zmiana stanu diody LED_0
		counter = 0;
	}
	counter++;
}

ISR(USART_RXC_vect) // przerwanie od odbioru danej
{
	if (isset == 0)
	{
		tempchar = UDR;
		isset = 1;
	}
}

void Zadanie1()
{
	UartString("Volodymyr Dobrohorskyi\n\r");
}

void Zadanie2()
{
	unsigned char znak;
	while (1)
	{
		UartString("Nacisnij klawisz [x]\n\r");
		znak = UART_RxChar();
		if (znak == 'x')
		{
			UartString("znak prawidlowy\n\r");
		}
		else
		{
			UartString("blad\n\r");
		}
	}
}

void Zadanie3()
{
	timer0_init();
	DDRA = 0xFF;
	PORTA = 0x00;
	sei();
	int i = 0;
	while (i < 10)
	{
		if (isset == 1)
		{
			if (tempchar == '1')
			{
				PORTA ^= 0x02;
			}
			else if (tempchar == '2')
			{
				PORTA ^= 0x04;
			}
			else if (tempchar == '3')
			{
				PORTA ^= 0x08;
			}
			else if (tempchar == '4')
			{
				PORTA ^= 0x10;
			}
			else if (tempchar == '5')
			{
				PORTA ^= 0x20;
			}
			else if (tempchar == '6')
			{
				PORTA ^= 0x40;
			}
			else if (tempchar == '7')
			{
				PORTA ^= 0x80;
			}
			else if (tempchar == 'c')
			{
				PORTA = 0x00;
			}
			else if (tempchar == 's')
			{
				PORTA = 0xFF;
			}
			else
			{
				UartString("blad\n\r");
			}
			isset = 0;
		}
	}
}

int main()
{
	usart_init();
	UartString("\nGotowy\n\r");

	Zadanie3();
}
