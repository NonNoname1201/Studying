#include <targets\AT91SAM7.h>
#include <ioLib.h>
#include "includeBitMapArrays.h"

void AudioResponse()
{
  PIOB_SODR |= AUDIO_OUT;
  Delay_(1000);
  PIOB_CODR |= AUDIO_OUT;
  Delay_(1000);

  PMC_PCER = PMC_PCER_PIOB; // wlaczenie urzadzenia we/wy PIOB
  PMC_PCER = PMC_PCER_PIOA;
  PIOB_OER = LCD_BACKLIGHT | AUDIO_OUT; // OUTPUT ENABLE
  PIOB_PER = LCD_BACKLIGHT | AUDIO_OUT; // PIO ENABLE

  while (1)
  {
    if ((PIOB_PDSR & SW_1) == 0)
    {
      PIOB_SODR |= LCD_BACKLIGHT; // ustawienie 1
      PIOB_SODR |= AUDIO_OUT;
      Delay_(1000);
      PIOB_CODR |= AUDIO_OUT;
      Delay_(1000);
    }
    if ((PIOB_PDSR & SW_2) == 0)
    {
      PIOB_CODR |= LCD_BACKLIGHT; // ustawienie 0
      PIOB_SODR |= AUDIO_OUT;
      Delay_(1000);
      PIOB_CODR |= AUDIO_OUT;
      Delay_(1000);
    }
  }
}
void PrintName()
{
  LCDPutStr("Imie i Nazwisko:", 10, 0, LARGE, BLACK, WHITE, OPAQUE);       // Wyświetlenie na LCD imienia i nazwiska
  LCDPutStr("Volodymyr Dobrohorsky:", 15, 1, SMALL, BLACK, WHITE, OPAQUE); // Wyświetlenie na LCD imienia i nazwiska
  LCDPutStr("Grupa: ", 30, 0, LARGE, BLUE, WHITE, OPAQUE);                 // Wyświetlenie grupy w kolejnej linii
  LCDPutStr("5.1", 43, 1, SMALL, BLUE, WHITE, OPAQUE);                     // Wyświetlenie grupy w kolejnej linii
}

void FillColor(int c)
{ // Unoptimized, use LCDClearScreenColored instead
  for (int i = 0; i < 131; i++)
  {
    for (int j = 0; j < 131; j++)
    {
      LCDSetPixel(i, j, c);
    }
  }
}

Zadanie1(int color)
{
  int tempColor = color;
  FillColor(color);

  while (1)
  {
    tempColor = ((PIOB_PDSR & SW_1) == 0) ? BLACK : color; // Switch 1
    LCDPutStr("SW1", 110, 10, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOB_PDSR & SW_2) == 0) ? BLACK : color; // Switch 2
    LCDPutStr("SW2", 110, 100, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOA_PDSR & JOY_UP) == 0) ? BLACK : color; // Joystick up
    LCDPutStr("UP", 20, 60, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOA_PDSR & JOY_DOWN) == 0) ? BLACK : color; // Joystick down
    LCDPutStr("DOWN", 110, 50, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOA_PDSR & JOY_LEFT) == 0) ? BLACK : color; // Joystick left
    LCDPutStr("LEFT", 60, 0, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOA_PDSR & JOY_RIGHT) == 0) ? BLACK : color; // Joystick right
    LCDPutStr("RIGHT", 60, 90, MEDIUM, tempColor, color, OPAQUE);

    tempColor = ((PIOA_PDSR & JOY_ENTER) == 0) ? BLACK : color; // Joystick enter
    LCDPutStr("ENTER", 60, 45, MEDIUM, tempColor, color, OPAQUE);
  }
}

Zadanie2(int color, int font)
{
  FillColor(color);

  int x = 65;
  int y = 65;
  LCDPutStr("X", x, y, font, BLACK, color, OPAQUE);
  int paddingLeft = 0;
  int paddingRight = (font == SMALL) ? 6 : (font == MEDIUM || font == LARGE) ? 8
                                                                             : 16;
  int paddingTop = 0;
  int paddingBottom = (font == SMALL) ? 6 : (font == MEDIUM) ? 8
                                                             : 16;

  while (1)
  {
    LCDPutStr("X", x, y, MEDIUM, BLACK, color, TRANSPARENTBG);
    Delay_(100000);
    if ((PIOA_PDSR & JOY_UP) == 0 && x > paddingRight)
    {
      LCDPutStr("X", x, y, MEDIUM, color, color, TRANSPARENTBG);
      x--;
    }
    if ((PIOA_PDSR & JOY_DOWN) == 0 && x < paddingLeft)
    {
      LCDPutStr("X", x, y, MEDIUM, color, color, TRANSPARENTBG);
      x++;
    }
    if ((PIOA_PDSR & JOY_LEFT) == 0 && y > paddingTop)
    {
      LCDPutStr("X", x, y, MEDIUM, color, color, TRANSPARENTBG);
      y--;
    }
    if ((PIOA_PDSR & JOY_RIGHT) == 0 && y < paddingBottom)
    {
      LCDPutStr("X", x, y, MEDIUM, color, color, TRANSPARENTBG);
      y++;
    }
  }
}

