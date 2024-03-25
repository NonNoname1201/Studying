
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -10.01 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <targets\AT91SAM7.h>

                                                               ZAD1
                                                                   // Jaki jest najdłuższy możliwy okres wyznaczany pomiędzy kolejnymi inkrementacjami sumatora PICNT timera PIT przy MCK = 16MHz
                                                                   // 2^20 czyli 1 048 576
                                                                   // T = (PIT_VALUE-1)/(MCK/16)
                                                                   // MCK/16 = 16000000/16 = 1000000
                                                                   // T = 1048576 / 1000000 = 1,048576s

                                                                   ZAD2
                                                               // 2^20 = 1048576
                                                               // MCK= 16MHz
                                                               //(PIT_VALUE - 1) / ( MCK / 16) = T
                                                               //  T = 1048576 / 1000000 = 1,048576s
                                                               // zadanie 2
                                                               //(PIT_VALUE - 1) / ( MCK / 16) = t
                                                               // MCK = 48MHz / 16 = 3MHz
                                                               // T = 5s
                                                               //(PIT_VALUE - 1) / 3000000 = 0.1s
                                                               //(PIT_VALUE - 1) = 300 000
                                                               // PIT_VALUE = 299 999
                                                               //
                                                               // RC=tf=5s*3MHz=15 000 000, jest to jednak wartość przekraczająca dopuszczającą, dlatego będziemy odliczać 15 przepełnień -> 15 inkrementacji w sumatorze PICNT, stąd
                                                               // RC=1000000, wówczas t=1/3s i przy 15 przepełnieniach zostanie odliczony czas ~5s

                                                               int
                                                               main()
{

    // konfiguracja lcd

    PMC_PCER = 1 << 3;
    PIOB_PER = 1 << 20;
    PIOB_OER = 1 << 20;
    PIOB_OWER = 1 << 20;

    PIT_PIVR;                   // wyczyszczenie zgłoszenia przerwania
    PIT_MR = 1000000 | 1 << 24; // ustawienie wartosci PIV oraz ustawienie bitu PITEN - zgoda na przerwanie PIT
    // musi wystąpić 15 przepełnień, aby nastąpilo odliczenie ~5s
    while (1)
    {
        if (PIT_PIIR >= (15 << 20))
        {                         // sprawdza, czy przepełnienie nastąpiło 15 razy
            PIT_PIVR;             // wyczyszczenie zgłoszenia przerwania - odlicza zgłoszenia od nowa
            PIOB_ODSR ^= 1 << 20; // odwrócenie stanu LCD
        }
    }
    return 0;
}

ZAD3
    // Jaka jest najniższa częstotliwośd możliwa do odliczenia przez kolejne przepełnienia timera TC0 układu Atmel SAM7X256 przy MCK = 128 MHz.

    // MCK = 128 MHz = 128 000 000 Hz
    // f = MCK / TIMER_CLOCK * RC
    // TIMER_CLOCK = (2^16)-1 = 65535
    // RC = 1024, ponież używamy TIMER_CLOCK5, który ma największy dzielnik
    // f = 128000000 / 65535*1024
    // f = 128 000 000 / 67 107 840
    // f = 1,90737773708 Hz = 0,52428 s

    ZAD4
        // Czy do zrealizowania przykładu 2 dot. Timer Counter 0 możliwe jest wykorzystanie innego dzielnika
        // częstotliwości niż MCK/1024 (TIMER_COUNTER5)?

        // częstotliwość obliczamy z wzoru
        // f=MCK/(TIMER_CLOCK*RC), zatem czas t=(TIMER_CLOCK*RC)/MCK
        // do odliczenia jest t=1s, MCK=64MHz, czyli

        // 1s=(TIMER_CLOCK*RC)/64MHz
        // TIMER_CLOCK*RC=64000000
        // wiadomo, że RCmax=65535, zatem aby sprawdzić, czy można użyć innego (mniejszego) dzielnika częstotliwości podstawiam tę wartość za RC
        // TIMER_CLOCK*65535=64000000
        // TIMER_CLOCK=977 (w przybliżeniu)
        // taki dzielnik częstotliwości nie istnieje, mniejszy niż 1024 dzielnik to dopiero 128, a wartość RC nie może być już większa
        // Nie jest zatem możliwe wykorzystanie innego dzielnika częstotliwości, niż MCK/1024.

        ZAD5 int
        main()
{
    PMC_PCER = 1 << 3 | 1 << 12; // zasilanie do LCD i TC0
    PIOB_PER = 1 << 20;
    PIOB_OER = 1 << 20;
    PIOB_OWER = 1 << 20;

    TC0_CCR = 1 << 1;
    TC0_SR;                    // wyzerowanie ewentualnie ustawionych flag
    TC0_CMR = 1 << 1 | 1 << 0; // timer_clock4->MCK/128, gdyby dać jeszcze 1<<14, to zgodność porównania resetuje zliczanie i wtedy w ifie nie 1<<0 tylko 1<<4
    TC0_RC = 37500;            // 48MHz/(128*10Hz)
    TC0_CCR = 1 << 0 | 1 << 2; // uruchomienie zegara timera
    while (1)
    {
        if ((TC0_SR & 1 << 0) != 0)
        {                           // jest ustawione 1 na bicie COVFS - nastąpiło przepełnienie od ostatiego odczytu; odczyt programowy powoduje reset wartości TC0_SR
            PIOB_ODSR ^= (1 << 20); // odwrócenie stanu wyświetlacza
        }
    }

    return 0;
}

ZAD5 - alternatyne(prawdopodobnie poprawne) int main()
{
    PMC_PCER = 1 << 3 | 1 << 12; // zasilanie do LCD i TC0
    PIOB_PER = 1 << 20;
    PIOB_OER = 1 << 20;
    PIOB_OWER = 1 << 20;

    TC0_CCR = 1 << 1;
    TC0_SR;                                // wyzerowanie ewentualnie ustawionych flag
    TC0_CMR = (1 << 14) | 1 << 1 | 1 << 0; // timer_clock4->MCK/128, gdyby dać jeszcze 1<<14, to zgodność porównania resetuje zliczanie i wtedy w ifie nie 1<<0 tylko 1<<4
    TC0_RC = 37500;                        // 48MHz/(128*10Hz)
    TC0_CCR = 1 << 0 | 1 << 2;             // uruchomienie zegara timera
    while (1)
    {
        if ((TC0_SR & 1 << 4) != 0)
        {                           // jest ustawione 1 na bicie COVFS - nastąpiło przepełnienie od ostatiego odczytu; odczyt programowy powoduje reset wartości TC0_SR
            PIOB_ODSR ^= (1 << 20); // odwrócenie stanu wyświetlacza
        }
    }

    return 0;
}

-- -- -- -- -- -- -- -- -- -- -kod na zajecia 06.12 -- -- - - - - - - - - - - -
                              // Z1
                              // podmienic w lcd.c definicje w lcd.h

                              int
                              LCDPutStr(char *pString, int x, int y, int Size, int fColor, int bColor)
{
    // Czyszczenie obszaru
    // LCDClearArea(x, y, strlen(pString), Size);

    // Rysowanie tekstu
    int dy = y;
    while (*pString != 0x00)
    {
        LCDPutChar(*pString++, x, dy, Size, fColor, bColor);
        dy += (Size == SMALL) ? 6 : 8;
        if (dy > 131)
            return dy;
    }
    return dy - y;
}

#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"
#define LCD_BL (1 << 19)
#define AUDIO_OUT (1 << 20)

void delay(int n) __attribute__((section(".fast")));

void delay(int n)
{
    volatile int i;
    for (i = 3000 * n; i > 0; i--)
    {
        __asm__("nop");
    }
}
void clearLCD(int length, int x, int y, int size, int bgcolor)
{
    long i;
    int width, height;

    if (size == SMALL)
    {
        width = 6 * length;
        height = 8;
    }
    else if (size == MEDIUM)
    {
        width = 8 * length;
        height = 12;
    }
    else
    {
        width = 8 * length;
        height = 16;
    }

    WriteSpiCommand(PASET);
    WriteSpiData(y);
    WriteSpiData(y + height - 1);

    WriteSpiCommand(CASET);
    WriteSpiData(x);
    WriteSpiData(x + width - 1);

    WriteSpiCommand(RAMWR);
    for (i = 0; i < (width * height); i++)
    {
        // przesłanie Red Green jako tło
        WriteSpiData((bgcolor >> 4) & 0xFF);
        // Przesłanie Blue Red jako tlo
        WriteSpiData(((bgcolor & 0xF) << 4) | ((bgcolor >> 8) & 0xF));
        // Przeslanie Green Blue jako kolor czcionki
        WriteSpiData(bgcolor & 0xFF);
    }
}
int main()
{
    PMC_PCER = PMC_PCER_PIOB;      // wlaczenie urzadzenia we/wy PIOB
    PIOB_OER = LCD_BL | AUDIO_OUT; // OUTPUT ENABLE
    PIOB_PER = LCD_BL | AUDIO_OUT; // PIO ENABLE
    InitLCD();                     // inicjalizacja LCD
    LCDSettings();                 // ustawienie LCD
    LCDClearScreen();              // LCDWrite130x130bmp(); //wyswietlenie BMP (zdef w pliku bmp.h)
    char *imie = "IMIE";
    char *nazwisko = "NAZWISKO";
    LCDPutStr(imie, 20, 15, SMALL, BLACK, WHITE);
    LCDPutStr(nazwisko, 30, 30, SMALL, BLACK, WHITE);
    // LCDPutStr("IMIE NAZWISKO",20,15, SMALL, BLACK, WHITE);
    //  LCDPutStr("GL02",50,50,LARGE,BLACK,WHITE);
    clearLCD(9, 15, 20, SMALL, GREEN);
    while (1)
    {
    }
    return 0;
}
- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -kod na zajecia 29.11 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// LAB 7 zad 7.1

#include <targets/AT91SAM7.h>
#include "pcf8833u8_lcd.h"
#define LCD_BACKLIGHT PIOB_SODR_P20
#define AUDIO_OUT PIOB_SODR_P19
#define SW_1 PIOB_SODR_P24
#define SW_2 PIOB_SODR_P25
#define JOY_UP PIOA_SODR_P9
#define JOY_ENTER PIOA_SODR_P15
#define JOY_LEFT PIOA_SODR_P7
#define JOY_DOWN PIOA_SODR_P8
#define JOY_RIGHT PIOA_SODR_P14

    __attribute__((section(".fast")))void
    delay(int n) // procedura opoznienia
{
    volatile int i;

    for (i = 3000 * n; i > 0; i--)
    {
        __asm__("nop");
    }
}

int main()
{
    PMC_PCER = PMC_PCER_PIOB; // wlaczenie urzadzenia we/wy PIOB
    PMC_PCER = PMC_PCER_PIOA;
    PIOB_OER = LCD_BACKLIGHT | AUDIO_OUT; // OUTPUT ENABLE
    PIOB_PER = LCD_BACKLIGHT | AUDIO_OUT; // PIO ENABLE

    InitLCD();     // inicjalizacja LCD
    LCDSettings(); // ustawienie LCD
    LCDClearScreen();
    LCDWrite130x130bmp(); // wyswietlenie BMP (zdef w pliku bmp.h)

    while (1)
    {

        if ((PIOA_PDSR & JOY_UP) == 0)
        {
            LCDPutStr("UP", 10, 55, MEDIUM, BLACK, GREEN);
        }
        if ((PIOA_PDSR & JOY_LEFT) == 0)
        {
            LCDPutStr("LEFT", 60, 7, MEDIUM, BLACK, GREEN);
        }
        if ((PIOA_PDSR & JOY_RIGHT) == 0)
        {
            LCDPutStr("RIGHT", 60, 90, MEDIUM, BLACK, GREEN);
        }
        if ((PIOA_PDSR & JOY_DOWN) == 0)
        {
            LCDPutStr("DOWN", 120, 45, MEDIUM, BLACK, GREEN);
        }
        if ((PIOA_PDSR & JOY_ENTER) == 0)
        {
            LCDPutStr("ENTER", 55, 45, MEDIUM, BLACK, GREEN);
        }
        if ((PIOB_PDSR & SW_1) == 0)
        {
            LCDPutStr("SW1", 120, 13, MEDIUM, BLACK, GREEN);
        }
        if ((PIOB_PDSR & SW_2) == 0)
        {
            LCDPutStr("SW2", 120, 98, MEDIUM, BLACK, GREEN);
        }
    }
    return 0;
}

// LAB8 zad 8.1
#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"

#define LCD_BACKLIGHT PIOB_SODR_P20
#define AUDIO_OUT PIOB_SODR_P19
#define SW_1 PIOB_SODR_P24
#define SW_2 PIOB_SODR_P25
#define JOY_UP PIOA_SODR_P9
#define JOY_ENTER PIOA_SODR_P15
#define JOY_LEFT PIOA_SODR_P7
#define JOY_DOWN PIOA_SODR_P8
#define JOY_RIGHT PIOA_SODR_P14

// Inicjalizacja zmiennych pozycji i koloru
int x = 60, y = 60;
char displayChar = 'O';      // Znak do wyświetlenia
int backgroundColor = BLACK; // Kolor tła

void delay(int n) __attribute__((section(".fast")));
void delay(int n)
{
    volatile int i;
    for (i = 3000 * n; i > 0; i--)
    {
        __asm__("nop");
    }
}

void drawChar()
{
    LCDClearScreen();
    LCDPutChar(displayChar, x, y, MEDIUM, WHITE, BLACK);
}

void wrapAround()
{
    if (x < 0)
        x = 130;
    else if (x > 130)
        x = 0;
    else if (y > 130)
        y = 0;
    else if (y < 0)
        y = 130;
}

int main()
{
    PMC_PCER = PMC_PCER_PIOA | PMC_PCER_PIOB;
    PIOB_OER = LCD_BACKLIGHT | AUDIO_OUT;
    PIOB_PER = LCD_BACKLIGHT | AUDIO_OUT;
    InitLCD();
    LCDSettings();
    LCDClearScreen();
    drawChar(); // Wyświetl początkowy znak na środku

    while (1)
    {
        wrapAround();
        // Obsługa joysticka
        if ((PIOA_PDSR & JOY_LEFT) == 0)
            y -= 5;
        if ((PIOA_PDSR & JOY_RIGHT) == 0)
            y += 5;
        if ((PIOA_PDSR & JOY_DOWN) == 0)
            x += 5;
        if ((PIOA_PDSR & JOY_UP) == 0)
            x -= 5;

        // Obsługa przełączników
        if ((PIOB_PDSR & SW_1) == 0)
            displayChar = (displayChar == 'Z') ? 'A' : displayChar + 1;
        if ((PIOB_PDSR & SW_2) == 0)
            backgroundColor = (backgroundColor == WHITE) ? BLACK : WHITE;

        // Reset pozycji
        if ((PIOA_PDSR & JOY_ENTER) == 0)
        {
            x = 60;
            y = 60;
        }

        drawChar();
        delay(100);
    }
    return 0;
}

