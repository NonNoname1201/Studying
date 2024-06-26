#include <targets\AT91SAM7.h>
#include "ioLib.h"
#include "fonts.h"
#include "includeBitmapArrays.h"

void DelayA(unsigned long a)
{
  while (--a != 0)
    ;
}

void Delay(unsigned long a)
{

  volatile unsigned long d;
  d = a;
  while (--d != 0)
    ;
}

void WriteSpiCommand(unsigned int data)
{

  data = (data & ~0x0100);

  // Wait for the transfer to complete
  while ((SPI0_SR & SPI0_SR_TXEMPTY) == 0)
    ;

  SPI0_TDR = data;
}

void WriteSpiData(unsigned int data)
{

  data = (data | 0x0100);

  // Wait for the transfer to complete
  while ((SPI0_SR & SPI0_SR_TXEMPTY) == 0)
    ;

  SPI0_TDR = data;
}

void Backlight(unsigned char state)
{

  if (state == BL_ON)
    PIOB_SODR = BIT20; // Set PB20 to HIGH
  else
    PIOB_CODR = BIT20; // Set PB20 to LOW
}

void SetContrast(unsigned char contrast)
{
  WriteSpiCommand(CONTRAST);
  WriteSpiData(0x20 + contrast); // contrast
}

void LCDSettings(void)
{
  LCD_RESET_LOW;
  Delay(10000);
  LCD_RESET_HIGH;
  Delay(10000);

  // Sleep out (command0x11)
  WriteSpiCommand(SLEEPOUT);

  // Inversion on(command 0x20)
  WriteSpiCommand(INVERSIONOFF); // seems to be required for this controller

  // Color Interface Pixel Format(command 0x3A)
  WriteSpiCommand(PIXELFORMAT);
  WriteSpiData(0x03); // 0x03 =12bits-per-pixel

  // Write contrast  (command 0x25)
  WriteSpiCommand(CONTRAST);
  WriteSpiData(0x40); // contrast 0x38
  Delay(10000);

  // DisplayOn  (command 0x29)
  WriteSpiCommand(DISPLAYON);

  // 6. Set Normal mode (my)
  WriteSpiCommand(NORMALMODE);

  // 7. Inversion off
  WriteSpiCommand(INVERSIONOFF); // OFF?

  // 8. Column address set
  WriteSpiCommand(COLADDRSET);
  WriteSpiData(0);
  WriteSpiData(131);

  // 9. Page address set
  WriteSpiCommand(PAGEADDRSET);
  WriteSpiData(0);
  WriteSpiData(131);

  // 10. Memory access controler
  WriteSpiCommand(ACCESSCTRL);
  WriteSpiData(0x08);

  ///// Display setting 1 end  /////

  ///// Power supply  ///////

  // 1. Power control
  WriteSpiCommand(PWRCTRL);
  WriteSpiData(4); // Internal resistance, V1OUT -> high power mode, oscilator devision rate

  // 2. Sleep out
  WriteSpiCommand(SLEEPOUT);

  // 3. Voltage control - voltage control and write contrast define LCD electronic volume
  WriteSpiCommand(VOLTCTRL);
  // WriteSpiData(0x7f);    //  full voltage control
  // WriteSpiData(0x03);    //  must be "1"

  DelayA(2000);

  // 5. Temperature gradient
  WriteSpiCommand(TEMPGRADIENT);
  for (int i = 0; i < 14; i++)
  {
    WriteSpiData(0);
  }

  // 6. Booster voltage ON
  WriteSpiCommand(BOOSTVON);

  // Finally - Display On
  WriteSpiCommand(DISPLAYON);
}

void InitLCD(void)
{

  // Pin for backlight
  PIOB_SODR = BIT20; // Set PB20 to HIGH
  PIOB_OER = BIT20;  // Configure PB20 as output
  // Reset pin
  PIOA_SODR = BIT2; // Set PA2 to HIGH
  PIOA_OER = BIT2;  // Configure PA2 as output
  // Init SPI0
  // set functionality to pins:
  // port0.12 -> NPCS0
  // port0.16 -> MISO
  // port0.17 -> MOSI
  // port0.18 -> SPCK
  PIOA_PDR = BIT12 | BIT16 | BIT17 | BIT18 | BIT13;
  PIOA_ASR = BIT12 | BIT16 | BIT17 | BIT18 | BIT13;
  PIOA_BSR = 0;
  // enable the clock of SPI
  PMC_PCER = PMC_PCER_SPI0;
  // Fixed mode
  SPI0_CR = 0x80;         // SPI Enable, Sowtware reset
  SPI0_CR = 0x01;         // SPI Enable
  SPI0_MR = 0x100E0011;   // Master mode, fixed select, disable decoder, FDIV=1 (MCK), PCS=1110
  SPI0_CSR0 = 0x01010C11; // 9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32*12 = 125kHz
  SPI0_CSR1 = 0x01010502;
  Delay(10000);
  LCDSettings();
}

