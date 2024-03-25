#include <targets\AT91SAM7.h>
#include "PCF8833U8_lcd.h"
#include "at91sam7x256.h"

#define BUTTON_SW1 AT91C_PIO_PB0
#define BUTTON_SW2 AT91C_PIO_PB1
#define BUZZER AT91C_PIO_PB2
#define LED AT91C_PIO_PB3

void setup()
{
  // Enable the clock of PIOB
  AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PIOB;

  // Set BUTTON_SW1 and BUTTON_SW2 as input
  AT91C_BASE_PIOB->PIO_ODR = BUTTON_SW1 | BUTTON_SW2;
  AT91C_BASE_PIOB->PIO_PER = BUTTON_SW1 | BUTTON_SW2;

  // Set BUZZER and LED as output
  AT91C_BASE_PIOB->PIO_OER = BUZZER | LED;
  AT91C_BASE_PIOB->PIO_PER = BUZZER | LED;
}

void loop()
{
  // Check if BUTTON_SW1 is pressed
  if (!(AT91C_BASE_PIOB->PIO_PDSR & BUTTON_SW1))
  {
    // Turn on the LED
    AT91C_BASE_PIOB->PIO_SODR = LED;
  }
  else
  {
    // Turn off the LED
    AT91C_BASE_PIOB->PIO_CODR = LED;
  }

  // Check if BUTTON_SW2 is pressed
  if (!(AT91C_BASE_PIOB->PIO_PDSR & BUTTON_SW2))
  {
    // Turn on the buzzer
    AT91C_BASE_PIOB->PIO_SODR = BUZZER;
  }
  else
  {
    // Turn off the buzzer
    AT91C_BASE_PIOB->PIO_CODR = BUZZER;
  }
}

int main()
{
  setup();

  while (1)
  {
    loop();
  }

  return 0;
}