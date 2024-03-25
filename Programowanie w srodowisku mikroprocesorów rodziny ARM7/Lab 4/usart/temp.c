volatile char tempchar;
volatile char isset = 0;

ISR(USART_RXC_vect) // przerwanie od odbioru danej
{
    tempchar = UDR;
    isset = 1;
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