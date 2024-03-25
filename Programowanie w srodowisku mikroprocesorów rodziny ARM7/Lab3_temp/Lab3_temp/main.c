/*
 * Lab3_temp.c
 *
 * Created: 04.05.2023 11:27:05
 * Author : User
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Define variables
volatile uint8_t count = 0; // Counter variable

// Define timer0 normal mode initialization function with external clock
void timer0_init() {
	TCCR0 = 0; // Normal mode
	TCCR0 = (1 << CS00) | (1 << CS02); // Prescaler = 1024
	TIMSK = (1 << TOIE0); // Enable timer overflow interrupt
}


// Define timer0 overflow interrupt service routine
ISR(TIMER0_OVF_vect) {
	count++; // Increment counter
}

int main() {
	DDRA = 0xFF; // Set LED pins as output
	timer0_init(); // Initialize timer0 in normal mode with external clock

	while (1) {
		// Read counter and check overflow flag
		uint8_t cnt = TCNT0;
		if (TIFR & (1 << TOV0)) {
			cnt = 0; // Timer overflow, reset counter
			TIFR |= (1 << TOV0); // Clear overflow flag
			TCCR0 &= ~(1 << CS02) & ~(1 << CS01) & ~(1 << CS00); // Stop timer
		}

		// Display counter on LED pins
		PORTA = cnt;

		// Delay before next read
		_delay_ms(200);
		
		// Check button state and edge
		uint8_t button_state = PINB & (1 << PB0);
		static uint8_t button_prev_state = 0;
		if (button_state != button_prev_state) {
			// Button state changed, check edge
			if (button_state & ~button_prev_state) {
				// Rising edge, start timer
				TCNT0 = 0; // Reset counter
				count = 0; // Reset count variable
				TCCR0 |= (1 << CS02) | (1 << CS00); // Prescaler = 1024, external clock
				} else {
				// Falling edge, stop timer and display count
				TCCR0 &= ~(1 << CS02) & ~(1 << CS01) & ~(1 << CS00); // Stop timer
				PORTA = count;
			}
			button_prev_state = button_state; // Update button state
		}
	}
	
	return 0;
}

