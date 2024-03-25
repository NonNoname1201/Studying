#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>

// Definicja pinów LCD
#define LCD_RS 2
#define LCD_EN 3
#define LCD_DB4 4
#define LCD_DB5 5
#define LCD_DB6 6
#define LCD_DB7 7

// Globalny wskaźnik do portu
extern volatile uint8_t *port;

// Funkcja do wysyłania poleceń do LCD
void LCD_input(uint8_t cmd);

// Funkcja do czyszczenia LCD
void LCD_clear();

// Funkcja do ustawienia kursora LCD
void LCD_set_cursor(uint8_t x, uint8_t y);

// Funkcja do czyszczenia linii y
void LCD_clear_y(uint8_t y);

// Funkcja do czyszczenia pozycji x, y
void LCD_clear_xy(uint8_t x, uint8_t y);

// Funkcja do wyświetlania ciągu znaków na LCD
void LCD_printString(const char *str);

// Funkcja do tworzenia symbolu na LCD
void LCD_createSymbol(uint8_t symbolNumber, const uint8_t *symbolData);

// Funkcja do wyświetlania symbolu na LCD
void LCD_printSymbol(uint8_t symbolNumber);

// Funkcja do inicjalizacji LCD
void LCD_init(char portChar);

#endif /* LCD_H_ */