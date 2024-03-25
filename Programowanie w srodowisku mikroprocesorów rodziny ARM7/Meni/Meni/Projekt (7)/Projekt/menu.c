#include <targets\AT91SAM7.h>
#include "ioLib.h"
// #include "fonts.h"
// #include "includeBitmapArrays.h"

#define NULL 0

typedef struct menu_struct menu_t;

struct menu_struct
{
    const char *name;
    menu_t *next;   // Nast�pny element
    menu_t *prev;   // Poprzeni element
    menu_t *child;  // Dziecko danego wska�nika
    menu_t *parent; // Rodzic danego wska�nika
    void (*menu_function)(void);
};

menu_t menu_1, menu_2, menu_3, sub_menu_1_1, sub_menu_1_2,
    sub_menu_2_1, sub_menu_2_2, sub_menu_3_1, sub_menu_3_2;

menu_t menu_0 = {
    "MENU 0 ",
    &menu_1,
    &menu_2,
    NULL,
    NULL,
    NULL,
};
menu_t menu_1 = {
    "MENU 1 ",
    &menu_0,
    NULL,
    &sub_menu_1_1,
    NULL,
    NULL,
};
menu_t sub_menu_1_1 = {
    "FUNKCJA 1",
    &sub_menu_1_2,
    &sub_menu_1_1,
    NULL,
    &menu_1,
    NULL,
};
menu_t sub_menu_1_2 = {
    "FUNKCJA 2",
    NULL,
    &sub_menu_1_1,
    NULL,
    &menu_1,
    NULL,
};
menu_t menu_2 = {
    "MENU 2 ",
    &menu_0,
    NULL,
    &sub_menu_2_1,
    NULL,
    NULL,
};
menu_t sub_menu_2_1 = {
    "FUNKCJA 1",
    &sub_menu_2_2,
    &sub_menu_2_1,
    NULL,
    &menu_2,
    NULL,
};
menu_t menu_3 = {
    "MENU 3 ",
    NULL,
    &menu_1,
    NULL,
    NULL,
    NULL,
};

menu_t *currentPointer = &menu_0;              // Aktualny wska�nik
char menu_index;                               // Numer aktualnie wybranego elementu nadanym poziomie
char lcd_row_pos;                              // Numer pozycji menu na LCD
char lcd_row_pos_level_1, lcd_row_pos_level_2; // Numerpozycji menu na LCD dla ni�szych poziom�w

void drawBoard()
{
    char spacing = 10;

    LCDClearScreenColored(GREEN);
    LCDSetRect(spacing, spacing, 130 - spacing, 130 - spacing, 0, BLACK);
    // drawWindow();
}

void drawBlock(const char *text, char row, char level)
{
    char spacing = 10;
    char row_pos = spacing * (row + 2) + (row * spacing);
    char level_pos = spacing + (level * 20) + 10;
    if (row == 0)
    {
        level_pos = spacing;
        row_pos = spacing;
    }
    char text_length = strlen(text);
    char text_pos = row_pos + spacing / 2;

    LCDSetRect(row_pos, level_pos, row_pos + spacing * 2, level_pos + text_length * 8, 1, YELLOW);
    LCDSetRect(row_pos, level_pos, row_pos + spacing * 2, level_pos + text_length * 8, 0, BLACK);

    LCDPutStr(text, text_pos, level_pos + spacing / 5, MEDIUM, BLACK, RED, TRANSPARENTBG);
}

void drawPointer(char row, char level)
{
    char spacing = 10;
    char row_pos = spacing * (row + 2) + (row * spacing);
    char level_pos = spacing + (level * 20) + 10;
    char text_length = strlen(currentPointer->name);
    char text_pos = row_pos + spacing / 2;

    LCDSetRect(row_pos, level_pos, row_pos + spacing * 2, level_pos + text_length * 8 + spacing / 5, 1, YELLOW);
    LCDSetRect(row_pos, level_pos, row_pos + spacing * 2, level_pos + text_length * 8 + spacing / 5, 0, BLACK);

    LCDPutStr("<", text_pos, level_pos + spacing / 5, MEDIUM, BLACK, RED, TRANSPARENTBG);
}

void drawWindow(char position)
{
    drawBoard();
    // make an interupt to redraw pointer
    // draw each menu using drawBlock
    char counter = 1;
    drawBlock(currentPointer->name, 0, 0);
    if (currentPointer->child != NULL)
    {
        drawBlock(currentPointer->child->name, counter, 0);
        counter++;
    }
    if (currentPointer->next != NULL)
    {
        drawBlock(currentPointer->next->name, counter, 0);
        counter++;
    }
    if (currentPointer->prev != NULL)
    {
        drawBlock(currentPointer->prev->name, counter, 0);
        counter++;
    }
    drawBlock("<= ", position, 3);
}

void menu()
{
    drawBoard();
    char isChanged = 1;
    char pos = 1;
    drawWindow(pos);
    while (1)
    {
        if ((PIOA_PDSR & JOY_UP) == 0 && isChanged == 0)
        {
            isChanged = 1;
            if (pos != 1)
            {
                pos--;
            }
            drawWindow(pos);
        }
        if ((PIOA_PDSR & JOY_DOWN) == 0 && isChanged == 0)
        {
            isChanged = 1;
            if (pos != 2)
            {
                pos++;
            }
            drawWindow(pos);
        }
        if ((PIOA_PDSR & SW_1) == 0 && isChanged == 0)
        {
            isChanged = 1;
            currentPointer = currentPointer->next;
            drawWindow(0);
        }
        if ((PIOA_PDSR & SW_2) == 0 && isChanged == 0)
        {
            currentPointer = currentPointer->prev;
            isChanged = 1;
            drawWindow(0);
        }
        if (isChanged == 1)
        {
            Delay(10000);
            isChanged = 0;
        }
    }
}