DO FONTS.H const unsigned char FONT6x8[97][8] = {

    0x06, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,  // columns, rows, num_bytes_per_char
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // space 0x20
    0x00, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20,  // !
    0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50,  // "
    0x00, 0x50, 0x50, 0xF8, 0x50, 0xF8, 0x50, 0x50,  // #
    0x00, 0x20, 0xF0, 0x28, 0x70, 0xA0, 0x78, 0x20,  // $
    0x00, 0x18, 0x98, 0x40, 0x20, 0x10, 0xC8, 0xC0,  // %
    0x00, 0x68, 0x90, 0xA8, 0x40, 0xA0, 0xA0, 0x40,  // &
    0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x30, 0x30,  // '
    0x00, 0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10,  // (
    0x00, 0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40,  // )
    0x00, 0x20, 0xA8, 0x70, 0x70, 0xA8, 0x20, 0x00,  // *
    0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00,  // +
    0x40, 0x20, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,  //
    0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,  // -
    0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,  // .
    0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00,  // / (forward slash)
    0x00, 0x70, 0x88, 0x88, 0xA8, 0x88, 0x88, 0x70,  // 0 0x30
    0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x60, 0x20,  // 1
    0x00, 0xF8, 0x80, 0x80, 0x70, 0x08, 0x88, 0x70,  // 2
    0x00, 0x70, 0x88, 0x08, 0x30, 0x10, 0x08, 0xF8,  // 3
    0x00, 0x10, 0x10, 0xF8, 0x90, 0x50, 0x30, 0x10,  // 4
    0x00, 0x70, 0x88, 0x08, 0x08, 0xF0, 0x80, 0xF8,  // 5
    0x00, 0x70, 0x88, 0x88, 0xF0, 0x80, 0x40, 0x38,  // 6
    0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x08, 0xF8,  // 7
    0x00, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70,  // 8
    0x00, 0xE0, 0x10, 0x08, 0x78, 0x88, 0x88, 0x70,  // 9
    0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00,  // :
    0x00, 0x40, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00,  // ;
    0x00, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08,  // <
    0x00, 0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00,  // =
    0x00, 0x40, 0x20, 0x10, 0x08, 0x10, 0x20, 0x40,  // >
    0x00, 0x20, 0x00, 0x20, 0x30, 0x08, 0x88, 0x70,  // ?
    0x00, 0x78, 0x80, 0xB0, 0xB8, 0xA8, 0x88, 0x70,  // @ 0x40
    0x00, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x50, 0x20,  // A
    0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0,  // B
    0x00, 0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70,  // C
    0x00, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0,  // D
    0x00, 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8,  // E
    0x00, 0x80, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8,  // F
    0x00, 0x78, 0x88, 0x98, 0x80, 0x80, 0x88, 0x78,  // G
    0x00, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88,  // H
    0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70,  // I
    0x00, 0x60, 0x90, 0x10, 0x10, 0x10, 0x10, 0x38,  // J
    0x00, 0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88,  // K
    0x00, 0xF8, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,  // L
    0x00, 0x88, 0x88, 0xA8, 0xA8, 0xA8, 0xD8, 0x88,  // M
    0x00, 0x88, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x88,  // N
    0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70,  // O
    0x00, 0x80, 0x80, 0x80, 0xF0, 0x88, 0x88, 0xF0,  // P 0x50
    0x00, 0x68, 0x90, 0xA8, 0x88, 0x88, 0x88, 0x70,  // Q
    0x00, 0x88, 0x90, 0xA0, 0xF0, 0x88, 0x88, 0xF0,  // R
    0x00, 0x70, 0x88, 0x08, 0x70, 0x80, 0x88, 0x70,  // S
    0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0xA8, 0xF8,  // T
    0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,  // U
    0x00, 0x20, 0x50, 0x88, 0x88, 0x88, 0x88, 0x88,  // V
    0x00, 0x50, 0xA8, 0xA8, 0xA8, 0x88, 0x88, 0x88,  // W
    0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88,  // X
    0x00, 0x20, 0x20, 0x20, 0x20, 0x50, 0x88, 0x88,  // Y
    0x00, 0xF8, 0x80, 0x40, 0x70, 0x10, 0x08, 0xF8,  // Z
    0x00, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x78,  // [
    0x00, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,  // \ (back slash)
    0x00, 0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x78,  // ]
    0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x50, 0x20,  // ^
    0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // _
    0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x60, 0x60,  // ` 0x60
    0x00, 0x78, 0x90, 0x70, 0x10, 0x60, 0x00, 0x00,  // a
    0x00, 0xB0, 0xC8, 0x88, 0xC8, 0xB0, 0x80, 0x80,  // b
    0x00, 0x70, 0x88, 0x80, 0x88, 0x70, 0x00, 0x00,  // c
    0x00, 0x68, 0x98, 0x88, 0x98, 0x68, 0x08, 0x08,  // d
    0x00, 0x70, 0x80, 0xF8, 0x88, 0x70, 0x00, 0x00,  // e
    0x00, 0x20, 0x20, 0x20, 0x70, 0x20, 0x28, 0x10,  // f
    0x70, 0x08, 0x68, 0x98, 0x98, 0x70, 0x00, 0x00,  // g
    0x00, 0x88, 0x88, 0x88, 0xC8, 0xB0, 0x80, 0x80,  // h
    0x00, 0x70, 0x20, 0x20, 0x20, 0x60, 0x00, 0x20,  // i
    0x00, 0x60, 0x90, 0x10, 0x10, 0x10, 0x00, 0x10,  // j
    0x00, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x80, 0x80,  // k
    0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x60,  // l
    0x00, 0xA8, 0xA8, 0xA8, 0xA8, 0xD0, 0x00, 0x00,  // m
    0x00, 0x88, 0x88, 0x88, 0xC8, 0xB0, 0x00, 0x00,  // n
    0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,  // o
    0x80, 0x80, 0xB0, 0xC8, 0xC8, 0xB0, 0x00, 0x00,  // p 0x70
    0x08, 0x08, 0x68, 0x98, 0x98, 0x68, 0x00, 0x00,  // q
    0x00, 0x80, 0x80, 0x80, 0xC8, 0xB0, 0x00, 0x00,  // r
    0x00, 0xF0, 0x08, 0x70, 0x80, 0x78, 0x00, 0x00,  // s
    0x00, 0x10, 0x28, 0x20, 0x20, 0xF8, 0x20, 0x20,  // t
    0x00, 0x68, 0x98, 0x88, 0x88, 0x88, 0x00, 0x00,  // u
    0x00, 0x20, 0x50, 0x88, 0x88, 0x88, 0x00, 0x00,  // v
    0x00, 0x50, 0xA8, 0xA8, 0x88, 0x88, 0x00, 0x00,  // w
    0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00,  // x
    0x70, 0x88, 0x08, 0x78, 0x88, 0x88, 0x00, 0x00,  // y
    0x00, 0xF8, 0x40, 0x20, 0x10, 0xF8, 0x00, 0x00,  // z
    0x00, 0x10, 0x20, 0x20, 0x40, 0x20, 0x20, 0x10,  // {
    0x00, 0x20, 0x20, 0x20, 0x00, 0x20, 0x20, 0x20,  // |
    0x00, 0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x40,  // }
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xA8, 0x40,  // ~
    0x00, 0x00, 0x00, 0x00, 0x70, 0xD8, 0xD8, 0x70}; // DEL

const unsigned char FONT8x8[97][8] = {

    0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, // columns
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // space 0x20
    0x00, 0x30, 0x00, 0x30, 0x30, 0x78, 0x78, 0x30, // !
    0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x6C, 0x6C, // "
    0x00, 0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, // #
    0x00, 0x18, 0x7C, 0x06, 0x3C, 0x60, 0x3E, 0x18, // $
    0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00, // %
    0x00, 0x3B, 0x66, 0x6E, 0x3B, 0x1C, 0x36, 0x1C, // &
    0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x30, // '
    0x00, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0C, // (
    0x00, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x18, 0x30, // )
    0x00, 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, // *
    0x00, 0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, // +
    0x30, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, // -
    0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, // .
    0x00, 0x40, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, // / (forward slash)
    0x00, 0x3E, 0x63, 0x63, 0x6B, 0x63, 0x63, 0x3E, // 0 0x30
    0x00, 0x7E, 0x18, 0x18, 0x18, 0x58, 0x38, 0x18, // 1
    0x00, 0x7E, 0x66, 0x30, 0x1C, 0x06, 0x66, 0x3C, // 2
    0x00, 0x3C, 0x66, 0x06, 0x1C, 0x06, 0x66, 0x3C, // 3
    0x00, 0x0F, 0x06, 0x7F, 0x66, 0x36, 0x1E, 0x0E, // 4
    0x00, 0x3C, 0x66, 0x06, 0x06, 0x7C, 0x60, 0x7E, // 5
    0x00, 0x3C, 0x66, 0x66, 0x7C, 0x60, 0x30, 0x1C, // 6
    0x00, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x66, 0x7E, // 7
    0x00, 0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x3C, // 8
    0x00, 0x38, 0x0C, 0x06, 0x3E, 0x66, 0x66, 0x3C, // 9
    0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, // :
    0x30, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, // ;
    0x00, 0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, // <
    0x00, 0x00, 0x7E, 0x00, 0x00, 0x7E, 0x00, 0x00, // =
    0x00, 0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, // >
    0x00, 0x18, 0x00, 0x18, 0x0C, 0x06, 0x66, 0x3C, // ?
    0x00, 0x3E, 0x60, 0x6F, 0x69, 0x6F, 0x63, 0x3E, // @ 0x40
    0x00, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x3C, 0x18, // A
    0x00, 0x7E, 0x33, 0x33, 0x3E, 0x33, 0x33, 0x7E, // B
    0x00, 0x1E, 0x33, 0x60, 0x60, 0x60, 0x33, 0x1E, // C
    0x00, 0x7C, 0x36, 0x33, 0x33, 0x33, 0x36, 0x7C, // D
    0x00, 0x7F, 0x31, 0x34, 0x3C, 0x34, 0x31, 0x7F, // E
    0x00, 0x78, 0x30, 0x34, 0x3C, 0x34, 0x31, 0x7F, // F
    0x00, 0x1F, 0x33, 0x67, 0x60, 0x60, 0x33, 0x1E, // G
    0x00, 0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, // H
    0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, // I
    0x00, 0x3C, 0x66, 0x66, 0x06, 0x06, 0x06, 0x0F, // J
    0x00, 0x73, 0x33, 0x36, 0x3C, 0x36, 0x33, 0x73, // K
    0x00, 0x7F, 0x33, 0x31, 0x30, 0x30, 0x30, 0x78, // L
    0x00, 0x63, 0x63, 0x6B, 0x7F, 0x7F, 0x77, 0x63, // M
    0x00, 0x63, 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, // N
    0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3E, // O
    0x00, 0x78, 0x30, 0x30, 0x3E, 0x33, 0x33, 0x7E, // P 0x50
    0x00, 0x0E, 0x3C, 0x6E, 0x66, 0x66, 0x66, 0x3C, // Q
    0x00, 0x73, 0x33, 0x36, 0x3E, 0x33, 0x33, 0x7E, // R
    0x00, 0x3C, 0x66, 0x0C, 0x18, 0x30, 0x66, 0x3C, // S
    0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x5A, 0x7E, // T
    0x00, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, // U
    0x00, 0x18, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, // V
    0x00, 0x63, 0x77, 0x7F, 0x6B, 0x63, 0x63, 0x63, // W
    0x00, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x63, // X
    0x00, 0x3C, 0x18, 0x18, 0x3C, 0x66, 0x66, 0x66, // Y
    0x00, 0x7F, 0x33, 0x19, 0x0C, 0x46, 0x63, 0x7F, // Z
    0x00, 0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, // [
    0x00, 0x01, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, // \ (back slash)
    0x00, 0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, // ]
    0x00, 0x00, 0x00, 0x00, 0x63, 0x36, 0x1C, 0x08, // ^
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // _
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x18, // ` 0x60
    0x00, 0x3B, 0x66, 0x3E, 0x06, 0x3C, 0x00, 0x00, // a
    0x00, 0x6E, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x70, // b
    0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00, 0x00, // c
    0x00, 0x3B, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x0E, // d
    0x00, 0x3C, 0x60, 0x7E, 0x66, 0x3C, 0x00, 0x00, // e
    0x00, 0x78, 0x30, 0x30, 0x78, 0x30, 0x36, 0x1C, // f
    0x7C, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, // g
    0x00, 0x73, 0x33, 0x33, 0x3B, 0x36, 0x30, 0x70, // h
    0x00, 0x3C, 0x18, 0x18, 0x18, 0x38, 0x00, 0x18, // i
    0x3C, 0x66, 0x66, 0x06, 0x06, 0x06, 0x00, 0x06, // j
    0x00, 0x73, 0x36, 0x3C, 0x36, 0x33, 0x30, 0x70, // k
    0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x38, // l
    0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x66, 0x00, 0x00, // m
    0x00, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x00, 0x00, // n
    0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00, 0x00, // o
    0x78, 0x30, 0x3E, 0x33, 0x33, 0x6E, 0x00, 0x00, // p 0x70
    0x0F, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00, 0x00, // q
    0x00, 0x78, 0x30, 0x33, 0x3B, 0x6E, 0x00, 0x00, // r
    0x00, 0x7C, 0x06, 0x3C, 0x60, 0x3E, 0x00, 0x00, // s
    0x00, 0x0C, 0x1A, 0x18, 0x18, 0x3E, 0x18, 0x08, // t
    0x00, 0x3B, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // u
    0x00, 0x18, 0x3C, 0x66, 0x66, 0x66, 0x00, 0x00, // v
    0x00, 0x36, 0x7F, 0x7F, 0x6B, 0x63, 0x00, 0x00, // w
    0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00, 0x00, // x
    0x7C, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x00, 0x00, // y
    0x00, 0x7E, 0x32, 0x18, 0x4C, 0x7E, 0x00, 0x00, // z
    0x00, 0x0E, 0x18, 0x18, 0x70, 0x18, 0x18, 0x0E, // {
    0x00, 0x0C, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x0C, // |
    0x00, 0x70, 0x18, 0x18, 0x0E, 0x18, 0x18, 0x70, // }
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 0x3B, // ~
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x36, 0x36, 0x1C, // DEL
    0x00, 0x3B, 0x66, 0x3E, 0x06, 0x3C, 0x00, 0x00, // a
    0x00, 0x7F, 0x31, 0x34, 0x3C, 0x34, 0x31, 0x7F, // E
    0x0C, 0x3C, 0x60, 0x7E, 0x66, 0x3C, 0x00, 0x00, // e

};