//@VD:
void LCDWriteBMP(unsigned char a, int x0, int y0, int x1, int y1)
{
  int x = (x0 < x1) ? x0 : x1;
  int y = (y0 < y1) ? y0 : y1;
  int dx = abs(x0 - x1);
  int dy = abs(y0 - y1);

  // Display OFF
 
  WriteSpiCommand(DISPLAYOFF);

  // Column address set (command 0x2A)
  WriteSpiCommand(CASET); // CASET na COLADDRSET
  WriteSpiData(x);
  WriteSpiData(x+dx);

  // Row address set (command 0x2B)
  WriteSpiCommand(PASET); // PASET NA PAGEADDRSET
  WriteSpiData(y);
  WriteSpiData(y+dy);

  // WRITE MEMORY
  WriteSpiCommand(MEMWRITE);

  if(a == 0){
    for (int j  = 0; j < sizeof(bmp_34); j++)
    {
      WriteSpiData(bmp_34[j]);
    }
  } else {
  for (int j  = 0; j < sizeof(bmp_34_1); j++)
    {
      WriteSpiData(bmp_34_1[j]);
    }
  }
  // Display On
  WriteSpiCommand(DISPLAYON);
}

void LCDClearScreen(void)
{

  // Row address set (command 0x2B)
  WriteSpiCommand(PASET); // PASET NA PAGEADDRSET
  WriteSpiData(0);
  WriteSpiData(131);

  // Column address set (command 0x2A)
  WriteSpiCommand(CASET); // CASET na COLADDRSET
  WriteSpiData(0);
  WriteSpiData(131);

  // set the display memory to WHITE
  WriteSpiCommand(RAMWR); // RAMWR na MEMWRITE
  for (long i = 0; i < ((132 * 132) / 2); i++)
  {
    WriteSpiData((WHITE >> 4) & 0xFF);
    WriteSpiData(((WHITE & 0xF) << 4) | ((WHITE >> 8) & 0xF));
    WriteSpiData(WHITE & 0xFF);
  }
}

void LCDClearScreenColored(int color)
{ //@VD now with color
  long i;

  // Row address set (command 0x2B)
  WriteSpiCommand(PASET); // PASET NA PAGEADDRSET
  WriteSpiData(0);
  WriteSpiData(131);

  // Column address set (command 0x2A)
  WriteSpiCommand(CASET); // CASET na COLADDRSET
  WriteSpiData(0);
  WriteSpiData(131);

  // set the display memory to color
  WriteSpiCommand(RAMWR); // RAMWR na MEMWRITE
  for (i = 0; i < ((132 * 132) / 2); i++)
  {
    WriteSpiData((color >> 4) & 0xFF);
    WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
    WriteSpiData(color & 0xFF);
  }
}

// *************************************************************************************
// Lights a single pixel in the specified color at the specified x and y addresses
//
// Inputs: x = row address (0 .. 131)
// y = column address (0 .. 131)
// color = 12-bit color value bbbbggggrrrr
// rrrr = 1111 full red
// :
// 0000 red is off
//
// gggg = 1111 full green
// :
// 0000 green is off
//
// bbbb = 1111 full blue
// :
// 0000 blue is off
//
// Returns: nothing
// *************************************************************************************
void LCDSetPixel(int x, int y, int color)
{
  // Column address set (command 0x2A)
  WriteSpiCommand(PASET);
  WriteSpiData(x);
  WriteSpiData(x);

  // Row address set (command 0x2B)
  WriteSpiCommand(CASET);
  WriteSpiData(y);
  WriteSpiData(y);

  // Now illuminate the pixel (2nd pixel will be ignored)
  WriteSpiCommand(RAMWR);
  WriteSpiData((color >> 4) & 0xFF);
  WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
  WriteSpiData(color & 0xFF);
}

