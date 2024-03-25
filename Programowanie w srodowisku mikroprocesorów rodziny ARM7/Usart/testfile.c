void usart_init(void)
{
    UBRRH = (BAUD_PRESCALE >> 8); // wpisanie starszego baitu
    UBRRL = BAUD_PRESCALE;        // wpisanie mlodszego baitu

    // UCSRA bez zmian 0x00
    UCSRB = (1 << RXCIE) | (1 << RXEN) | (1 << TXEN);   // aktywne przerwanie od odbioru oraz zmiana trybu działania pinów DO i D1
    UCSRC = (1 << URSEL) | (1 << UCSZO) | (1 << UCSZ1); // praca asynchroniczna, brak kontroli parzystości, 1 bit stopu, 8 bitów danych
}

/*Odbiór danych można dokonać dwoma sposobami:*/

// programowo poprzez monitorowanie bitu RXC w UCSRA
// Bit RXC wskazuje stan odebrania danej.
unsigned char UART_RxChar()
{
    while ((UCSRA & (1 << RXC)) == 0)
        ;
    return (UDR);
}

// lub poprzez przerwanie:
ISR(USART_RXC_vect) // przerwanie od odbioru danej
{
    static char a; // zmienna pomocnicza
    a = UDR;       // zapis odebranej danej
    a ^= 0xFF;     // operacja bitowa XOR
    UDR = a;       // wysłanie danej zwrotnej
}

/*Nadawanie poprzez port można dokonać:
- monitorując bit UDRE z UCSRA. Gdy flaga UDRE jest ustawiona, oznacza że bufor nadawczy jest pusty i gotowy do przyjęcia kolejnego bajtu:
*/

void UART_TxChar(char znak)
{
    while (!(UCSRA & (1 << UDRE)))
        ; /* Wait for empty transmit buffer */

    UDR = znak;
}

/* lub w przerwaniu od timera, który służy jako znacznik czasu wysyłania danych poprzez port:*/

void timer0_init(void)
{
    // praca w przerwaniu od przepelnienia, preskaler 256, wysylanie danych co 3,5ms
    TCCR0 |= (1 << CS02);
    TIMSK |= (1 << TOIE0);
}

ISR(TIMER0_OVF_vect)
{
    UDR = PINB; // Port B jako źródło danych
}

/*Jak należy skonfigurować port USART do trybu nadawanie z prędkością 9600 bodów (bps) dla F_CPU= 4 MHz.
 */

#define F_CPU 4000000UL                                   // określenie częstotliwości pracy mikrokontrolera
#define BAUDRATE 9600                                     // określenie prędkości przesyłania
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1) // obliczenie preskalera

void usart_init(void)
{
    UBRRH = (BAUD_PRESCALE >> 8); // wpisanie starszego baitu
    UBRRL = BAUD_PRESCALE;        // wpisanie mlodszego baitu

    // UCSRA bez zmian 0x00
    UCSRB = (1 << RXCIE) | (1 << RXEN) | (1 << TXEN);   // aktywne przerwanie od odbioru oraz zmiana trybu działania pinów DO i D1
    UCSRC = (1 << URSEL) | (1 << UCSZO) | (1 << UCSZ1); // praca asynchroniczna, brak kontroli parzystości, 1 bit stopu, 8 bitów danych
}

void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE)))
        ;
    UDR = data;
}

/*Zadanie 2:
Do programu z zadania 1 dodać funkcję odbioru danych. Na terminal należy wysłać wiadomość: "Nacisnij klawisz [x]" (student wybiera indywidualnie znak). Następnie program powinien oczekiwać na wprowadzenie wybranego znaku z poziomu klawiatury komputera PC, a po
jego podaniu nadać wiadomość potwierdzającą odbiór (np.. “znak prawidlowy”).
W przypadku podania złego znaku (litery) należy wygenerować kod błędu (np. "błędny znak").
*/

// Tip:
unsigned char UART_RxChar()
{
    while ((UCSRA & (1 << RXC)) == 0)
        ;       /* Wait till data is received */
    return UDR; /* Return the byte */
}

void UART_TxChar(char znak)
{
    while (!(UCSRA & (1 << UDRE)))
        ; /* Wait for empty transmit buffer */

    UDR = znak;
}