const unsigned char FONT8x16[100][16] = {

    0x08, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // columns
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // space 0x20
    0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x3C, 0x3C, 0x3C, 0x18, 0x00, 0x00, // !
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x63, 0x63, 0x63, 0x00, // "
    0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x7F, 0x36, 0x36, 0x36, 0x7F, 0x36, 0x36, 0x00, 0x00, 0x00, // #
    0x00, 0x00, 0x0C, 0x0C, 0x3E, 0x63, 0x43, 0x03, 0x03, 0x3E, 0x60, 0x61, 0x63, 0x3E, 0x0C, 0x0C, // $
    0x00, 0x00, 0x00, 0x00, 0x63, 0x33, 0x18, 0x0C, 0x06, 0x63, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, // %
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x66, 0x66, 0x6E, 0x3B, 0x1C, 0x36, 0x36, 0x1C, 0x00, 0x00, 0x00, // &
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x30, 0x30, 0x00, // '
    0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x18, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x0C, 0x00, 0x00, // (
    0x00, 0x00, 0x00, 0x00, 0x18, 0x0C, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x0C, 0x0C, 0x18, 0x00, 0x00, // )
    0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x42, 0x00, 0x00, 0x00, 0x00, // *
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, // +
    0x00, 0x00, 0x30, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -
    0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00, // / (forward slash)
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x6B, 0x6B, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, // 0 0x30
    0x00, 0x00, 0x00, 0x00, 0x3F, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x1C, 0x0C, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x63, 0x61, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x63, 0x3E, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x03, 0x03, 0x03, 0x1E, 0x03, 0x03, 0x63, 0x3E, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x06, 0x06, 0x7F, 0x66, 0x66, 0x36, 0x1E, 0x0E, 0x06, 0x00, 0x00, // 4
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x73, 0x63, 0x03, 0x03, 0x7E, 0x60, 0x60, 0x60, 0x7F, 0x00, 0x00, // 5
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x7E, 0x60, 0x60, 0x30, 0x1C, 0x00, 0x00, // 6
    0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x06, 0x06, 0x03, 0x63, 0x7F, 0x00, 0x00, // 7
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, // 8
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x06, 0x03, 0x03, 0x3F, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, // 9
    0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, // :
    0x00, 0x00, 0x30, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, // ;
    0x00, 0x00, 0x00, 0x00, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x00, 0x00, 0x00, // <
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // =
    0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x00, 0x00, 0x00, // >
    0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0x06, 0x63, 0x63, 0x3E, 0x00, 0x00, // ?
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x60, 0x60, 0x6E, 0x6B, 0x6B, 0x6F, 0x63, 0x63, 0x3E, 0x00, 0x00, // @ 0x40
    0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x7F, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x08, 0x00, 0x00, // A
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x33, 0x33, 0x33, 0x33, 0x3E, 0x33, 0x33, 0x33, 0x7E, 0x00, 0x00, // B
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x33, 0x61, 0x60, 0x60, 0x60, 0x60, 0x61, 0x33, 0x1E, 0x00, 0x00, // C
    0x00, 0x00, 0x00, 0x00, 0x7C, 0x36, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x36, 0x7C, 0x00, 0x00, // D
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x31, 0x30, 0x34, 0x3C, 0x34, 0x31, 0x33, 0x7F, 0x00, 0x00, // E
    0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0x30, 0x30, 0x34, 0x3C, 0x34, 0x31, 0x33, 0x7F, 0x00, 0x00, // F
    0x00, 0x00, 0x00, 0x00, 0x1D, 0x37, 0x63, 0x63, 0x6F, 0x60, 0x60, 0x61, 0x33, 0x1E, 0x00, 0x00, // G
    0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x7F, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, // H
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, 0x00, // I
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x66, 0x66, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0F, 0x00, 0x00, // J
    0x00, 0x00, 0x00, 0x00, 0x73, 0x33, 0x33, 0x36, 0x36, 0x3C, 0x36, 0x36, 0x33, 0x73, 0x00, 0x00, // K
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, // L
    0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00, 0x00, // M
    0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x67, 0x6F, 0x7F, 0x7B, 0x73, 0x63, 0x63, 0x00, 0x00, // N
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x36, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00, 0x00, // O
    0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0x30, 0x30, 0x30, 0x3E, 0x33, 0x33, 0x33, 0x7E, 0x00, 0x00, // P 0x50
    0x00, 0x00, 0x07, 0x06, 0x3E, 0x6F, 0x6B, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, // Q
    0x00, 0x00, 0x00, 0x00, 0x73, 0x33, 0x33, 0x36, 0x36, 0x3E, 0x33, 0x33, 0x33, 0x7E, 0x00, 0x00, // R
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x03, 0x06, 0x1C, 0x30, 0x63, 0x63, 0x3E, 0x00, 0x00, // S
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x99, 0xDB, 0xFF, 0x00, 0x00, // T
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, // U
    0x00, 0x00, 0x00, 0x00, 0x08, 0x1C, 0x36, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, // V
    0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x7F, 0x6B, 0x6B, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, // W
    0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3, 0x66, 0x3C, 0x18, 0x18, 0x3C, 0x66, 0xC3, 0xC3, 0x00, 0x00, // X
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x66, 0xC3, 0xC3, 0xC3, 0x00, 0x00, // Y
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x63, 0x61, 0x30, 0x18, 0x0C, 0x06, 0x43, 0x63, 0x7F, 0x00, 0x00, // Z
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00, 0x00, // [
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00, // \ (back slash)
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00, 0x00, // ]
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x36, 0x1C, 0x08, // ^
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // _
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x18, // ` 0x60
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x46, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, // a
    0x00, 0x00, 0x00, 0x00, 0x6E, 0x33, 0x33, 0x33, 0x33, 0x36, 0x3C, 0x30, 0x30, 0x70, 0x00, 0x00, // b
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x60, 0x60, 0x60, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // c
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x66, 0x66, 0x66, 0x66, 0x36, 0x1E, 0x06, 0x06, 0x0E, 0x00, 0x00, // d
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x60, 0x7E, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // e
    0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0x30, 0x30, 0x30, 0x7C, 0x30, 0x32, 0x36, 0x1C, 0x00, 0x00, // f
    0x00, 0x00, 0x3C, 0x66, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, // g
    0x00, 0x00, 0x00, 0x00, 0x73, 0x33, 0x33, 0x33, 0x33, 0x3B, 0x36, 0x30, 0x30, 0x70, 0x00, 0x00, // h
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x00, 0x0C, 0x0C, 0x00, 0x00, // i
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x00, 0x06, 0x06, 0x00, 0x00, // j
    0x00, 0x00, 0x00, 0x00, 0x73, 0x33, 0x36, 0x3C, 0x36, 0x33, 0x33, 0x30, 0x30, 0x70, 0x00, 0x00, // k
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x00, 0x00, // l
    0x00, 0x00, 0x00, 0x00, 0x6B, 0x6B, 0x6B, 0x6B, 0x6B, 0x7F, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, // m
    0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, // n
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // o
    0x00, 0x00, 0x78, 0x30, 0x30, 0x3E, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, // p 0x70
    0x00, 0x00, 0x0F, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x66, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, // q
    0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0x30, 0x30, 0x33, 0x3B, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, // r
    0x00, 0x00, 0x00, 0x00, 0x3E, 0x63, 0x03, 0x0E, 0x38, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // s
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x1B, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x08, 0x00, 0x00, // t
    0x00, 0x00, 0x00, 0x00, 0x3B, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, // u
    0x00, 0x00, 0x00, 0x00, 0x08, 0x1C, 0x1C, 0x36, 0x36, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, // v
    0x00, 0x00, 0x00, 0x00, 0x36, 0x7F, 0x6B, 0x6B, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, // w
    0x00, 0x00, 0x00, 0x00, 0x63, 0x36, 0x1C, 0x1C, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, // x
    0x00, 0x00, 0x3C, 0x06, 0x03, 0x3F, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, // y
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x63, 0x30, 0x18, 0x0C, 0x66, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, // z
    0x00, 0x00, 0x00, 0x00, 0x0E, 0x18, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x18, 0x0E, 0x00, 0x00, // {
    0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // |
    0x00, 0x00, 0x00, 0x00, 0x70, 0x18, 0x18, 0x18, 0x18, 0x0E, 0x18, 0x18, 0x18, 0x70, 0x00, 0x00, // }
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 0x3B, 0x00, 0x00, // ~
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xD8, 0xD8, 0x70, 0x00, // DEL
    0x00, 0x07, 0x0C, 0x06, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x46, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, // ą
    0x00, 0x03, 0x04, 0x06, 0x7F, 0x33, 0x31, 0x30, 0x34, 0x3C, 0x34, 0x31, 0x33, 0x7F, 0x00, 0x00, // Ę
    0x00, 0x06, 0x08, 0x0C, 0x3E, 0x63, 0x60, 0x7E, 0x63, 0x63, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // ę
};

W MAIN
    LCDPutChar(128, 10, 10, LARGE, BLACK, WHITE);
LCDPutChar(129, 10, 30, LARGE, BLACK, WHITE);
LCDPutChar(130, 10, 50, LARGE, BLACK, WHITE);

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -kod na zajecia 22.11 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"

#define AUDIO_OUT PIOB_SODR_P19
#define SW_1 PIOB_SODR_P24
#define SW_2 PIOB_SODR_P25
#define LCD_BACKLIGHT PIOB_SODR_P20

                                                                                                                                                            void
                                                                                                                                                            delay(int n)
{
    volatile int i;
    for (i = 3000 * 1000 * n; i > 0; i--)
    {
        __asm__("nop");
    }
}

int main()
{

    PMC_PCER = PMC_PCER_PIOB;
    // Konfiguracja portu B jako wyjście
    PIOB_OER = LCD_BACKLIGHT | AUDIO_OUT; // OUTPUT ENABLE

    // Włączenie PIO (Peripheral Input/Output) dla wybranych pinów
    PIOB_PER = LCD_BACKLIGHT | AUDIO_OUT | SW_1 | SW_2; // PIO ENABLE

    InitLCD(); // Inicjalizacja ekranu LCD
    SetContrast(30);
    LCDClearScreen(); // Wyczyszczenie ekranu

    LCDPutStr("Im nazw", 15, 10, LARGE, BLACK, WHITE);    // WyĹ›wietlenie na LCD imienia i nazwiska
    LCDPutStr("Grupa: 5.4", 30, 30, LARGE, BLACK, WHITE); // WyĹ›wietlenie grupy w kolejnej linii

    LCDPutStr("Im nazw", 50, 10, MEDIUM, GREEN, BLACK);
    LCDPutStr("Grupa: 5.4", 70, 70, SMALL, YELLOW, BLUE);

    LCDPutStr("Im nazw", 90, 10, SMALL, GREEN, WHITE);
    LCDPutStr("Grupa: 5.4", 100, 50, LARGE, BLUE, YELLOW);

    delay(5); // opóźnienie 5 sekund

    /// LCDClearScreen(); // Wyczyszczenie ekranu
    // LCDWrite130x130bmp(); // WyĹ›wietlenie obrazu na LCD

    while (1)
    {
        if ((PIOB_PDSR & SW_2) == 0)
        {
            PIOB_SODR |= LCD_BACKLIGHT; // ustawienie 1
            PIOB_SODR |= AUDIO_OUT;
            delay(1);
            PIOB_CODR |= AUDIO_OUT;
            delay(1);
        }
        if ((PIOB_PDSR & SW_1) == 0)
        {
            PIOB_CODR |= LCD_BACKLIGHT; // ustawienie 0
            PIOB_SODR |= AUDIO_OUT;
            delay(1);
            PIOB_CODR |= AUDIO_OUT;
            delay(1);
        }
    }
    return 0;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -kod na zajecia 08.11 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -ZAD 1 Z LAB 4 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <avr/io.h>                                             //Importowanie biblioteki AVR
#include <avr/interrupt.h>                                      //Importowanie biblioteki do obs ugi przerwa
#include <util/delay.h>                                         //Importowanie biblioteki do funkcji op nienia
#include <string.h>                                             // biblioteka zawieraj ca funkcje do zwracania d ugo ci napisu
#define F_CPU 4000000                                           // Definicja cz stotliwo ci zegara mikrokontrolera (4 MHz)
#define USART_BAUDRATE 9600                                     // Ustalenie pr dko ci transmisji szeregowej (9600 bps)
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) // Obliczenie preskalera

                                                                                                                                                            void
                                                                                                                                                            usart_init(void) // Deklaracja funkcji inicjalizuj cej modu  USART
{
    UBRRH = (uint8_t)(BAUD_PRESCALE >> 8);              // wpisanie starszego bajtu preskalera
    UBRRL = (uint8_t)BAUD_PRESCALE;                     // wpisanie mlodszego bajtu preskalera
    UCSRB = (1 << TXEN);                                // zmiana trybu dzia ania (W  cz nadajnik USART)
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Ustawienie formatu ramki danych (8 bit w danych, 1 bit stopu, bez bitu parzysto ci)
}

void USART_putchar(unsigned char data) // Funkcja wysy aj ca pojedynczy znak przez USART
{
    while (!(UCSRA & (1 << UDRE)))
        ;       // Czekaj, a  bufor nadawczy USART b dzie gotowy do przesy ania
    UDR = data; // Wys anie znaku przez USART
}

void USART_puttext(unsigned char *tekst, uint8_t dlugosc) // Funkcja wysy aj ca ci g znak w przez USART
{
    int8_t i = 0;
    while (i < dlugosc)
    {
        USART_putchar(tekst[i]); // Wywo aj funkcj  wysy aj c  pojedynczy znak
        _delay_ms(2);            // Op nienie 2 ms
        i++;                     // Inkrementacja licznika
    }
}

int main(void)
{
    PORTD = 0x02;                                            // pullup na TXC
    usart_init();                                            // Wywo anie funkcji inicjalizuj cej USART
    USART_puttext("IMIE NAZWISKO", strlen("IMIE NAZWISKO")); // Wywo anie funkcji wysy aj cej ci g znak w
    while (1)
    {
    } // P tla niesko czona
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -ZAD 2 Z LAB 4 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <avr/io.h>                                             //Importowanie biblioteki AVR
#include <avr/interrupt.h>                                      //Importowanie biblioteki do obs ugi przerwa
#include <util/delay.h>                                         //Importowanie biblioteki do funkcji op nienia
#include <string.h>                                             // biblioteka zawieraj ca funkcje do zwracania d ugo ci napisu
#define F_CPU 4000000                                           // Definicja cz stotliwo ci zegara mikrokontrolera (4 MHz)
#define USART_BAUDRATE 9600                                     // Ustalenie pr dko ci transmisji szeregowej (9600 bps)
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) // Obliczenie preskalera na podstawie wybranej pr dko ci transmisji

                                                                                                                                                            void
                                                                                                                                                            usart_init(void) // Funkcja inicjalizuj ca modu  USART
{
    UBRRH = (uint8_t)(BAUD_PRESCALE >> 8);              // Ustawienie starszego bajtu preskalera
    UBRRL = (uint8_t)BAUD_PRESCALE;                     // Ustawienie m odszego bajtu preskalera
    UCSRB = (1 << RXCIE | 1 << RXEN | 1 << TXEN);       // Ustawienie bit w w rejestrze UCSR (w  czenie odbiornika, nadajnika i przerwania od odbioru)
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Ustawienie formatu ramki danych (8 bit w danych, 1 bit stopu, bez bitu parzysto ci)
}

void USART_putchar(unsigned char data) // Funkcja wysy aj ca pojedynczy znak przez USART
{
    while (!(UCSRA & (1 << UDRE)))
    {
    }           // Oczekiwanie na gotno   bufora nadawczego USART
    UDR = data; // Wys anie znaku przez USART
}

void USART_puttext(unsigned char *tekst, uint8_t dlugosc) // Funkcja wysy aj ca ci g znak w przez USART
{
    int8_t i = 0;
    while (i < dlugosc)
    {
        USART_putchar(tekst[i]); // Wywo aj funkcj  wysy aj c  pojedynczy znak
        i++;                     // Inkrementacja licznika
    }
    _delay_ms(2); // Op nienie 2 ms
}

ISR(USART_RXC_vect) // Obs uga przerwania od odebrania danych przez USART
{
    char c = UDR; // Odczyt odebranej danej
    if (c == 'c')
        USART_puttext("\nZnak prawidlowy\r\n", strlen("\nZnak prawidlowy\r\n"));
    else
        USART_puttext("\nZnak bledny\r\n", strlen("\nZnak bledny\r\n"));
}

