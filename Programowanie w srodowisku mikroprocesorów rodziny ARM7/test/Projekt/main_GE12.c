#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"

#define AUDIO_OUT PIOB_SODR_P19
#define LCD_BACKLIGHT PIOB_SODR_P20 
#define SW_1 PIOB_SODR_P24
#define SW_2 PIOB_SODR_P25


__attribute__ ((section(".fast")))
void delay(int n) //procedura opoznienia 
{
  volatile int i;

  for(i=3000*n;i>0;i--)
  {
  __asm__("nop");
  }
}

int main (){

  PMC_PCER=PMC_PCER_PIOB; //wlaczenie urzadzenia we/wy PIOB
  PIOB_OER= LCD_BACKLIGHT | AUDIO_OUT; //OUTPUT ENABLE
  PIOB_PER= LCD_BACKLIGHT | AUDIO_OUT; //PIO ENABLE 

  InitLCD(); // Inicjalizacja ekranu LCD
  SetContrast(30);
  LCDClearScreen(); // Wyczyszczenie ekranu

  LCDPutStr("Wkras", 15, 10, LARGE, BLACK, WHITE); // Wyświetlenie na LCD imienia i nazwiska
  LCDPutStr("Grupa: 5.4", 30, 30, LARGE, BLACK, WHITE); // Wyświetlenie grupy w kolejnej linii 
  Delaya(10000000); // Opóźnienie 5 sekund
  //LCDClearScreen(); // Wyczyszczenie ekranu
  //LCDWrite130x130bmp(); // Wyświetlenie obrazu na LCD

  while (1){

  if ((PIOB_PDSR & SW_1)==0)
    {
      //ustawienie 1 
      PIOB_SODR|=LCD_BACKLIGHT;
      PIOB_SODR|=AUDIO_OUT;
      delay(1);
      PIOB_CODR|=AUDIO_OUT;
      delay(1);
    }

    if ((PIOB_PDSR & SW_2)==0)
    {
      //ustawienie 0 
      PIOB_CODR|=LCD_BACKLIGHT;
      PIOB_SODR|=AUDIO_OUT;
      delay(5);
      PIOB_CODR|=AUDIO_OUT;
      delay(5);
    }
  }
}