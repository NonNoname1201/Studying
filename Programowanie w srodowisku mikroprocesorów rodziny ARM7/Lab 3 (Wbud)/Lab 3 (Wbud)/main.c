/*
 * Lab 3 (Wbud).c
 *
 * Created: 17.10.2023 8:44:05
 * Author : User
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "lcd.h"
#include "keyboard.h"
#include "character.h"


void Zadanie_1()
{
    while (1)
    {
        LCD_clear();
        LCD_set_cursor(1, 1);
        LCD_printString("Dobrohorskyi. V.");
        
		char key = getkey('B', false);
		
		LCD_set_cursor(1, 2);
		
		LCD_printString("Klawisz: ");
		
        LCD_set_cursor(9, 2);
		
        if (key < 10)
        {
            LCD_printSymbol('0' + (char)key);
        }
        else
        {
            LCD_printSymbol('0' + (char)key / 10);
            LCD_printSymbol('0' + (char)key % 10);
        }
		
        _delay_ms(100);
    }
}

void Zadanie_2(){
	LCD_createSymbol(0, character());
	while (1)
	{
		LCD_clear();
		LCD_set_cursor(1,1);
		LCD_printSymbol(0);
		
		_delay_ms(100);
	}
}

int main(void)
{
    LCD_init('A');
    Keyboard_init('D');
	DDRA = 0xff;

    while (1)
    {
		
		Zadanie_2();
		_delay_ms(10);
    }
}