void screenAnim()
{
  while (1)
  {
    LCDWriteBMP(bmp_131_0, sizeof(bmp_131_0), 0, 0, 131, 131);
    Delay(10000000);
    // LCDWriteBMP(bmp_131_1, 0, 0, 131, 131);
    Delay(10000000);
    // LCDWriteBMP(bmp_132_0, 0, 0, 132, 132);
    // Delay_(100000);
    // LCDWriteBMP(bmp_132_1, 0, 0, 132, 132);
    // Delay_(100000);
  }
}

int main()
{
  PMC_PCER = PMC_PCER_PIOA;
  PMC_PCER = PMC_PCER_PIOB;
  InitLCD(); // Inicjalizacja ekranu LCD
  LCDSettings();
  SetContrast(40);

  LCDClearScreenColored(WHITE);
  LCDPutStr("HELLO WORLD", 16, 0, LARGE, RED, BLUE, TRANSPARENTBG);
  LCDSetPixel(10, 10, BLACK);
  LCDPutChar(0, 0, 0, CUSTOM, BLUE, RED, TRANSPARENTBG);
  LCDPutChar(1, 0, 8, CUSTOM, BLUE, RED, TRANSPARENTBG);

  // OPAQUE
  // TRANSPARENTTEXT
  // TRANSPARENTBG

  screenAnim();

  // LCDPutCharExtendedCustom(2, 10, 10, FontCustom1, BLACK, WHITE, TRANSPARENTBG);

  // screenAnim();

  /*1. Pytanie 1. Jak adresujemy i kodujemy pozycję piksela i jego kolor na wyświetlacz
    LCD?
    2. Pytanie 2. W jaki sposób rozróżniamy instrukcję od danej wysyłanej do
    wyświetlacza LCD.
    3. Pytanie 3. W jaki sposób włączamy interfejs SPI0 do pracy?
    4. Pytanie 4. W jaki sposób budujemy funkcje graficzne, np. rysowanie linii?*/

  // 1. Adresowanie i kodowanie pozycji piksela i jego koloru na wyswietlacz LCD
  // // Row address set (command 0x2B)
  // WriteSpiCommand(PASET);
  // WriteSpiData(x0);
  // WriteSpiData(x0);

  // // Column address set (command 0x2A)
  // WriteSpiCommand(CASET);
  // WriteSpiData(y0);
  // WriteSpiData(y0);

  // // Now illuminate the pixel (2nd pixel will be ignored)
  // WriteSpiCommand(RAMWR);
  // WriteSpiData((color >> 4) & 0xFF);
  // WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
  // WriteSpiData(color & 0xFF);

  // 2. Rozroznianie instrukcji od danej wysylanej do wyswietlacza LCD
  // // Command
  // WriteSpiCommand(0x2A);
  // // Data
  // WriteSpiData(0x00);
  // data = rawData | 0x100;   8th bit high
  // command = rawData & 0xFF; 8th bit low

  // 3. Wlaczanie interfejsu SPI0 do pracy
  // // Enable SPI0
  // PMC_PCER = PMC_PCER_SPI0;
  // // Enable SPI0 pins
  // PIOA_PDR = SPI0_MISO | SPI0_MOSI | SPI0_SPCK;
  // PIOA_ASR = SPI0_MISO | SPI0_MOSI | SPI0_SPCK;
  // // Enable SPI0 master mode
  // SPI0_CR = SPI0_CR_SPIEN | SPI0_CR_MSTR;
  // // Set SPI0 clock divider
  // SPI0_CSR = SPI0_CSR_SCBR(1) | SPI0_CSR_BITS_8_BIT;

  // 4. Budowanie funkcji graficznych, np. rysowanie linii
  // // Set the window to draw into
  // WriteSpiCommand(CASET);
  // WriteSpiData(x0);
  // WriteSpiData(x1);
  // WriteSpiCommand(PASET);
  // WriteSpiData(y0);
  // WriteSpiData(y1);
  // // Now illuminate the pixels
  // WriteSpiCommand(RAMWR);
  // for (i = 0; i < (x1 - x0 + 1) * (y1 - y0 + 1); i++)
  // {
  //   WriteSpiData((color >> 4) & 0xFF);
  //   WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF)); //3 commands for 2 pixels
  //   WriteSpiData(color & 0xFF);
  // }
}
