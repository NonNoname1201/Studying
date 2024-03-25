#include "lcd.h"
#include <util/delay.h>

// Globalny wskaźnik do portu
volatile uint8_t *port;
volatile uint8_t *ddr;

// Funkcja do wysyłania poleceń do LCD
void LCD_input(uint8_t cmd)
{
    *port |= _BV(LCD_EN);
    *port = (cmd & 0xF0) | (*port & 0x0F);
    *port &= ~(_BV(LCD_EN));
    asm volatile("nop");
    *port |= _BV(LCD_EN);
    *port = ((cmd & 0x0F) << 4) | (*port & 0x0F);
    *port &= ~(_BV(LCD_EN));
    _delay_ms(1);
}

// Funkcja do czyszczenia LCD
void LCD_clear()
{
    *port &= ~(_BV(LCD_RS));
    LCD_input(0b00000001);

    _delay_ms(2);
}

// Funkcja do ustawienia kursora na LCD
void LCD_set_cursor(uint8_t x, uint8_t y)
{
    uint8_t cmd = 0x80 | ((y - 1) * 0x40 + x - 1);

    //(y == 1 ? 0x80 : 0xC0) + x - 1;
    *port &= ~(_BV(LCD_RS));
    LCD_input(cmd);
}

// Funkcja do czyszczenia linii y na LCD
void LCD_clear_y(uint8_t y)
{
    set_cursor_LCD(1, y);
    for (uint8_t i = 0; i < 16; i++)
    {
        LCD_printSymbol(' ');
    }
    set_cursor_LCD(1, y);
}

// Funkcja do czyszczenia pozycji x, y na LCD
void LCD_clear_xy(uint8_t x, uint8_t y)
{
    LCD_set_cursor(x, y);
    LCD_printSymbol(' ');
    LCD_set_cursor(x, y);
}

// Funkcja do wyświetlania ciągu znaków na LCD
void LCD_printString(const char *str)
{
    uint8_t i = 0;
    while (str[i] != '\0')
    {
        LCD_printSymbol(str[i]);
        _delay_ms(2);
        i++;
    }
}

// Funkcja do tworzenia symbolu na LCD
void LCD_createSymbol(uint8_t symbolNumber, const uint8_t *symbolData)
{
    *port &= ~(_BV(LCD_RS));
    LCD_input(0x40 | (symbolNumber * 8));

    *port |= _BV(LCD_RS);
    for (uint8_t i = 0; i < 8; i++)
    {
        LCD_input(symbolData[i]);
    }
}

void LCD_printSymbol(uint8_t symbolNumber)
{
    *port |= _BV(LCD_RS);
    LCD_input(symbolNumber);
}

// Funkcja do inicjalizacji LCD
void LCD_init(char portChar)
{
    switch (portChar)
    {
    case 'A':
        port = &PORTA;
        ddr = &DDRA;
        break;
    case 'B':
        port = &PORTB;
        ddr = &DDRB;
        break;
    case 'C':
        port = &PORTC;
        ddr = &DDRC;
        break;
    case 'D':
        port = &PORTD;
        ddr = &DDRD;
        break;
    default:
        return;
    }

    _delay_ms(20);
    *ddr = 0xff;
    *port = 0;

    *port &= ~(_BV(LCD_RS));
    LCD_input(0b00101000);
    LCD_input(0b00000110);
    LCD_input(0b00001100);
    LCD_set_cursor(1, 1);
    *port |= _BV(LCD_RS);
    LCD_clear();
    _delay_ms(2);
}