void UartString(char *s)
{
    while (*s)
    {
        UART_TxChar(*s);
        s++;
    }
}

int main()
{
    unsigned char znak;
    usart_init();
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

/*Zadanie 3:
Należy podłączyć diody przewodami łączeniowymi według schematu:
LED_0 → (PA0)
LED_1 → (PA1)
LED_2 → (PA2)
LED_3 → (PA3)
LED_4 → (PA4)
LED_5 → (PA5)
LED_6 → (PA6)
LED_7 → (PA7)
W układzie jak powyżej (baud rate = 9600, ramka: 8 bitów danych, brak kontroli parzystości, 1 bit
stopu) napisać program, który:
a) będzie powodował cykliczne miganie diodą LED_0 z wykorzystaniem przerwania od porównania
Timera 0,
b) umożliwi sterowanie pozostałymi diodami z klawiatury komputera PC ([1] – LED_1, [2] – LED_2,
itd.) z wykorzystaniem transmisji szeregowej. Po wciśnięciu klawisza [x], jego wartość powinna zostać
wyświetlona na terminalu komputera PC, a wybrana dioda powinna zostać przełączona w stan
przeciwny. Dodatkowo przyciski [c] i [s] powinny odpowiednio wyłączać (clear) i włączać (set)
wszystkie diody od LED_1 do LED_7. Wciśnięcie jakiegokolwiek innego klawisza powinno zwrócić
wiadomość o błędzie. Do realizacji odbioru danych można w tym zadaniu wykorzystać obsługę
przerwania od zakończenia odbioru przez USART (USART_RXC_vect).
Tip:
Załączenie obsługi przerwań od odbioru danych następuje w rejestrze UCSRB. */

#define F_CPU 4000000UL                                   // określenie częstotliwości pracy mikrokontrolera
#define BAUDRATE 9600                                     // określenie prędkości przesyłania
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1) // obliczenie preskalera

void usart_init(void)
{
    UBRRH = (BAUD_PRESCALE >> 8); // wpisanie starszego baitu
    UBRRL = BAUD_PRESCALE;        // wpisanie mlodszego baitu

    // UCSRA bez zmian 0x00
    UCSRB = (1 << RXCIE) | (1 << RXEN) | (1 << TXEN);   // aktywne przerwanie od odbioru oraz zmiana trybu działania pinów DO i D1
    UCSRC = (1 << URSEL) | (1 << UCSZO) | (1 << UCSZ1); // praca asynchroniczna, brak kontroli parzystości, 1 bit stopu, 8 bitów danych
}

void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE)))
        ;
    UDR = data;
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
    // praca w przerwaniu od przepelnienia, preskaler 256, wysylanie danych co 3,5ms
    TCCR0 |= (1 << CS02);
    TIMSK |= (1 << TOIE0);
}

ISR(TIMER0_OVF_vect)
{
    PORTA ^= 0x01; // zmiana stanu diody LED_0
}

// ISR(USART_RXC_vect) // przerwanie od odbioru danej
// {
//     static char a; // zmienna pomocnicza
//     a = UDR;       // zapis odebranej danej
//     a ^= 0xFF;     // operacja bitowa XOR
//     UDR = a;       // wysłanie danej zwrotnej
// }

int main()
{
    unsigned char znak;
    usart_init();
    timer0_init();
    DDRA = 0xFF; // port A jako wyjscie
    PORTA = 0x00;
    while (1)
    {
        znak = UART_RxChar();
        if (znak == '1')
        {
            PORTA ^= 0x02;
        }
        else if (znak == '2')
        {
            PORTA ^= 0x04;
        }
        else if (znak == '3')
        {
            PORTA ^= 0x08;
        }
        else if (znak == '4')
        {
            PORTA ^= 0x10;
        }
        else if (znak == '5')
        {
            PORTA ^= 0x20;
        }
        else if (znak == '6')
        {
            PORTA ^= 0x40;
        }
        else if (znak == '7')
        {
            PORTA ^= 0x80;
        }
        else if (znak == 'c')
        {
            PORTA = 0x00;
        }
        else if (znak == 's')
        {
            PORTA = 0xFF;
        }
        else
        {
            UartString("blad\n\r");
        }
    }
}
