#include "klawiatura.h" 
#include <util/delay.h> 
 
// Zmienne globalne 
volatile uint8_t *_PORT; 
volatile uint8_t *_DDR; 
volatile uint8_t *_PIN; 
 
// Inicjalizacja klawiatury 
void init_keyboard(char port) 
{ 
  if (port != 'A' && port != 'B' && port != 'C' && port != 'D') 
  { 
    return; 
  } 
  selectPort(port); 
  *_DDR = 0xf0; 
  *_PORT = 0x0f; 
} 
 
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
 
// Funkcja zwracajaca indeks najbardziej znaczacego bitu 
uint8_t get_index_of_rmsb(uint8_t of) { 
    if (of & 0b00000001) { return 0; } // Jesli najmniej znaczacy bit jest ustawiony na "1," zwracamy 0 jako indeks 
    else if (of & 0b00000010) { return 1; } // Jesli drugi od najmniej znaczacego bitu jest ustawiony na "1," zwracamy 1 jako indeks 
    else if (of & 0b00000100) { return 2; }  
    else if (of & 0b00001000) { return 3; } 
    else if (of & 0b00010000) { return 4; } 
    else if (of & 0b00100000) { return 5; } 
    else if (of & 0b01000000) { return 6; } 
    else if (of & 0b10000000) { return 7; } 
    else { return 8; } // Jesli wszystkie bity sa wyzerowane, zwracamy 8 
} 
 
// Funkcja odczytujaca nacisniety klawisz w trybie 4x1 
uint8_t get_keyboard_pressed_key_index_4x1() { 
    uint8_t row_index = _PIN; // Odczytujemy stan wierszy 
    _DDR = 0x0F; // Ustawiamy wiersze jako wyjscia i kolumny jako wejscia 
    _PORT = 0xF0; // Wlaczamy rezystory pull-up dla kolumn 
    _delay_ms(1); // Opoznienie 
    uint8_t column_index = _PIN; // Odczytujemy stan kolumn 
    _DDR = 0xF0; // Powrot do stanu poczatkowego 
    _PORT = 0x0F; 
 
    if ((row_index | column_index) == 0xFF) { 
        return 0xFF; // Jesli zaden klawisz nie jest nacisniety (wartosc 0xFF) 
    } 
 
    row_index = get_index_of_rmsb(~row_index); // Konwersja stanu wierszy na indeks wiersza 
    column_index = get_index_of_rmsb(~(column_index >> 4)); // Konwersja stanu kolumn na indeks kolumny 
 
    if (row_index == 0 && column_index == 0) { 
        return 0; // Jesli nacisniety jest klawisz w pierwszym wierszu i pierwszej kolumnie, zwracamy 0 
    } else if (row_index == 0 && column_index == 1) { 
        return 1;  
    } else if (row_index == 0 && column_index == 2) { 
        return 2; 
    } else if (row_index == 0 && column_index == 3) { 
        return 3; 
    } 
 
    return 0xFF; // Jesli nacisniety jest inny klawisz, zwracamy 0xFF 
} 
 
// Funkcja odczytujaca nacisniety klawisz w trybie 4x4 
uint8_t get_keyboard_pressed_key_index_4x4() { 
    uint8_t row_index = _PIN; // Odczytujemy stan wierszy 
    _DDR = 0x0F; // Ustawiamy wiersze jako wyjscia i kolumny jako wejscia 
    _PORT = 0xF0; // Wlaczamy rezystory pull-up dla kolumn 
    _delay_ms(1); // Opoznienie 
    uint8_t column_index = _PIN; // Odczytujemy stan kolumn 
    _DDR = 0xF0; // Powrot do stanu poczatkowego 
    _PORT = 0x0F; 
 
    if ((row_index | column_index) == 0xFF) { 
        return 0xFF; // Jesli zaden klawisz nie jest nacisniety (wartosc 0xFF) 
    } 
 
    row_index = get_index_of_rmsb(~row_index); // Konwersja stanu wierszy na indeks wiersza 
    column_index = get_index_of_rmsb(~(column_index >> 4)); // Konwersja stanu kolumn na indeks kolumny 
 
    return row_index * 4 + column_index; // Obliczenie indeksu klawisza w ukladzie 4x4 i zwrocenie go 
}