int main(void)
{
    PORTD = 0x02; // Ustawienie drugiego pinu portu D na warto   0x02 (pull-up na TXC)
    PORTB = 0xFF; // Ustawienie portu B jako wej cia z w  czonymi pull-up
    usart_init(); // Wywo anie funkcji inicjalizuj cej modu  USART
    USART_puttext("Nacisnij klawisz [c]\n:", strlen("Nacisnij klawisz [c]\n"));
    sei(); // W  czenie obs ugi przerwa
    while (1)
    {
    } // P tla niesko czona
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -ZAD 3 Z LAB 4 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <avr/io.h>                                             // Importowanie biblioteki AVR
#include <avr/interrupt.h>                                      // Importowanie biblioteki do obs ugi przerwa
#include <util/delay.h>                                         // Importowanie biblioteki do funkcji op nienia
#define F_CPU 4000000                                           // Definicja cz stotliwo ci zegara mikrokontrolera (4 MHz)
#define USART_BAUDRATE 9600                                     // Ustalenie pr dko ci transmisji szeregowej (9600 bps)
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) // Obliczenie preskalera na podstawie wybranej pr dko ci transmisji
                                                                                                                                                            void
                                                                                                                                                            usart_init(void)
{
    UBRRH = (uint8_t)(BAUD_PRESCALE >> 8);              // Ustawienie starszego bajtu preskalera
    UBRRL = (uint8_t)BAUD_PRESCALE;                     // Ustawienie m odszego bajtu preskalera
    UCSRB = (1 << RXCIE | 1 << RXEN | 1 << TXEN);       // Ustawienie bit w w rejestrze UCSR (w  czenie przerwa  od odbioru, w  czenie odbiornika i nadajnika)
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Ustawienie formatu ramki danych (8 bit w danych, 1 bit stopu, bez bitu parzysto ci)
}
void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE)))
    {
    }           // Czekaj, a  bufor nadawczy USART b dzie gotowy do przesy ania
    UDR = data; // Wys anie znaku przez USART
}
void USART_puttext(unsigned char *tekst, uint8_t dlugosc)
{
    int8_t i = 0;
    while (i < dlugosc)
    {
        USART_putchar(tekst[i]); // Wywo aj funkcj  wysy aj c  pojedynczy znak
        _delay_ms(2);            // Op nienie 2 ms
        i++;                     // Inkrementacja licznika
    }
}
void timer0_init(void)
{
    TCCR0 |= 1 << WGM01;            // timer w tryb CTC
    OCR0 = 97;                      // Ustawia warto   rejestru OCR0 na 97.
    TIMSK |= (1 << OCIE0);          // zezwolenie na obs ug  przerwania od flagi OCF0
    TCCR0 |= 1 << CS02 | 1 << CS00; // start timera, ustawienie preskalera 1/1024
}
ISR(TIMER0_COMP_vect) // Obs uga przerwania od przepelnienia timera 0
{
    PORTA ^= 1; // Zmiana stanu pinu PORTA bit 0
}
ISR(USART_RXC_vect) // Obs uga przerwania od odebrania danych przez USART
{
    char a = UDR;                             // Odczyt odebranej danej
    USART_puttext("\nOdczytano numer: ", 19); // Wys anie tekstu informacyjnego przez USART
    USART_putchar(a);                         // Wys anie odebranego znaku przez USART
    switch (a)
    {
    case '1':
    {
        PORTA ^= 0b00000010; // Zmiana stanu pinu PORTA bit 1
        break;
    }
    case '2':
    {
        PORTA ^= 0b00000100; // Zmiana stanu pinu PORTA bit 2
        break;
    }
    case '3':
    {
        PORTA ^= 0b00001000; // Zmiana stanu pinu PORTA bit 3
        break;
    }
    case '4':
    {
        PORTA ^= 0b00010000; // Zmiana stanu pinu PORTA bit 4
        break;
    }
    case '5':
    {
        PORTA ^= 0b00100000; // Zmiana stanu pinu PORTA bit 5
        break;
    }
    case '6':
    {
        PORTA ^= 0b01000000; // Zmiana stanu pinu PORTA bit 6
        break;
    }
    case '7':
    {
        PORTA ^= 0b10000000; // Zmiana stanu pinu PORTA bit 7
        break;
    }
    case 'c':
    {
        PORTA &= 1; // Wy  czenie wszystkich pin w PORTA opr cz bitu 0
        break;
    }
    case 's':
    {
        PORTA |= 0xFE; // W  czenie wszystkich pin w PORTA opr cz bitu 0
        break;
    }
    default:
    {
        USART_puttext("\nerr", 4); // Wys anie informacji o b  dzie
    }
    }
}
int main(void)
{
    PORTD = 0x02;                             // Ustawienie drugiego pinu portu D na warto   0x02 (pull-up na TXC)
    DDRA = 0xFF;                              // Ustawienie portu A jako wyj cia
    usart_init();                             // Wywo anie funkcji inicjalizuj cej modu  USART
    timer0_init();                            // Wywo anie funkcji inicjalizuj cej timer 0
    USART_puttext("Podaj numer diody: ", 19); // Wys anie informacji przez USART
    sei();                                    // W  czenie obs ugi przerwa
    while (1)
    {
    } // P tla niesko czona
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -kod na zajecia 25.10 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -main.c-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#define F_CPU 1000000L // Definiowanie cz stotliwo ci taktowania mikrokontrolera
#include <avr/io.h>    //biblioteka avr
#include "lcd.h"       //stworzona biblioteka do obs ugi ekranu
#include "key.h"       //stworzona biblioteka do obs ugi klawiatury
#include <util/delay.h>
#include "symbol.h"

                                                                                                                                                             int
                                                                                                                                                             main(void)
{
    unsigned char PORT = 'A'; // ustawienie na kt rym porcie uruchamiamy lcd
    uint8_t RS = 0;           // Ustawiamy kt ry bit bedzie odpowiada  za wyprowadzenie RS
    uint8_t EN = 1;           // Ustawiamy kt ry bit bedzie odpowiada  za wyprowadzenie EN
    LCD_init(PORT, EN, RS);   // Inicjalizacja lcd na Porcie, pinie EN oraz pinie RS wybranym przez u ytkownika

    LCD_write(PORT, EN, RS, "Czas na zadanialab ", 19); // Wypisanie napisu na ekran
    LCD_clear_y(PORT, EN, RS, 4);                       // wyczy zenie od 4 pozycji w aktualnym wierszu

    // dodawanie :) na slot 0
    LCD_add_symbol(PORT, EN, RS, customsmiley, 0);
    // Dodawanie   slot 1
    LCD_add_symbol(PORT, EN, RS, customC, 1);

    set_kursor_LCD(PORT, EN, RS, 1, 1); // ustawienie kursora w 1 wierszu na 4 pozycji
    LCD_send(PORT, 0, EN);              // wypisanie zdefiniowanego znaku 1
    LCD_send(PORT, ' ', EN);
    LCD_send(PORT, 1, EN);   // wypisanie zdefiniowanego znaku 2
    keyboard_init('D', 'D'); // inicjalizacja klawiatury na porcie D

    // podczas wcisniecia wyswietla sie numer przycisku
    // while(1)
    //{
    //	set_kursor_LCD(PORT, EN, RS, 1, 8); // ustawienie kursora
    //	LCD_send_number(PORT, EN, get_key('D', 'D')); // Ustawienie na ekranie warto ci zwracanej funkcj  get_key
    // }

    // po wcisnieciu pozostaje wyswietlony numer
    while (1)
    {
        uint8_t key = get_key('D', 'D');

        if (key != 0)
        {
            // Wci ni to klawisz, wi c wy wietl numer klawisza
            set_kursor_LCD(PORT, EN, RS, 1, 8); // Ustawienie kursora
            LCD_send_number(PORT, EN, key);
        }
        asm("nop");
    }
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -lcd.h-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#ifndef LCD_H_
#define LCD_H_

                                                                                     unsigned char
                                                                                     LCD_set_PORT(char port, char value); // setter Portu
unsigned char LCD_set_DDR(char port, char value);                                                                         // Setter rejestru DDR
unsigned char LCD_get_PORT(char port);                                                                                    // getter Portu

void LCD_send(unsigned char PORT, uint8_t b, uint8_t EN);                                          // wysy anie danych do interfejsu LCD
void LCD_clear(unsigned char PORT, uint8_t EN, uint8_t RS);                                        // czyszczenie ekranu
void LCD_init(unsigned char PORT, uint8_t EN, uint8_t RS);                                         // inicjalizacja ekranu na wybranym porcie
void set_kursor_LCD(unsigned char PORT, uint8_t EN, uint8_t RS, unsigned char x, unsigned char y); // ustawienie kursora w podanym wierszu i kolumnie
void LCD_write(unsigned char PORT, uint8_t EN, uint8_t RS, char *tekst,
               int8_t dlugosc);                                                                // wypisanie tekstu o podanej d ugo ci na ekranie
void LCD_send_number(unsigned char PORT, uint8_t EN, uint8_t numer);                           // wys anie liczby
int8_t LCD_row();                                                                              // Zwr cenie aktualnego wiersza
void LCD_clear_y(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t pozycja);                 // wyczyszczenie ekranu w aktualnym wierszu od pozycji podanej w parametrze
void LCD_send_command(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t b);                  // wys anie komendy
void LCD_add_symbol(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t tab[8], uint8_t slot); // dodanie nowego symbolu
#endif

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -lcd.c-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <avr/io.h>     // Pod  czenie biblioteki do obs ugi wej cia/wyj cia mikrokontrolera AVR
#include <util/delay.h> // Pod  czenie biblioteki do op nie
#include <string.h>     // Pod  czenie biblioteki do obs ugi  a cuch w znak w
#include "lcd.h"        // import biblioteki do obs ugi lcd

                                                                      volatile int8_t curr_row = 0; // Deklaracja zmiennej globalnej przechowuj cej aktualny wiersz na ekranie LCD
int8_t LCD_row()                                                                                    // definicja funkcji zwracaj cej aktualny wiersz
{
    return curr_row;
}

unsigned char LCD_set_PORT(char port, char value)
{
    switch (port)
    { // w zale no ci od podanego portu w argumencie funkcji, ustaw dan  warto
    case 'A':
    {                  // gdy port == 'A'
        PORTA = value; // Ustaw Port A
        break;
    }
    case 'B':
    { // gdy port == 'B'
        PORTB = value;
        break;
    }
    case 'C':
    { // gdy port == 'C'
        PORTC = value;
        break;
    }
    case 'D':
    { // gdy port == 'D'
        PORTD = value;
        break;
    }
    default:
        return -1;
    } // w przypadku b  dnej warto ci zwr   -1
}

unsigned char LCD_set_DDR(char port, char value)
{
    switch (port)
    {         // w zale no ci od podanego portu w argumencie funkcji, ustaw dan  warto   rejestru DDR*
    case 'A': // gdy port == 'A'
    {
        DDRA = value; // Ustaw rejestr DDRA
        break;
    }
    case 'B':
    { // gdy port == 'B'
        DDRB = value;
        break;
    }
    case 'C':
    { // gdy port == 'C'
        DDRC = value;
        break;
    }
    case 'D':
    { // gdy port == 'D'
        DDRD = value;
        break;
    }
    default:
        return -1;
    }
}
unsigned char LCD_get_PORT(char port)
{
    switch (port) // w zale no ci od podanego portu w argumencie funkcji, zwr   dan  warto
    {
    case 'A':
    {                 // gdy port == 'A'
        return PORTA; // zwr   PORTA
        break;
    }
    case 'B':
    {                 // gdy port == 'B'
        return PORTB; // Zwr   PORTB
        break;
    }
    case 'C':
    {                 // gdy port == 'C'
        return PORTC; // Zwr   PORTC
        break;
    }
    case 'D':
    {                 // gdy port == 'D'
        return PORTD; // Zwr   PORTD
        break;
    }
    default:
        return -1; // w przypadku b  dnej warto ci zwr   -1
    }
}

void set_kursor_LCD(unsigned char PORT, uint8_t EN, uint8_t RS, unsigned char x, unsigned char y)
{                                                        // Ustawia kursor w miejscu podanym we wsp rz dnych
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) & ~_BV(RS))); // Prze  czenie linii RS na 0, aby wys a  komend , a nie dane
    LCD_send(PORT, ((x * 0x40 + y) | 0x80), EN);         // przes anie komendy zmienienia pozycji kursora
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) | _BV(RS)));  // w  czenie trybu wysy ania danych
    _delay_ms(5);                                        // Op nienie
    curr_row = x;                                        // Zapisanie aktualnego wiersza
}

void LCD_send(unsigned char PORT, uint8_t b, uint8_t EN) // Funkcja do wys ania danych do interfejsu LCD
{
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) | _BV(EN)));                  // Ustawienie linii ENABLE w stan wysoki
    LCD_set_PORT(PORT, (b & 0xF0) | (LCD_get_PORT(PORT) & 0x0F));        // Wys anie starszych 4 bit w danych
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) & ~_BV(EN)));                 // Potwierdzenie wys ania danych przez opuszczenie linii ENABLE
    asm volatile("nop");                                                 // Odczekanie
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) | _BV(EN)));                  // Ponowne ustawienie linii ENABLE
    LCD_set_PORT(PORT, ((b & 0x0F) << 4) | (LCD_get_PORT(PORT) & 0x0F)); // Wys anie m odszych 4 bit w danych
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) & ~_BV(EN)));                 // Potwierdzenie wys ania danych przez opuszczenie linii ENABLE
    _delay_us(50);                                                       // Op nienie
}

void LCD_clear(unsigned char PORT, uint8_t EN, uint8_t RS) // Wyczyszczenie ekranu LCD
{
    LCD_send_command(PORT, EN, RS, 0x01); // Wys anie komendy do czyszczenia
    _delay_ms(2);                         // Op nienie
    curr_row = 0;                         // Zresetowanie aktualnego wiersza
}

void LCD_send_command(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t b) // wys anie komendy
{
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) & ~_BV(RS))); // ustawienie trybu przesy ania komend
    LCD_send(PORT, b, EN);                               // przes anie informacji
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) | _BV(RS)));  // ustawienie trybu przesy ania danych
    _delay_us(2);
}

void LCD_init(unsigned char PORT, uint8_t EN, uint8_t RS)
{
    LCD_set_DDR(PORT, 0xF0 | (_BV(RS)) | (_BV(EN))); // Konfiguracja kierunku pin w dla interfejsu LCD
    LCD_set_PORT(PORT, 0);                           // Wyczyszczenie portu interfejsu LCD
    _delay_ms(15);                                   // opoznienie
    LCD_send(PORT, 0b00110000, EN);
    _delay_ms(4.2);
    LCD_send(PORT, 0b00110000, EN);
    _delay_us(100);
    LCD_send(PORT, 0x32, EN);
    LCD_send(PORT, 0b00101000, EN);                     // function set (2 linie, 5x8)
    LCD_send(PORT, 0b00000110, EN);                     // entry mode set (Tryb inkrementacji kursora)
    LCD_send(PORT, 0b00001100, EN);                     // display on/off (w   zony ekran, bez kursora)
    LCD_clear(PORT, EN, RS);                            // wyczyszczenie ekranu
    LCD_set_PORT(PORT, (LCD_get_PORT(PORT) | _BV(RS))); // prze  czenie w tryb danych
}