// *************************************************************************************************
// Draws a line in the specified color from (x0,y0) to (x1,y1)
//
// Inputs: x = row address (0 .. 131)
// y = column address (0 .. 131)
// color = 12-bit color value bbbbggggrrrr
// rrrr = 1111 full red
// :
// 0000 red is off
//
// gggg = 1111 full green
// :
// 0000 green is off
//
// bbbb = 1111 full blue
// :
// 0000 blue is off
//
// Returns: nothing
// ************************************************************************************************
void LCDSetLine(int x0, int y0, int x1, int y1, int color)
{

  int dy = y1 - y0;
  int dx = x1 - x0;
  int stepx, stepy;

  if (dy < 0)
  {
    dy = -dy;
    stepy = -1;
  }
  else
  {
    stepy = 1;
  }
  if (dx < 0)
  {
    dx = -dx;
    stepx = -1;
  }
  else
  {
    stepx = 1;
  }
  dy <<= 1; // dy is now 2*dy
  dx <<= 1; // dx is now 2*dx

  LCDSetPixel(x0, y0, color);
  if (dx > dy)
  {
    int fraction = dy - (dx >> 1); // same as 2*dy - dx
    while (x0 != x1)
    {
      if (fraction >= 0)
      {
        y0 += stepy;
        fraction -= dx; // same as fraction -= 2*dx
      }
      x0 += stepx;
      fraction += dy; // same as fraction -= 2*dy
      LCDSetPixel(x0, y0, color);
    }
  }
  else
  {
    int fraction = dx - (dy >> 1);
    while (y0 != y1)
    {
      if (fraction >= 0)
      {
        x0 += stepx;
        fraction -= dy;
      }
      y0 += stepy;
      fraction += dx;
      LCDSetPixel(x0, y0, color);
    }
  }
}

// *****************************************************************************************
// Draws a rectangle in the specified color from (x1,y1) to (x2,y2)
// Rectangle can be filled with a color if desired
//
// Inputs: x = row address (0 .. 131)
// y = column address (0 .. 131)
// fill = 0=no fill, 1-fill entire rectangle
// color = 12-bit color value for lines bbbbggggrrrr
// rrrr = 1111 full red
// :
// 0000 red is off
//
// gggg = 1111 full green
// :
// 0000 green is off
//
// bbbb = 1111 full blue
// :
// 0000 blue is off
//
// Returns: nothing
//
// Notes:
//
// The best way to fill a rectangle is to take advantage of the "wrap-around" featute
// built into the Epson S1D15G00 controller. By defining a drawing box, the memory can
// be simply filled by successive memory writes until all pixels have been illuminated.
//
// 1. Given the coordinates of two opposing corners (x0, y0) (x1, y1)
// calculate the minimums and maximums of the coordinates
//
// xmin = (x0 <= x1) ? x0 : x1;
// xmax = (x0 > x1) ? x0 : x1;
// ymin = (y0 <= y1) ? y0 : y1;
// ymax = (y0 > y1) ? y0 : y1;
//
// 2. Now set up the drawing box to be the desired rectangle
//
// WriteSpiCommand(PASET); // set the row boundaries
// WriteSpiData(xmin);
// WriteSpiData(xmax);
// WriteSpiCommand(CASET); // set the column boundaries
// WriteSpiData(ymin);
// WriteSpiData(ymax);
//*****************************************************************************************
void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color)
{
  int xmin, xmax, ymin, ymax;
  int i;

  // check if the rectangle is to be filled
  if (fill == FILL)
  {

    // best way to create a filled rectangle is to define a drawing box
    // and loop two pixels at a time

    // calculate the min and max for x and y directions
    xmin = (x0 <= x1) ? x0 : x1;
    xmax = (x0 > x1) ? x0 : x1;
    ymin = (y0 <= y1) ? y0 : y1;
    ymax = (y0 > y1) ? y0 : y1;

    // specify the controller drawing box according to those limits
    // Column address set (command 0x2A)
    WriteSpiCommand(CASET);
    WriteSpiData(xmin);
    WriteSpiData(xmax);

    // Row address set (command 0x2B)
    WriteSpiCommand(PASET);
    WriteSpiData(ymin);
    WriteSpiData(ymax);

    // WRITE MEMORY
    WriteSpiCommand(RAMWR);

    // loop on total number of pixels / 2
    for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 130); i++)
    {

      // use the color value to output three data bytes covering two pixels
      WriteSpiData((color >> 4) & 0xFF);
      WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
      WriteSpiData(color & 0xFF);
    }
  }
  else
  {
    // best way to draw un unfilled rectangle is to draw four lines
    LCDSetLine(x0, y0, x1, y0, color);
    LCDSetLine(x0, y1, x1, y1, color);
    LCDSetLine(x0, y0, x0, y1, color);
    LCDSetLine(x1, y0, x1, y1, color);
  }
}

// *************************************************************************************
// LCDSetCircle.c
//
// Draws a line in the specified color at center (x0,y0) with radius
//
// Inputs: x0 = row address (0 .. 131)
// y0 = column address (0 .. 131)
// radius = radius in pixels
// color = 12-bit color value bbbbggggrrrr
//
// Returns: nothing
//
// Author: Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
//
// Note: taken verbatim Wikipedia article on Bresenham's line algorithm
// http://www.wikipedia.org
//
// *************************************************************************************

