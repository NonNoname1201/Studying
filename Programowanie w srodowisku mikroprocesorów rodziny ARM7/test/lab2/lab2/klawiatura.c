/*
 * Lab2.c
 *
 * Created: 10.10.2023 18:17:13
 * Author : Uladzislau Krasnavitski
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

 //komenda preprocesora ktora przed kompilacja zamienia wszystkie wystapienia:
#define INPUT DDRB
#define OUTPUT DDRA
#define KEYBOARD PORTA 
#define LED PORTB
#define KEYBOARD_READ PINA 

uint8_t i,x; // zmienne i dla fora, x dla odczytu stanu klawiatury

inline uint8_t klawiatura(); // deklaracja funkcji
inline uint8_t klawiatura_mala(); // deklaracja funkcji

int main(void)
{
	INPUT = 0b11111111; //ustawienie pinow INPUT(PORTB) na wyjscie
	OUTPUT = 0b11110000; //ustawienie pinow KEYBOARD(PORTA) na wejscie
	KEYBOARD = 0b00001111; //podlaczenie rezystora podciągającego na 0,1,2,3 pin KEYBORD(PORTA)

		while (1)
		{
			LED = klawiatura(); // zapisanie wyniku funkcji klawiatura w LED(PORTB)
		}
}

	

inline uint8_t klawiatura()
{
	for (i = 4; i < 8; i++) // petla przechodzaca po wszystkim kolumnam klawiatury
	{
		KEYBOARD = ~(1<<i); //selektywne ustawienia PORTA
		_delay_ms(1);
		x = KEYBOARD_READ & 0x0F; //przypisanie dla odczytu stanu klawiatury
		
		switch (x) // sprawdzenie do jakiego case pasuje x
		{ 
			case 0b00001111: //zaden przycisk nie jest wcisnienty
			/*
			tutaj nic nie robimy dlatego ze jezeli bedziemy zwracac return 0; to nie przejdzie do i = 5 i tak dalej dlatego 
			ze  case 0b00001111 jest defoltowym i w pierwszej iteracji jezeli jest przycisk wcisniety w PA1, PA2, PA3 to petla to nie zobaczy i zwroci 0
			*/
				break; //wychodzmy ze switch'a
			case 0b00001110: //wiersz 1 (u mnie kolumna)
				return i - 3; //sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00001101://wiersz 2 (u mnie kolumna)
				return  i + 1;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00001011://wiersz 3 (u mnie kolumna)
				return i + 5;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00000111://wiersz 4 (u mnie kolumna)
				return i + 9;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			default: // jezeli zaden z powyzszych case nie byl uruchomiony
				return 0xff; // jezeli mamy wcisniete 2 i wiecej przyciski to zapalami wszyscu ledy(tutaj moze byc blad dlatego ze nie moze to sprawdzic u siebie w programie)
				break; //wychodzmy ze switch'a
		}
	}
	return 0; // jezeli zaden przycisk nie byl wcisniety
}

inline uint8_t klawiatura_mala()
{
		KEYBOARD = ~(1<<4); //selektywne ustawienia PORTA
		_delay_ms(1);
		x = KEYBOARD_READ & 0x0F; //przypisanie dla odczytu stanu klawiatury
		
		switch (x) // sprawdzenie do jakiego case pasuje x
		{ 
			case 0b00001111: //zaden przycisk nie jest wcisnienty
			/*
			tutaj nic nie robimy dlatego ze jezeli bedziemy zwracac return 0; to nie przejdzie do i = 5 i tak dalej dlatego 
			ze  case 0b00001111 jest defoltowym i w pierwszej iteracji jezeli jest przycisk wcisniety w PA1, PA2, PA3 to petla to nie zobaczy i zwroci 0
			*/
				break; //wychodzmy ze switch'a
			case 0b00001110: //wiersz 1 (u mnie kolumna)
				return 4 - 3; //sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00001101://wiersz 2 (u mnie kolumna)
				return  4 + 1;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00001011://wiersz 3 (u mnie kolumna)
				return 4 + 5;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			case 0b00000111://wiersz 4 (u mnie kolumna)
				return 4 + 9;//sterownie miedzy weirszem zwiazanym z kolumna i zwrocenie
				break; //wychodzmy ze switch'a
			default: // jezeli zaden z powyzszych case nie byl uruchomiony
				return 0xff; // jezeli mamy wcisniete 2 i wiecej przyciski to zapalami wszyscu ledy(tutaj moze byc blad dlatego ze nie moze to sprawdzic u siebie w programie)
				break; //wychodzmy ze switch'a
		}
	return 0; // jezeli zaden przycisk nie byl wcisniety
}