void LCD_write(unsigned char PORT, uint8_t EN, uint8_t RS, char *tekst, int8_t dlugosc)
{
    int8_t i = 0;
    while (i < dlugosc)
    {
        if (i == 15) // Je li osi gni to 16 znak, przesu  kursor na pocz tek drugiej linii
        {
            set_kursor_LCD(PORT, EN, RS, 1, 0); // Przesuni cie kursora na pocz tek drugiej linii
            curr_row = 1;                       // Aktualizacja warto ci aktualnego wiersza
        }
        LCD_send(PORT, tekst[i], EN); // wypisz znak
        i++;                          // Inkrementacja licznika
    }
}

void LCD_send_number(unsigned char PORT, uint8_t EN, uint8_t numer) // Wyswietlenie pojedynczej cyfry
{
    LCD_clear(PORT, EN, 0);
    int8_t temp;
    if (numer < 10) // Je eli liczba jest mniejsza od 10
    {
        LCD_send(PORT, 48, EN);         // Wypisanie zera
        LCD_send(PORT, 48 + numer, EN); // Wypisanie cyfry odpowiadaj cej liczbie na wy wietlaczu LCD
    }
    else if (numer == 255) // Je eli liczba r wna si  255
    {
        LCD_send(PORT, 45, EN);
        ; // Wypisanie znaku '-' na wy wietlaczu LCD
    }
    else
    {
        temp = numer % 10;              // Obliczenie reszty z dzielenia liczby przez 10
        numer /= 10;                    // Podzielenie liczby przez 10
        LCD_send(PORT, 48 + numer, EN); // Wypisanie cyfry dziesi tek na wy wietlaczu LCD
        LCD_send(PORT, 48 + temp, EN);  // Wypisanie cyfry jedno ci na wy wietlaczu LCD
    }
}

void LCD_clear_y(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t pozycja)
{
    set_kursor_LCD(PORT, EN, RS, curr_row, pozycja); // ustawienie pozycji kursora
    for (pozycja; pozycja < 16; pozycja++)           // wyczyszczenie od tej pozycji do ko ca
        LCD_send(PORT, ' ', EN);                     // wypisanie spacji
}

void LCD_add_symbol(unsigned char PORT, uint8_t EN, uint8_t RS, uint8_t tab[8], uint8_t slot)
{                                                      // dodanie nowego symbolu
    LCD_send_command(PORT, EN, RS, (0x40 + slot * 8)); // ustawienie zerowego adresu w pami ci CGRAM
    _delay_ms(5);
    LCD_send(PORT, tab[0], EN); // za adowanie pierwszego wiersza
    LCD_send(PORT, tab[1], EN);
    LCD_send(PORT, tab[2], EN);
    LCD_send(PORT, tab[3], EN);
    LCD_send(PORT, tab[4], EN);
    LCD_send(PORT, tab[5], EN);
    LCD_send(PORT, tab[6], EN);
    LCD_send(PORT, tab[7], EN);           // za adowanie ostatniego wiersza
    LCD_send_command(PORT, EN, RS, 0x80); // ustawienie zerowego adresu pami ci DDRAM
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -key.h-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#ifndef KEY_H_
#define KEY_H_

                                                                                     unsigned char
                                                                                     get_pin(char port); // getter warto ci portu podanego jako argument
unsigned char set_PORT(char port, char value);                                                           // setter podanej warto ci do podanego portu jako argument
unsigned char set_DDR(char port, char value);                                                            // setter podanej warto ci do podanego portu jako argument
unsigned char get_key(char port, char wielkosc);
void keyboard_init(char port, char wielkosc);

#endif

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --key.c-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <avr/io.h>     // Pod  czenie biblioteki do obs ugi wej cia/wyj cia mikrokontrolera AVR
#include <util/delay.h> // Pod  czenie biblioteki do op nie
#include <string.h>     // Pod  czenie biblioteki do obs ugi  a cuch w znak w
#include "lcd.h"        // import biblioteki do obs ugi lcd
#include "key.h"        //import bibliotki do obslugi klawiatury

#define F_CPU 1000000UL // Zdefiniowanie cz stotliwo ci taktowania mikrokontrolera

                                                              unsigned char
                                                              get_pin(char port)
{
    switch (port)
    {
    case 'A':
        return PINA;
        break;
    case 'B':
        return PINB;
        break;
    case 'C':
        return PINC;
        break;
    case 'D':
        return PIND;
        break;
    default:
        return -1;
    }
}

unsigned char set_PORT(char port, char value)
{
    switch (port)
    {
    case 'A':
        PORTA = value;
        break;
    case 'B':
        PORTB = value;
        break;
    case 'C':
        PORTC = value;
        break;
    case 'D':
        PORTD = value;
        break;
    default:
        return -1;
    }
}

unsigned char set_DDR(char port, char value)
{
    switch (port)
    {
    case 'A':
        DDRA = value;
        break;
    case 'B':
        DDRB = value;
        break;
    case 'C':
        DDRC = value;
        break;
    case 'D':
        DDRD = value;
        break;
    default:
        return -1;
    }
}

void keyboard_init(char port, char wielkosc)
{
    set_DDR(port, 0xF0);
    if (wielkosc == 'D')
    {
        set_PORT(port, 0x0F);
    }
    if (wielkosc == 'M')
    {
        set_PORT(port, ~(1 << 4));
    }
}

unsigned char get_key(char port, char wielkosc)
{
    uint8_t x, y, counter = 0, i = 0, key = 0;
    if (wielkosc == 'D')
    {
        for (; i < 4; i++)
        {
            set_PORT(port, ~(1 << i + 4)); // ustawienie stanu niskiego w celu wybrania aktualnie sprawdzanej kolumny
            _delay_ms(1);                  // odczekanie 1 ms
            x = get_pin(port);             // Odczyt warto ci portu A i przypisanie jej do zmiennej x
            _delay_ms(20);                 // odczekanie 20 ms
            y = get_pin(port);             // Ponowny odczyt wartosci portu A i przypisanie jej do zmiennej y
            if ((x != y))
                return 0;
            if (x == 0b00001111)
                return 0;
            if (x == 0xFF)
                return 255;
            x &= 0x0F;
            for (int j = 0; j < 4; j++) // iteracja po wierszach
            {
                if (!(x & (1 << j))) // sprawdzanie wiersza na pozycji j
                {
                    key = 4 * j + i + 1;
                    ;          // formu a obliczaj ca numer przycisku
                    counter++; // zwi kszenie licznika
                }
            }
        }
        if (counter > 1) // jezeli by o wiecej wcisnietych w wierszu
            return 255;
        else
            return key;
    }
    else if (wielkosc == 'M')
    {
        uint8_t x, y, counter = 0,
                      i = 0,
                      key = 0;
        for (; i < 4; i++)
        {
            set_PORT(port, ~(1 << i + 4));
            _delay_ms(1);
            x = get_pin(port);
            _delay_ms(20);
            y = get_pin(port);
            if ((x != y))
                return 0;
            if (x == 0b00001111)
                return 0;
            if (x == 0xFF)
                return 255;
            x &= 0x0F;
            switch (x)
            {
            case 0b00000111:
                return 4;
            case 0b00001011:
                return 3;
            case 0b00001101:
                return 2;
            case 0b00001110:
                return 1;
            default:
                return 0;
            }
        }
        if (counter > 1)
            return 255;
        else
            return key;
    }
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --symbol.h-- -- -- -- -- -- -- -- -- -- -- -- --

#ifndef SYMBOL_H_
#define SYMBOL_H_

                                                        // Definicja
                                                        const uint8_t customC[8] = {
    0b00010,
    0b00100,
    0b01110,
    0b10000,
    0b10000,
    0b10001,
    0b01110,
    0b00000};

// usmieszek
const uint8_t customsmiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000};

#endif /* SYMBOL_H_ */

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -kod na zajecia 18.10 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

                                                                                                                                  main.c :
//================================main.c
#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

    int
    main(void)
{
    volatile uint8_t *LCD_DDR = &DDRA;
    volatile uint8_t *LCD_PORT = &PORTA;
    uint8_t RS = 0, EN = 1;
    *LCD_DDR |= 0xf0 | 1 << RS | 1 << EN;
    LCD_INIT(LCD_PORT, EN, RS);
    char tekst[] = "Testowy napis ktory jest dlugi";
    LCD_WRITE(tekst, 30, 0, 0, LCD_PORT, EN, RS);
    _delay_ms(5000);
    LCD_CLEAR_XY(1, 10, LCD_PORT, EN, RS);
    _delay_ms(5000);
    LCD_CLEAR_XY(0, 10, LCD_PORT, EN, RS);
    while (1)
    {
        asm("nop");
    }
}

lcd.h
//================================lcd.h
#ifndef LCD_H_
#define LCD_H_
    // wysy a bajt danych ("b") w trybie 4-bitowym
    extern void
    LCD_SEND(uint8_t b, volatile uint8_t *port, uint8_t EN);
// wysy a komende konfiguracyjn
extern void LCD_WRITE_CMD(volatile uint8_t b, volatile uint8_t *port, volatile uint8_t EN, volatile uint8_t RS);
// wypisanie tekstu o dl len od miejsca w, k
extern void LCD_WRITE(volatile char *text, volatile uint8_t len, volatile uint8_t row, volatile uint8_t col, volatile uint8_t *port, volatile uint8_t EN, volatile uint8_t RS);
// konfiguruje pocz tkowe ustawienia wy wietlacza
extern void LCD_INIT(volatile uint8_t *port, uint8_t EN, uint8_t RS);
// czy ci, przesuwa kursor na pocz tek
extern void LCD_CLEAR(volatile uint8_t *port, uint8_t EN, uint8_t RS);
// ustawia kursor
extern void LCD_XY(uint8_t row, uint8_t col, volatile uint8_t *port, uint8_t EN, uint8_t RS);
// czy ci wy wietlacz od row col
extern void LCD_CLEAR_XY(uint8_t row, uint8_t col, volatile uint8_t *port, uint8_t EN, uint8_t RS);
#endif /* LCD_H_ */

lcd.c
//========================lcd.c
#ifndef F_CPU
#define F_CPU 1000000L
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

    void
    LCD_SEND(uint8_t b, volatile uint8_t *port, uint8_t EN)
{
    *port |= 1 << EN;
    *port = (b & 0xf0) | (*port & 0x0f);
    *port &= ~(1 << EN);
    _delay_us(1);
    *port |= 1 << EN;
    *port = (b << 4) | (*port & 0x0f);
    *port &= ~(1 << EN);
    _delay_ms(1.5);
}

void LCD_WRITE_CMD(volatile uint8_t b, volatile uint8_t *port, volatile uint8_t EN, volatile uint8_t RS)
{
    *port &= ~(1 << RS);
    LCD_SEND(b, port, EN);
    *port |= 1 << RS;
    _delay_ms(5);
}

void LCD_INIT(volatile uint8_t *port, uint8_t EN, uint8_t RS)
{
    *port &= ~(1 << RS);
    LCD_SEND(0x33, port, EN);
    LCD_SEND(0x32, port, EN);
    LCD_SEND(0x20 | 0b00001000, port, EN);
    LCD_SEND(0x10 | 0b00000100, port, EN);
    LCD_SEND(0x08 | 0b00000110, port, EN);
    LCD_SEND(0x04 | 0b00000010, port, EN);
    LCD_SEND(0x01, port, EN);
    *port |= 1 << RS;
    _delay_ms(5);
}

void LCD_XY(uint8_t row, uint8_t col, volatile uint8_t *port, uint8_t EN, uint8_t RS)
{
    LCD_WRITE_CMD((row * 0x40 + col) | 0x80, port, EN, RS);
}

void LCD_CLEAR(volatile uint8_t *port, uint8_t EN, uint8_t RS)
{
    LCD_WRITE_CMD(0x01, port, EN, RS);
}

void LCD_WRITE(volatile char *text, uint8_t len, uint8_t row, uint8_t col, volatile uint8_t *port, volatile uint8_t EN, volatile uint8_t RS)
{
    uint8_t i = 0;
    LCD_XY(row, col, port, EN, RS);
    while (row * 16 + col + i < 32 && i < len)
    {
        if (col + i == 16 && row == 0)
        {
            LCD_XY(1, 0, port, EN, RS);
        }
        LCD_SEND(text[i], port, EN);
        i++;
    }
}

void LCD_CLEAR_XY(uint8_t row, uint8_t col, volatile uint8_t *port, uint8_t EN, uint8_t RS)
{
    LCD_XY(row, col, port, EN, RS);
    uint8_t col_temp = col;
    if (row == 0)
    {
        while (col < 16)
        {
            LCD_SEND(' ', port, EN);
            col++;
        }
        col = 0;
        LCD_XY(1, 0, port, EN, RS);
    }
    while (col < 16)
    {
        LCD_SEND(' ', port, EN);
        col++;
    }
    LCD_XY(row, col_temp, port, EN, RS);
}

SPRAWDŹCIE newcpu CHŁOPAKI

#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

    unsigned char
    get_pin(char port);
unsigned char set_PORT(char port, char value);
unsigned char set_DDR(char port, char value);
void leds_init(char port);
void set_led_number(char port, uint8_t number);
void keyboard_init(char port, char wielkosc);
unsigned get_key(char port, char wielkosc);

unsigned char get_pin(char port)
{
    switch (port)
    {
    case 'A':
        return PINA;
        break;
    case 'B':
        return PINB;
        break;
    case 'C':
        return PINC;
        break;
    case 'D':
        return PIND;
        break;
    default:
        return -1;
    }
}
unsigned char set_PORT(char port, char value)
{
    switch (port)
    {
    case 'A':
        PORTA = value;
        break;
    case 'B':
        PORTB = value;
        break;
    case 'C':
        PORTC = value;
        break;
    case 'D':
        PORTD = value;
        break;
    default:
        return -1;
    }
}
unsigned char set_DDR(char port, char value)
{
    switch (port)
    {
    case 'A':
        DDRA = value;
        break;
    case 'B':
        DDRB = value;
        break;
    case 'C':
        DDRC = value;
        break;
    case 'D':
        DDRD = value;
        break;
    default:
        return -1;
    }
}

void keyboard_init(char port, char wielkosc)
{
    set_DDR(port, 0xF0);
    if (wielkosc == 'D')
    {
        set_PORT(port, 0x0F);
    }
    if (wielkosc == 'M')
    {
        set_PORT(port, ~(1 << 4));
    }
}

unsigned get_key(char port, char wielkosc)
{
    uint8_t x, y, counter = 0, i = 0, key = 0;
    if (wielkosc == 'D')
    {
        for (; i < 4; i++)
        {
            set_PORT(port, ~(1 << i + 4)); // ustawienie stanu niskiego w celu wybrania aktualnie sprawdzanej kolumny
            _delay_ms(1);                  // odczekanie 1 ms
            x = get_pin(port);             // Odczyt warto ci portu A i przypisanie jej do zmiennej x
            _delay_ms(20);                 // odczekanie 20 ms
            y = get_pin(port);             // Ponowny odczyt wartosci portu A i przypisanie jej do zmiennej y
            if ((x != y))
                return 0;
            if (x == 0b00001111)
                return 0;
            if (x == 0xFF)
                return 255;
            x &= 0x0F;
            for (int j = 0; j < 4; j++) // iteracja po wierszach
            {
                if (!(x & (1 << j))) // sprawdzanie wiersza na pozycji j
                {
                    key = 4 * j + i + 1;
                    ;          // formu a obliczaj ca numer przycisku
                    counter++; // zwi kszenie licznika
                }
            }
        }
        if (counter > 1) // jezeli by o wiecej wcisnietych w wierszu
            return 255;
        else
            return key;
    }
    else if (wielkosc == 'M')
    {
        uint8_t x, y, counter = 0,
                      i = 0,
                      key = 0;
        for (; i < 4; i++)
        {
            set_PORT(port, ~(1 << i + 4));
            _delay_ms(1);
            x = get_pin(port);
            _delay_ms(20);
            y = get_pin(port);
            if ((x != y))
                return 0;
            if (x == 0b00001111)
                return 0;
            if (x == 0xFF)
                return 255;
            x &= 0x0F;
            switch (x)
            {
            case 0b00000111:
                return 4;
            case 0b00001011:
                return 3;
            case 0b00001101:
                return 2;
            case 0b00001110:
                return 1;
            default:
                return 0;
            }
        }
        if (counter > 1)
            return 255;
        else
            return key;
    }
}

int main(void)
{
    DDRA = 0xFF;
    PORTA = 0x00;
    keyboard_init('D', 'M');

    while (1)
    {
        char z = get_key('D', 'M');
        PORTA = z;
    }
}

def para(a = 1, b = 2):

if( not isinstance(a, int) or not isinstance(b, int)):
return None
elif(a>b):
return (b, a)
elif (a == b):
return (a,a)
elif (a return (a, b)


def srednia(input1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],input2 = [1]*10):
srednia = 0
if(len(input1) == len(input2)):
for i in input1:
if(not isinstance(i, int)):
return None
for i in input2:
if(not isinstance(i, int)):
return None
licznik = 0
mianownik = 0
for i in range(len(input1)):
licznik += input1[i]*input2[i]
mianownik += input2[i]
srednia = round(licznik/mianownik, 2)
return srednia
else:
return None


  
  LAB 4 zadanie 1 Bartek
  adanie1

// Poniżej podaj swoje dane
//
//
// I1S 4.3
// GL05
// CW5Z1

// NORMAL
// preskaler 64

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
    if ((PORTA & _BV(0)) == 0)
    { // jeśli dioda nie jest zapalona
        TCNT1 = 65536 - 7812;
    }
    else
    {
        TCNT1 -= 7812; // jeśli dioda jest zapalona
    }

    PORTA |= _BV(0); // zapalenie diody na porcie A

    TCCR1B |= _BV(0);
    TCCR1B |= _BV(1); // ustawienie timera 1 ze sklaowaniem clk/64
    TCCR1B &= ~_BV(2);
}