void LCDSetCircle(int x0, int y0, int radius, int color, int fill)
{
  int f = 1 - radius;
  int ddF_x = 0;
  int ddF_y = -2 * radius;
  int x = 0;
  int y = radius;

  LCDSetPixel(x0, y0 + radius, color);
  LCDSetPixel(x0, y0 - radius, color);
  LCDSetPixel(x0 + radius, y0, color);
  LCDSetPixel(x0 - radius, y0, color);

  while (x < y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x + 1;

    if (fill != 0)
    {
      LCDSetLine(x0 - x, y0 + y, x0 + x, y0 + y, color);
      LCDSetLine(x0 - x, y0 - y, x0 + x, y0 - y, color);
      LCDSetLine(x0 - y, y0 + x, x0 + y, y0 + x, color);
      LCDSetLine(x0 - y, y0 - x, x0 + y, y0 - x, color);
    }
    else
    {
      LCDSetPixel(x0 + x, y0 + y, color);
      LCDSetPixel(x0 - x, y0 + y, color);
      LCDSetPixel(x0 + x, y0 - y, color);
      LCDSetPixel(x0 - x, y0 - y, color);
      LCDSetPixel(x0 + y, y0 + x, color);
      LCDSetPixel(x0 - y, y0 + x, color);
      LCDSetPixel(x0 + y, y0 - x, color);
      LCDSetPixel(x0 - y, y0 - x, color);
    }
  }
}

//@VD:
void LCDPutChar(int addressOfChar, int x, int y, int fontType, int fColor, int bColor, int transparentMode)
{
  char *font = (fontType == SMALL) ? FONT6x8 : (fontType == MEDIUM) ? FONT8x8
                                           : (fontType == LARGE)    ? FONT8x16
                                                                    : FontCustom; // 0x06, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,  // columns, rows, num_bytes_per_char
  int fontWidth = font[0];
  int fontHeight = font[1];
  int byteSize = font[2];
  int charOffset = byteSize * (addressOfChar - ' ' + 1);
  int color = 0;
  volatile char temp = 1;
  if (fontType == CUSTOM)
  {
    charOffset = byteSize * (addressOfChar + 1) - 1;
    for (int i = 0; i < fontHeight; i++)
    {
      int charByte = font[charOffset + i + 1];
      for (int j = fontWidth; j > 0; j--)
      {
        if (charByte & (1 << (fontWidth - j)))
          color = fColor;
        else
          color = bColor;
        if (transparentMode == OPAQUE)
        {
          LCDSetPixel(x + i, y + j, color);
        }
        else if (transparentMode == TRANSPARENTTEXT)
        {
          if (color == bColor)
            LCDSetPixel(x + i, y + j, color);
        }
        else if (transparentMode == TRANSPARENTBG)
        {
          if (color == fColor)
            LCDSetPixel(x + i, y + j, color);
        }
      }
    }
  }
  else
  {
    for (int i = 0; i < fontHeight; i++)
    {
      int charByte = font[charOffset + fontHeight - i];
      for (int j = 0; j < fontWidth; j++)
      {
        if(fontType == SMALL) temp = -2;
        if (charByte & (1 << (fontWidth - j - temp)))
          color = fColor;
        else
          color = bColor;
        if (transparentMode == OPAQUE)
        {
          LCDSetPixel(x + i, y + j, color);
        }
        else if (transparentMode == TRANSPARENTTEXT)
        {
          if (color == bColor)
            LCDSetPixel(x + i, y + j, color);
        }
        else if (transparentMode == TRANSPARENTBG)
        {
          if (color == fColor)
            LCDSetPixel(x + i, y + j, color);
        }
        temp = 1;
      }
    }
  }
}

//
// *************************************************************************************************
// Draws a null-terminates character string at the specified (x,y) address, size, color, transparecy
//
// Inputs: pString = pointer to character string to be displayed
// x = row address (0 .. 131)
// y = column address (0 .. 131)
// Size = font pitch (SMALL, MEDIUM, LARGE, CUSTOM)
// fColor = 12-bit foreground color value bbbbggggrrrr
// bColor = 12-bit background color value bbbbggggrrrr
// transparentMode = OPAQUE, TRANSPARENTTEXT, TRANSPARENTBG
//
//
// Returns: nothing
//
// Notes: Here's an example to display "Hello World!" at address (20,20)
//
// LCDPutChar("Hello World!", 20, 20, LARGE, WHITE, BLACK, OPAQUE);
// *************************************************************************************************
void LCDPutStr(char *pString, int x, int y, int Size, int fColor, int bColor, int transparentMode)
{
  // loop until null-terminator is seen
  while (*pString != 0x00)
  {
    // draw the character
    LCDPutChar(*pString++, x, y, Size, fColor, bColor, transparentMode);

    // advance the y position
    if (Size == SMALL)
      y = y + 6;
    else if (Size == MEDIUM || Size == LARGE)
      y = y + 8;
    else if (Size == CUSTOM)
      y = y + 16;

    // bail out if y exceeds 131
    if (y > 131)
      break;
  }
}
