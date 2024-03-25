// BEGIN: header_file
#ifndef KEYBOARD_H // sprawdzenie, czy plik nagłówkowy nie został już wcześniej załączony
#define KEYBOARD_H

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define INPUT DDRB
#define OUTPUT DDRA
#define KEYBOARD PORTA
#define LED PORTB
#define KEYBOARD_READ PINA

uint8_t i,x;

inline uint8_t klawiatura();

#endif
// END: header_file