ISR(TIMER1_OVF_vect){
    PORTA &= ~_BV(0);
    TCCR1B &= ~_BV(0);
    TCCR1B &= ~_BV(1);
}

int main(void)
{
    DDRA |= _BV(0);  // ustawienie lini wyjściowej portu A
    DDRD &= ~_BV(2); // ustawienie lini wejściowej portu D
    PORTD |= _BV(2); // podciaganie linie wejściowej portu D

    DDRC = 0xFF; // usatwienie lini wyjściowych portu C

    GICR |= _BV(6); // ustawienie obsługi przerwania dla INT0
    MCUCR |= _BV(1);
    MCUCR &= ~_BV(0); // usatwienie trybu falling edge w dla INT0

    TCCR1A &= ~_BV(0);
    TCCR1A &= ~_BV(1);
    // tutaj jest błąd to nie ustawia nomarsd
    TCCR1B &= _BV(3);
    TCCR1B &= _BV(4); // ustawienie timera1 w tryb normal

    TCCR1B &= ~_BV(0);
    TCCR1B &= ~_BV(1);
    TCCR1B &= ~_BV(2); // zatrzymanie timera

    TIMSK |= _BV(2); // zezowlenie na przerwanie przy przepełnieniu timera1

    sei(); // globalne zezwolenie na przerwania

    while (1)
    {
        PORTC = 0xFF;
        _delay_ms(150);
        PORTC = 0x00;
        _delay_ms(150);

        asm("nop");
    }
}

// Kod Jakuba
// Tryb normal

#define F_CPU 16000000L    // ustawiamy częstowliwość taktowania dla procedury opóźnienia
#include <avr/io.h>        // dołączamy nazwy rejestrów dla AVR
#include <util/delay.h>    // dołączamy procedury opóźniające
#include <avr/interrupt.h> // dołączamy nazwy procedur obsługi przerwań


ISR(INT0_vect)							// procedura obsługi przerwania INT0
{
    TCNT1 = 34286;                     // ustawianie wartosci poczatkowej timera (65536 - (16*10^6 * 0.5s/256))
    TCCR1B &= ~_BV(CS11) & ~_BV(CS10); // włączamy timer1 ze skalowaniem clk/64
    TCCR1B |= _BV(CS12);
    PORTA |= _BV(0); // włączamy diodę na PA0
}

ISR(TIMER1_OVF_vect){
    PORTA &= ~_BV(0);                 // wyłączamy diodę na PA0
    TCCR1B &= ~_BV(CS11) | _BV(CS10); // zatrzymujemy timer
}

int main(void)							// program główny
{
    DDRA |= _BV(0);  // ustawiamy PA0 na wyjście
    DDRC = 0xFF;     // ustawiamy PC na wyjście
    DDRD &= ~_BV(2); // ustawiamy PD2 na wejście
    PORTD |= _BV(2); // podciągamy zasilanie do przycisku na PD2

    PORTC = 0xFF;

    TIMSK |= _BV(TOIE1);                // włączamy obsługę przerwania timera 1
    MCUCR = (MCUCR | _BV(1)) & ~_BV(0); // ustawiamy bit 1 i zerujemy bit 0 w MCUCR (INT0 falling egde)
    GICR |= _BV(6);                     // włączamy obsługę przerwania INT0

    sei(); // włączamy globalną obsługę przerwań

    while (1)
    {
        _delay_ms(150); // czekamy 150ms
        PORTC = ~PORTC; // zmieniamy stan diod na PORTC na przeciwny
    }
}

// Tryb Fast PWM

#include <avr/io.h> // dołączamy nazwy rejestrów AVR

int main(void)
{
    DDRD |= _BV(5); // ustawiamy PD5 na wyjście (linia OC1A)
    ICR1 = 32500;   // ustawiamy wartość końcową zliczania (TOP) Obliczenia: (16*10^6 * 0.52s / 256)
    OCR1A = 23750;  // ustawiamy wartość timer1, przy której stan OC1A ma się zmienić Obliczenia: (16*10^6 *0.38s / 256)
    TCNT1 = 16000;  // ustawienie minimalnego opoznienia

    // Ustawienie tryb Fast PWM, wartość TOP w ICR1
    TCCR1A |= _BV(WGM11) | _BV(COM1A1) | _BV(COM1A0);
    TCCR1B |= _BV(WGM12) | _BV(WGM13);
    TCCR1B |= (1 << CS12); // prescaler 256 bit
    TCCR1B &= ~(1 << CS11) | (1 << CS10);

    while (1) // ta pętla ma nic nie robić
    {
        asm("nop");
    }
}

// Tryb CTC

#include <avr/io.h>        // dołączamy nazwy rejestrów dla AVR
#define F_CPU 4000000L     // ustawiamy częstowliwość taktowania dla procedury opóźnienia
#include <util/delay.h>    // dołączamy procedury opóźniające
#include <avr/interrupt.h> // dołączamy nazwy procedur obsłgi przerwań

ISR(INT0_vect)							// procedura obsługi przerwania INT0
{
    PORTA |= _BV(0);                 // włączamy diodę na PA0
    TCNT1 = 0;                       // zerujemy timer
    TCCR1B |= _BV(CS10) | _BV(CS11); // włączamy timer1 ze skalowaniem clk/64
}

ISR(TIMER1_COMPA_vect)					// procedura obsługi przerwania przy porównaniu z OCR1A timer1
{
    PORTA &= ~_BV(0);                  // wyłączamy diodę na PA0
    TCCR1B &= ~_BV(CS10) & ~_BV(CS11); // zatrzymujemy timer
}

int main(void)							// program główny
{
    DDRA |= _BV(0);    // ustawiamy PA0 na wyjście
    DDRC = 0b11111111; // ustawiamy PC na wyjście
    DDRD &= ~_BV(2);   // ustawiamy PD2 na wejście
    PORTD |= _BV(2);   // podciągamy zasilanie do przycisku na PD2

    PORTC = 0b11111111; // włączamy wszytskie diody na PC

    TIMSK |= _BV(OCIE1A);               // włączamy obsługę przerwania przy porównaniu z OCR1A timera 1
    MCUCR = (MCUCR | _BV(1)) & ~_BV(0); // ustawiamy bit 1 i zerujemy bit 0 w MCUCR (INT0 falling egde)
    GICR |= _BV(6);                     // włączamy obsługę przerwania INT0

    OCR1A = 31250;        // 31250 zliczeń = 0,5s przy f = 4MHz, skalowanie clk/64
    TCCR1B |= _BV(WGM12); // ustawiamy timer1 w tryb CTC z wartością szczytową w OCR1A

    sei(); // włączamy globalną obsługę przerwań

    while (1)
    {
        _delay_ms(50);  // czekamy 50ms
        PORTC = ~PORTC; // zmieniamy stan diod na PORTC na przeciwny
    }
}


ZADANIE 2

zad2
#include <util/delay.h>
#include <avr/io.h> // dołączamy nazwy rejestrów AVR

int main(void)
{
    DDRB |= _BV(2); // ustawiamy PB2 na wyjśie (linia OC1B)

    TCCR1A |= _BV(WGM11) | _BV(COM1A1);
    TCCR1B |= _BV(WGM12) | _BV(WGM13);

    TCCR1B |= _BV(CS11); // CS11 - skalowanie clk/8, startujemy timer

    ICR1 = 285000;  // ustawiamy wartość końcową zliczania (TOP)
                    // 285000 zliczeń = 570ms przy f = 4MHz, skalowanie clk/8
    OCR1A = 95000;  // ustawiamy wartość timer1, przy której stan OC1A ma się zmienić
                    // 95000 zliczeń = 190ms przy f = 4MHz, skalowanie clk/8
    TCNT1 = 284999; // ustawiamy wartość licznika na prawie TOP, aby nastychmiast ustawić stan linii wyjściowej

    while (1)
    {
        asm("nop");
    }
}




KODZIK ERYŚ
zad1
/*
PA0=D0

PD2=W1
K1=GND

WYSW
C4=GND
PC0=a
PC1=b
PC2=c
PC3=d
PC4=e
PC5=f
PC6=g
PC7=dp
*/

#include <avr/io.h>        //dolaczenie bibliotwki nazw rejestrów
#include <avr/interrupt.h> //dolaczenie bibliotwki przerwan
#define F_CPU 1000000L     // definicja zegara
#include <util/delay.h>    //dolaczenie bibliotwki opoznienia
	

ISR(TIMER1_OVF_vect)	// procedura przerwania kiedy przepełni sie tim1				 
{
    PORTA &= ~(1 << PA0);                  // zgas diode
    TCCR1B &= ~(1 << CS10) | ~(1 << CS12); // Zatrzymaj timer z prescalerem 1024
}

ISR(INT0_vect){    // procedura przerwania int0
    _delay_ms(20); // opoznenie 20ms
    if (!(PIND & 4))
    {                                        // jesli po 20ms dalej wcisniety przycisk to idz dalej
        PORTA |= (1 << PA0);                 // zapal diode
        TCNT1 = 65535 - 488;                 // 0.5s przy prescalerze to ok. 488 dlatego od wartosci max odejmujemy to aby przerwał sie po 0.5s
        TCCR1B |= (1 << CS10) | (1 << CS12); // Uruchom timer z prescalerem 1024 w trybie normal
    }
    GIFR |= (1 << INTF0); // wykluczenie przerwan int0
}

int main(void)
{
    DDRA |= 1 << PA0;  // PA0 na wyjscie dioda
    PORTD |= 1 << PD2; // zasilanie do przycisku
    DDRC = 0xFF;       // wyswietlacz na wyjscie

    TIMSK |= (1 << TOIE1); // Zezwól tim1 na przerwanie gdy sie przepełni

    MCUCR |= 1 << ISC01; // zbocze opadajace dla przerwania int0
    GICR |= 1 << INT0;   // włacz przerwania int0
    sei();               // włacz globalne przerwania

    while (1) // petla głowna
    {
        _delay_ms(150); // czekaj 150ms
        PORTC = ~PORTC; // neguj wyswietlanie wyswietlacza

        asm("nop"); // nie rob nic
    }
}

zad2

#include <avr/io.h> //dolaczenie bibliotwki nazw rejestrów

int main(void)
{
    DDRD |= (1 << PD5); // OC1A na wyjscie

    TCCR1A |= (1 << WGM11) | (1 << COM1A1); // COM1A1= zerujemy przy porównaniu z ocr1a ustawiamy przy wyzerowaniu tim1
    TCCR1B |= (1 << WGM12) | (1 << WGM13);  // konfiguracja tim1 w tryb fast PWM z wartoscia TOP w ICR1  // WGM11, WGM12, WGM13

    // 190ms+380ms = 570
    ICR1 = 557;                          // ustawiamy wartość końcową TOP .557 przy f=1MHZ i prescalerze 1024
    OCR1A = 186;                         // wartość tim1, kiedy stan OC1A ma się zmienić
    TCNT1 = 540;                         // wartość licznika na prawie TOP zeby odrazy byl na lini wyjsciowej oraz minimalne opoznienie
    TCCR1B |= (1 << CS10) | (1 << CS12); // uruchom tim1 ze preskalerem /1024

    while (1) // petla glowna
    {
        asm("nop"); // nie rob nic
    }
}

ZADANIE 1 CHYAB DZIAŁA XD
// Poniżej podaj swoje dane
// Bartosz Kędziorek
// 97633
// GL05
// I1S 4.3
// CW5Z1
////////////////////////////

#define F_CPU 1000000L
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect){
    TCCR0 &= ~_BV(0);
    TCCR0 &= ~_BV(1);
    TCCR0 &= ~_BV(2); // zatrzymanie timera 0

    if ((PIND & _BV(2)) == 0)
    { // jeżeli przycisk jest nadal wciśnięty
        if ((PORTA & _BV(0)) == 0)
        { // jeśli dioda nie jest zapalona
            TCNT1 = 65536 - 7813;
        }
        else
        {
            TCNT1 -= 7813; // jeśli dioda jest zapalona
        }

        PORTA |= _BV(0); // zapalenie diody na porcie A

        TCCR1B |= _BV(0);
        TCCR1B |= _BV(1); // ustawienie timera 1 z częstotliwością clk/64
        TCCR1B &= ~_BV(2);
    }

    GIFR |= _BV(6); // wyczyszczenie flagi przerwania zewnętrznego INT0
    GICR |= _BV(6);
}

ISR(INT0_vect){
    GICR &= ~_BV(6); // zablokowanie przerwania zewnetrznego INT0

    TCNT0 = 256 - 78; // załadowanie poczatkowej wartości timera
    TCCR0 |= _BV(2);
    TCCR0 &= ~_BV(1);
    TCCR0 &= ~_BV(0); // ustawienie timera 0 z częstotliwością clk/66
	
}

ISR(TIMER1_OVF_vect){
    PORTA &= ~_BV(0);

    TCCR1B &= ~_BV(0);
    TCCR1B &= ~_BV(1); // zatrzymanie timera
}




int main(void)
{
    DDRC = 0xFF;
    PORTC = 0xFF; // ustawienie i inicjalizacja diód na porcie C

    DDRA |= _BV(0);  // ustawienie lini wyjściowej portu A
    DDRD &= ~_BV(2); // ustawienie lini wejściowej portu D
    PORTD |= _BV(2); // podciaganie linie wejściowej portu D

    GICR |= _BV(6); // ustawienie obsługi przerwania dla INT0
    MCUCR |= _BV(1);
    MCUCR &= ~_BV(0); // usatwienie trybu falling edge w dla INT0

    TCCR1A &= ~_BV(0);
    TCCR1A &= ~_BV(1);
    TCCR1B &= ~_BV(3);
    TCCR1B &= ~_BV(4); // ustawienie timera1 w tryb normal

    TCCR1B &= ~_BV(0);
    TCCR1B &= ~_BV(1);
    TCCR1B &= ~_BV(2); // zatrzymanie timera

    TIMSK |= _BV(2); // zezowlenie na przerwanie przy przepełnieniu timera1

    // ustawienie timera 0
    TCCR0 &= ~_BV(6);
    TCCR0 &= ~_BV(3); // ustawienie timera 0 w tryb normal

    // To do proceduty wal
    //	TCCR0 &= ~_BV(2);
    //	TCCR0 |= _BV(1);
    //	TCCR0 |= _BV(0);  //ustawienie timera 1 z częstotliwością clk/64

    TCCR0 &= ~_BV(0);
    TCCR0 &= ~_BV(1);
    TCCR0 &= ~_BV(2); // zatrzymanie timera

    TIMSK |= _BV(0); // zezowlenie na przerwanie przy przepełnieniu timera0

    sei(); // globalne zezwolenie na przerwania

    while (1)
    {
        _delay_ms(150);
        PORTC = ~PORTC;
        asm("nop");
    }
}

/// LAB 5//Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
// Zadanie Cw7Z2
/////////////////////////

#define F_CPU 1000000L
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


uint8_t BinCode(uint8_t code, uint8_t mask) {
    uint8_t licznik = 0;
    uint8_t i = 0;

    while ((code & mask) == 0)
    {
        if (i == 3)
        {
            break;
        }
        licznik++;
        mask = mask << 1;
        i++;
    }

    return licznik;
}

ISR(TIMER0_OVF_vect){
    TCCR0 &= 0b11111000; // zatrzymanie timera 0
    _delay_ms(20);       // opóźnienie
    static uint8_t maska = 0b00010000;
    PORTD ^= maska; // wygaszenie bitu dla odpowiedniej kolumny

    uint8_t aktywne_wiersze = ~PIND & 0b00001111;
    // określenie aktywnych wierszy

    if (aktywne_wiersze != 0)
    { // jeżeli którakolwiek z lini wiersza jest aktywna
        uint8_t number_wiersza = BinCode(aktywne_wiersze, 0b00000001);
        uint8_t number_kolumny = BinCode(maska, 0b00010000);
        uint8_t finCode = number_wiersza * 4 + number_kolumny;
        PORTA = finCode;
    }

    maska = maska << 1;
    if (maska == 0b00000000)
    {
        maska = 0b00010000;
    }

    TCNT0 = 236;
    TCCR0 |= 0b00000101; // ponowne wystartowanie timera
    PORTD |= 0b11110000;
}

int main(void)
{
    cli(); // brak zezwolenia na przerwania zewnętrzne

    // ustawienia początkowe portu D
    DDRD = 0b11110000;   // ustawienie linii wierszy jako lini wejścia
                         // oraz linii kolumn jako lini wyjscia dla portu D
    PORTD |= 0b00001111; // podciąganie lini wejściowych na porcie D

    // ustawienia początkowe portu A
    DDRA = 0xFF;  // ustawienie lini portu A jako linie wyjścia
    PORTA = 0x00; // zgaszenie wszystkich diód na porcie A

    // ustawienia początkowe timera 0

    TCCR0 &= 0b10110000; // ustawienie TIMERA 0 w tryb normal
                         // oraz zatrzymanie timera
    TIMSK |= 0b00000001; // zezwolenie na przerwanie spowodowane
                         // przepełnieniem timera 0

    TCNT0 = 236; // sprawdzanie klawiatury będzie odbywało sie co 20ms
                 // preskaler ustawiamy na 1024, zakaładamy, że mikroprocesor
                 // taktuje z częstotliwością 1Mhz

    TCCR0 |= 0b00000101; // wystartowanie timera z preskalerem 1024

    DDRC = 0xFF;  // ustawienie portu C jako portu wyjściowego
    PORTC = 0XFF; // ustawienie początkowego świecenia diód na porcie C
    sei();        // zezowlenie na przerwania

    while (1)
    {
        _delay_ms(150);
        PORTC = ~PORTC; // animacja na porcie C
        asm("nop");
    }
	
}

////////////////////////////////////////////////////////////////////////////////////////////////

// Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
// Zadanie Cw7Z2
/////////////////////////

#define F_CPU 1000000L
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


ISR(TIMER0_OVF_vect){
    TCCR0 &= 0b11111000; // zatrzymanie timera 0
    _delay_ms(20);       // opóźnienie
    uint8_t aktywne_wiersze = (~PIND) & 0b00001111;
    // pobranie wartości wierszy
    if (aktywne_wiersze != 0)
    {                 // jeżeli którykolwiek z wierszy jest w stanie wysokim
        DDRD = ~DDRD; // zmiana kierunku linii
                      // DDRD = 0b00001111
        PORTD = ~PORTD; // podciąganie lini kolumn oraz podanie 0 na linie wierszy
                        // PORTD = 0b11110000

        uint8_t aktywne_kolumny = (~PIND) & 0b11110000; // pobranie wartości kolumn
        PORTA = aktywne_kolumny | aktywne_wiersze;

        DDRD = ~DDRD;   //
        PORTD = ~PORTD; // powrót do stanu początkowego
    }

    TCCR0 |= 0b00000101; // ponowne wystartowanie timera
}

int main(void)
{
    cli(); // brak zezwolenia na przerwania zewnętrzne

    // ustawienia początkowe portu D
    DDRD = 0b11110000;   // ustawienie linii wierszy jako lini wejścia
                         // oraz linii kolumn jako lini wyjscia dla portu D
    PORTD |= 0b00001111; // podciąganie lini wejściowych na porcie D

    // ustawienia początkowe portu A
    DDRA = 0xFF;  // ustawienie lini portu A jako linie wyjścia
    PORTA = 0x00; // zgaszenie wszystkich diód na porcie A

    // ustawienia początkowe timera 0

    TCCR0 &= 0b10110000; // ustawienie TIMERA 0 w tryb normal
                         // oraz zatrzymanie timera
    TIMSK |= 0b00000001; // zezwolenie na przerwanie spowodowane
                         // przepełnieniem timera 0

    TCNT0 = 236; // sprawdzanie klawiatury będzie odbywało sie co 20ms
                 // preskaler ustawiamy na 1024, zakaładamy, że mikroprocesor
                 // taktuje z częstotliwością 1Mhz

    TCCR0 |= 0b00000101; // wystartowanie timera z preskalerem 1024

    DDRC = 0xFF;  // ustawienie portu C jako portu wyjściowego
    PORTC = 0XFF; // ustawienie początkowego świecenia diód na porcie C
    sei();        // zezowlenie na przerwania

    while (1)
    {
        _delay_ms(150);
        PORTC = ~PORTC; // animacja na porcie C
        asm("nop");
    }
	
}

/////////////////////////////////////////////////////////////////////////////////
// JAKUB
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Zadanie 1 v1

// PD0-3=W1-W4; PD4-7=K1-K4; PA0-7=a-dp; PC0-7=D0-7; C4=GND
#define F_CPU 16000000L    // definiujemy częstotliwość taktowania dla procedury delay
#include <avr/io.h>        // dołączamy makra nazw rejestrów AVR
#include <avr/interrupt.h> // dołączamy makra obsługi systemu przerwań
#include <util/delay.h>    // dołączamy procedury opóźnienia

unsigned char reverse(unsigned char b) {
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

ISR(TIMER0_COMP_vect)							// procedura obsługi przerwania przy porównaniu timera 0
{
    uint8_t w, k;    // deklarujemy zmienne do zapamiętania aktywnego wiersza i kolumny
    w = PIND | 0xf0; // zapamiętujemy aktywny wiersz w zmiennej w
    // aktywny wiersz = 0, reszta bitów = 1)
    if (w != 0xff) // jeśli którykolwiek przycisk został wciśnięty
    {
        DDRD = 0x0f;     // zmieniamy kierunki linii w PD na przeciwny
        PORTD = 0xf0;    // podciągamy zasilanie do wejść oraz ustawiamy wyjścia w stan niski
        _delay_us(5);    // przeczekujemy stan przejściowy
        k = PIND | 0x0f; // zapamiętujemy aktywną kolumnę w zmiennej k
        // aktywna kolumna = 0, reszta bitów = 1
        DDRD = 0xf0;  // zmieniamy kierunek linii w PD na przeciwny (przywracamy stan wyjściowy)
        PORTD = 0x0f; // przywracamy stan wyjściowy PORTD

        w = ~w;                 // negujemy zmienną w (aktywny wiersz = 1; reszta bitów = 0)
        k = ~k;                 // negacja zmiennej k (aktywna kolumna = 1; reszta bitów = 0)
        PORTA = reverse(w | k); // kodujemy numer wciśnietego klawisza na diodach na PA
    }
}

int main(void)									// program główny
{
    DDRA = 0xff;  // ustawiamy całe PA na wyjście (linijka diod)
    DDRC = 0xff;  // ustawiamy całe PC na wyjście (linijka diod)
    DDRD = 0xf0;  // ustawiamy PD0-3 na wejście (wiersze), PD4-7 na wyjście (kolumny)
    PORTD = 0x0f; // podciągamy zasilanie do wejść oraz ustawiamy wyjścia w stan niski

    TIMSK |= _BV(OCIE0);                         // włączamy obsługę przerwania przy porównaniu timera0
    OCR0 = 38;                                   // ustawiamy wartość końcową zliczania w OCR0 (przerwanie co 38,9ms)
    TCCR0 |= _BV(WGM01) | _BV(CS00) | _BV(CS01); // ustawiamy timer0 w tryb CTC, skalowanie clk/64

    PORTC = 0xff; // wstępnie włączamy wszystkie diody na PC

    sei(); // włączamy globalną obsługę przerwań

    while (1) // pętla główna - animacja na PC
    {
        _delay_ms(150); // czekamy 150ms
        PORTC = ~PORTC; // zmieniamy stan diod na PC na przeciwny
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Zadanie 1 v2

// PD0-3=W1-W4; PD4-7=K1-K4; PA0-7=a-dp; PC0-7=D0-7; C4=GND
#define F_CPU 1000000L     // definiujemy częstotliwość taktowania dla procedury delay
#include <avr/io.h>        // dołączamy makra nazw rejestrów AVR
#include <avr/interrupt.h> // dołączamy makra obsługi systemu przerwań
#include <util/delay.h>    // dołączamy procedury opóźnienia

ISR(TIMER0_COMP_vect)							// procedura obsługi przerwania przy porównaniu timera 0
{
    uint8_t w, k;    // deklarujemy zmienne do zapamiętania aktywnego wiersza i kolumny
    w = PIND | 0xf0; // zapamiętujemy aktywny wiersz w zmiennej w
    // aktywny wiersz = 0, reszta bitów = 1)
    if (w != 0xff) // jeśli którykolwiek przycisk został wciśnięty
    {
        DDRD = 0x0f;     // zmieniamy kierunki linii w PD na przeciwny
        PORTD = 0xf0;    // podciągamy zasilanie do wejść oraz ustawiamy wyjścia w stan niski
        _delay_us(10);   // przeczekujemy stan przejściowy
        k = PIND | 0x0f; // zapamiętujemy aktywną kolumnę w zmiennej k
        // aktywna kolumna = 0, reszta bitów = 1
        DDRD = 0xf0;  // zmieniamy kierunek linii w PD na przeciwny (przywracamy stan wyjściowy)
        PORTD = 0x0f; // przywracamy stan wyjściowy PORTD

        w = ~w;        // negujemy zmienną w (aktywny wiersz = 1; reszta bitów = 0)
        k = ~k;        // negacja zmiennej k (aktywna kolumna = 1; reszta bitów = 0)
        PORTA = w | k; // kodujemy numer wciśnietego klawisza na diodach na PA
    }
}

int main(void)									// program główny
{
    DDRA = 0xff;  // ustawiamy całe PA na wyjście (linijka diod)
    DDRC = 0xff;  // ustawiamy całe PC na wyjście (linijka diod)
    DDRD = 0xf0;  // ustawiamy PD0-3 na wejście (wiersze), PD4-7 na wyjście (kolumny)
    PORTD = 0x0f; // podciągamy zasilanie do wejść oraz ustawiamy wyjścia w stan niski

    TIMSK |= _BV(OCIE0);                         // włączamy obsługę przerwania przy porównaniu timera0
    OCR0 = 38;                                   // ustawiamy wartość końcową zliczania w OCR0 (przerwanie co 38,9ms)
    TCCR0 |= _BV(WGM01) | _BV(CS00) | _BV(CS02); // ustawiamy timer0 w tryb CTC, skalowanie clk/1024

    PORTC = 0xff; // wstępnie włączamy wszystkie diody na PC

    sei(); // włączamy globalną obsługę przerwań

    while (1) // pętla główna - animacja na PC
    {
        _delay_ms(150); // czekamy 150ms
        PORTC = ~PORTC; // zmieniamy stan diod na PC na przeciwny
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Zadanie 1 v3

PA0-7 = LED0-7
PC0-7 = a, b, ..., dp
PD0-3 = W1-4
PD4-7 = K1-4
C1 = GND
*/
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (TIMER0_COMP_vect) {						// Przerwanie TIMER0
    if ((PIND & 0x0F) != 0x0F)
    {
        uint8_t wiersz = PIND;   // 0 na miejscu wcisnietego wiersza
        wiersz = ~wiersz & 0x0F; // 1 na miejscu wcisnietego wiersza i 0 nareszcie bitow

        DDRD ^= 0xFF;  // Zmienienie wejscia z wierszy na kolumny
        PORTD ^= 0xFF; // Zmienienie podciagnięcia zasilania z wierszy na kolumny

        _delay_us(5); // Opoznienie zeby stan PIND sie zaaktualizowal

        uint8_t kolumna = PIND;    // 0 na miejscu wcisnietej kolumny
        kolumna = ~kolumna & 0xF0; // 1 na miejscu wcisnietej kolumny i 0 na reszcie

        DDRD ^= 0xFF; // Powrót do stanu pierwotnego
        PORTD ^= 0xFF;

        PORTA = kolumna | wiersz; // Ustawienie numeru wcisnietego wiersza i kolumny napasku LED
    }
}
int main(void)
{
    DDRA = 0xFF;                                       // PORTA WYJ
    DDRC = 0xFF;                                       // PORTC WYJ
    DDRD = 0xF0;                                       // Wiersze na wyjscie kolumny wejscie
    PORTD = 0x0F;                                      // Podciagniecie zasilania na kolumny
    OCR0 = 50;                                         // Top na 50ms
    TIMSK |= (1 << OCIE0);                             // Przerwania na timer0
    TCCR0 |= (1 << CS02) | (1 << CS00) | (1 << WGM01); // Tryb CTC i preskaler 1024
    sei();                                             // Globalna obsluga przerwan ON
    while (1)
    {
        PORTC ^= 0xFF; // Animacja na porcie C
        _delay_ms(150);
        asm("nop");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Zadanie 2

// PD0-3=W1-W4; PD4-7=K1-K4; PA0-7=a-dp; PC0-7=D0-7; C4=GND
#define F_CPU 1000000L     // definiujemy częstotliwość taktowania dla procedur delay
#include <avr/io.h>        // dołączamy makra nazw rejestrów AVR
#include <avr/interrupt.h> // dołączamy makra obsługi systemu przerwań
#include <util/delay.h>    // dołączamy procedury opóźnienia

uint8_t k=0;									// deklarujemy zmienną - sprawdzana kolumna

ISR(TIMER0_COMP_vect)							// procedura obsługi przerwania przy porównaniu timera0
{
    uint8_t w, wLicznik = 0; // zmienne pomocnicze do zapamiętania aktywnego wiersza oraz kolumny
    PORTD &= ~_BV(k + 4);    // ustawiamy stan niski na aktywnej kolumnie
    _delay_us(10);           // przeczekujemy stan przejściowy
    w = PIND | 0xf0;         // zapamiętujemy aktywny wiersz w zmiennej w
                             // aktywny wiersz = 0, reszta bitów = 1
    PORTD |= _BV(k + 4);     // przywracamy stan wysoki na aktywnej kolumnie
    if (w != 0xff)           // jeżeli którykolwiek przycisk został wciśnięty...
    {
        w = ~w;                    // negujemy kod aktywnego wiersza (1 = aktywny, 0 = nieaktywny)
        while (w != _BV(wLicznik)) // sprawdzamy numer wiersza
        {
            wLicznik++; // inkrementujemy numer wiersza
        }
        PORTA = (4 * wLicznik + k + 1); // ustawiamy numer przycisku na PA
    }
    k++;       // inkrementujemy numer kolumny
    if (k > 3) // jeżeli sprawdzono wszystkie kolumny...
    {
        k = 0; // ustawiamy numer kolumny na 0
    }
}

int main(void)									// program główny
{
    DDRA = 0xff;  // ustawiamy całe PA na wyjście (linijka diod)
    DDRC = 0xff;  // ustawiamy całe PC na wyjście (linijka diod)
    DDRD = 0xf0;  // PD0-3 na wejście (wiersze), PD4-7 na wyjście (kolumny)
    PORTD = 0xff; // podciągamy zasilanie do wejść oraz ustawiamy wyjścia w stan wysoki

    TIMSK |= _BV(OCIE0);                         // włączamy obsługę przerwania przy porównaniu timera0
    OCR0 = 38;                                   // wartość końcowa zliczania (przerwanie co 38,9ms)
    TCCR0 |= _BV(WGM01) | _BV(CS00) | _BV(CS02); // ustawienie timera 0 w tryb CTC, preskaler clk/1024

    PORTC = 0x0f; // wstępnie włączamy diody na PC0-3

    sei(); // włączamy globalną obsługę przerwań

    while (1) // pętla główna - animacja na porcie C
    {
        _delay_ms(150); // czekamy 150ms
        PORTC ^= 0x0f;  // zmieniamy stan diod na PC0-3 na przeciwny
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Zadanie 2 v2

PA0-7 = LED0-7
PC0-7 = a, b, ..., dp
PD0-3 = W1-4
PD4-7 = K1-4
C1 = GND
*/
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t licznik = 0;

int odkoduj(int x){
    if (x == 8)
        return 4;
    if (x == 4)
        return 3;
    if (x == 2)
        return 2;
    if (x == 1)
        return 1;
    return 0;
}

ISR (TIMER0_COMP_vect) {
    if (licznik >= 4)
    {
        licznik = 0;
    }

    PORTD = (~(1 << (licznik + 4)) & 0xF0) | 0x0F; // 0 na sprawdzany wiersz reszta wierszy 1, kolumny na 1
    _delay_us(5);                                  // opoznienie aby zaaktualizowal sie PIND
    if ((PIND & 0x0F) != 0x0F)
    {
        PORTA = (odkoduj(~PIND & 0x0F) - 1) * 4 + licznik + 1; // zamienienie wcisnietego klawisza na liczbe calkowita i wypisanie jej na porcie A
    }

    licznik++;
}

int main(void)
{
    DDRA = 0xFF;  // PORTA WYJ
    DDRC = 0xFF;  // PORTC WYJ
    DDRD = 0xF0;  // Wiersze na wyjscie kolumny wejscie
    PORTD = 0x0F; // Podciagniecie zasilania na kolumny

    OCR0 = 50;                                         // Top na 50ms
    TIMSK |= (1 << OCIE0);                             // Przerwania na timer0
    TCCR0 |= (1 << CS02) | (1 << CS00) | (1 << WGM01); // Tryb CTC i preskaler 1024
    sei();                                             // Globalna obsluga przerwan ON
    while (1)
    {
        PORTC ^= 0xFF; // Animacja na porcie C
        _delay_ms(150);
        asm("nop");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Z1 z zaocznych

#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (INT0_vect) 								// Przerwanie INT0 
{
    cli(); // Upewniam się że nie dojdzie do wykonania przerwania podczas tego przerwania
    PORTB += 1;
    for (int i = 0; i < 4; i++)
    {
        PORTD = (~_BV(i + 4) & 0xF0) | (PORTD & 0x0F); // Ustawiam 0 na danym bicie i resztę na 1 (pomijam młodsze bity)
        _delay_us(10);
        if (!(PIND & 0x04)) // Sprawdzam czy dany klawisz jest naciśnięty
        {
            PORTA = (PORTA & 0x0F) | (((i + 1) << 4) & 0xF0);
        }
    }

    PORTD &= 0x0F;

    GIFR |= 0b01000000; // upewniam się że nie dojdzie do pasożytniczych przerwań

    sei(); // Włączam obsługę przerwań
}

ISR (INT1_vect) 				// Przerwanie INT1 
{
    cli(); // Upewniam się że nie dojdzie do wykonania przerwania podczas tego przerwania
    PORTC += 1;
    for (int i = 0; i < 4; i++)
    {
        PORTD = (~_BV(i + 4) & 0xF0) | (PORTD & 0x0F); // Ustawiam 0 na danym bicie i resztę na 1 (pomijam młodsze bity)
        _delay_us(10);
        if (!(PIND & 0x08))
        {
            PORTA = (PORTA & 0x0F) | (((i + 5) << 4) & 0xF0); // Sprawdzam czy dany klawisz jest naciśnięty
        }
    }

    PORTD &= 0x0F;

    GIFR |= 0b10000000; // upewniam się że nie dojdzie do pasożytniczych przerwań

    sei();
}

int main(void)
{
    DDRA = 0xFF; // Ustawiam PORT A,B i C jako wejście
    DDRB = 0xFF;
    DDRC = 0xFF;

    DDRD = 0xF0; // Ustawiam 4 starsze bity portu D jako wejście

    PORTD |= 0x0C; // Podciągam pod zasilanie 2 i 3 PIND

    MCUCR |= 0x0A; // Ustawienie aktywacji obu przerwań w tryb falling-edge;

    GICR |= 0xC0; // Włączenie przerwań INT0 i INT1

    sei(); // Włączam globalną obsługę przerwań

    while (1)
    {

        PORTA ^= 0x0F; // Wykonuję animację
        _delay_ms(50); // opóźnienie 50ms
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Z1 z zaocznych

#define F_CPU 4000000L     // definiujemy częstotliwości taktowania dla procedur delay
#include <avr/io.h>        // dołączamy makra nazw rejestrów AVR
#include <avr/interrupt.h> // dołączamy makra obsługi systemu przerwań
#include <util/delay.h>    // dołączamy procedury opóźnienia

void ktoryPrzycisk(uint8_t w)					// procedura obsługi multipleksowej
{
    uint8_t pom, k = 4; // deklarujemy zmienną pomocniczą oraz zmienną k (do kolumn)
    PORTD |= 0xf0;      // ustawiamy wyjścia (kolumny) w stan wysoki
    while (k < 7)       // tak długo jak numer kolumny jest mniejszy niż 7...
    {
        PORTD &= ~_BV(k);     // ustawiamy stan niski na sprawdzanej kolumnie
        asm("nop");           // przeczekujemy stan przejściowy
        if (!(PIND & _BV(w))) // jeśli na wejściu jest 0 to...
        {
            break; // przerywamy wykonywanie pętli
        }
        PORTD |= _BV(k); // przywracamy stan wysoki na sprawdzanej kolumnie
        k++;             // zwiększamy numer sprawdzanej kolumny
    }
    PORTD &= 0x0f; // przywracamy stan niski na wyjściach (kolumnach)
    if (w == 2)    // jeśli numer wiersza to 2 (INT0, wiersz 0)...
    {
        k -= 3; // odejmij 3 od numeru kolumny (użyjemy go jako numeru klawisza)
    }
    else // w przeciwnym razie (INT1, wiersz 1)...
    {
        k++; // zwiększ numer kolumny o 1 (użyjemy go jako numeru klawisza)
    }
    k = k << 4;  // przesuwamy wartość numeru kolumny na starsze bity (4-7)
    pom = PORTA; // wczytujemy stan PORTA do zmiennej pomocniczej
    pom &= 0x0f; // ustawiamy 0 na  bitach 4-7
    pom |= k;    // ustawiamy numer klawisza na bitach 4-7
    PORTA = pom; // wyświetlamy numer wciśnietego klawisza na PA
}

ISR(INT0_vect)									// procedura obsługi przerwania INT0
{
    ktoryPrzycisk(2);   // wywołujemy procedurę zczytywania klawisza
    PORTB++;            // zwiększamy wartość na PB i ją wyświetlamy
    GIFR |= _BV(INTF0); // neutralizujemy pasożytnicze przerwanie
}

ISR(INT1_vect)									// procedura obsługi przerwania INT1
{
    ktoryPrzycisk(3);   // wywołujemy procedurę zczytywania klawisza
    PORTC++;            // zwiększamy wartość na PC i ją wyświetlamy
    GIFR |= _BV(INTF1); // neutralizujemy pasożytnicze przerwanie
}

int main(void)
{
    DDRA = 0xff; // ustawiamy całe PA na wyjście (linijka diod)
    DDRB = 0xff; // ustawiamy całe PB na wyjście (linijka diod)
    DDRC = 0xff; // ustawiamy całe PC na wyjście (linijka diod)
    DDRD = 0xf0; // ustawiamy PD0-3 na wejście (na PD2 i PD3 są wiersze), PD4-7 na wyjście (kolumny)

    PORTB = 0;    // wstępnie gasimy wszystkie diody na PB
    PORTC = 0;    // wstępnie gasimy wszystkie diody na PC
    PORTD = 0x0f; // podciągamy zasilanie do wejść i ustawamy wyjścia w stan niski

    // ustawiamy obsługę przerwań INT0 i INT1 na falling edge
    MCUCR |= _BV(ISC01) | _BV(ISC11) & ~_BV(ISC00) & ~_BV(ISC10);

    GICR |= _BV(INT0) | _BV(INT1); // włączamy obsługę przerwań INT0 i INT1

    sei(); // włączamy globalną obsługę przerwań

    PORTA = 0x0f; // wstępnie włączamy diody na PA0-3

    while (1)
    {
        _delay_ms(50); // czekamy 50 ms
        PORTA ^= 0x0f; // zmieniamy stan diod PA0-3 na przeciwny
    }
}

// erys

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#define F_CPU 1000000UL


volatile uint8_t liczba=0; //przechowująca ilosc wprowadzanych liczb
volatile uint8_t licznik=0;  //Zmienna służąca do sterowania modułami wyświetlacza
volatile uint8_t odczekanie=40; //zmienna potzrbna do odczekania chwili zamin mozna bedzie wprowadzic nastepna liczbe
const uint8_t kody[] PROGMEM ={
    ~(0x3F),~(0x06),~(0x5B),~(0x4F),~(0x66),~(0x6D),~(0x7D),~(0x07),~(0x7F),~(0x6F),~(0x77),~(0x7C),~(0x39),~(0x5E),~(0x79),~(0x71),~(0x0)}; //Tablica przechowująca kody 7-segmentowe zapisana w pamięci programu.
uint8_t segmenty[]={16,16,16,16}; //Tablica przechowująca znaki które chcemy wyświetlić.

ISR(TIMER0_COMP_vect){
    PORTD |= 0b11110000; // Ustawenie wszystkich modułów na 1, tak, aby program nie wyświetlał nic przez chwilę. Pozwoli nam to na zmienienie wyświetlanego kodu bez wyświetlania go na złym module.
    PORTA = pgm_read_byte(&kody[segmenty[licznik]]);
    PORTD &= ~(1 << (licznik + 4));  // Włączenie wyświetlania na odpowiednim module.
    _delay_us(3);                    // odczekanie stanów
    uint8_t wiersz = (~PIND) & 0x0F; // zapisanie stanu wierszy
    if (wiersz && (odczekanie == 40))
    { // jeśli jakis przycisk zpstał wciśnięty oraz upłyną czas na blokowanie wprowadzania
        if (wiersz == 8)
        { // zamiana wiersza na cyfre
            wiersz = 3;
        }
        else
        {
            wiersz = wiersz >> 1;
        }
        if (liczba < 4)
        {
            segmenty[3] = se 0xFFF cznik + (wiersz * 4); // Wyświetlenie numeru przycisku, dodajemy 1 gdyż liczymy od 1
            liczba = liczba + 1;
            odczekanie = 0;
        }
    }
    if (odczekanie < 40)
    {
        odczekanie = odczekanie + 1;
    }
    licznik = (licznik + 1) & 0b11;
}

int main(void) {
    DDRD = 0xF0;                         // kolumny klawiatury i wyswietlacza na wyjscie
    PORTD = 0xFF;                        // kolumny i wiersze podciagniete do zasilania
    DDRA = 0xFF;                         // segmenty na wyjscie
    PORTA = 0xFF;                        // zgaszenie wszyskich segmentów
    OCR0 = 49;                           // 5 ms
    TCCR0 |= (1 << WGM01) | (1 << CS02); // tim0 w trybie ctc preskaler 256
    TIMSK |= (1 << OCIE0);               // wlaczenie przerwania porównania tim0
    sei();

    while (1)
    {
    }

    return 0;
}
  
--------------------------------------------------------------------------------------------
//zad2
  PMC_PCER=1<<10;
  PIOB_PDR=1<<20 | 1<<19;
  PIOB_ASR=1<<20 | 1<<19;
  PWM_ENA=1<<1 | 1<<0;
 
  PWM_CMR1=1<<0 | 1<<3; //Prescaler 512
  //0.5=512x/48 000 000
  //x=46875
  PWM_CPRD1=46875;
  //80% z x = 37500
  PWM_CDTY1=37500;
 
  PWM_CMR0=1<<1 | 1<<2; //Prescaler 64
  //0.001=64x/48 000 000
  //x=750
  PWM_CPRD0=750;
  //50% z x = 375
  PWM_CDTY0=375;
