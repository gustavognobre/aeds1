#include <stdio.h>
#include <windows.h>
#include "Tela.h"


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int Cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cor);
}

void Caixa(int x, int y, int l, int h)
{
    gotoxy(x, y);
    putchar((char)high_l);

    gotoxy(x + l, y);
    putchar((char)high_r);

    gotoxy(x, y + h);
    putchar((char)low_l);

    gotoxy(x + l, y + h);
    putchar((char)low_r);
    for (int i = 0; i < l - 1; i++)
    {
        gotoxy(x + i+ 1, y);
        putchar((char)lin);
        gotoxy(x +i+ 1, y + h);
        putchar((char)lin);
    }
    for (int i = 1; i < h; i++)
    {
        gotoxy(x, y + i);
        putchar((char)col);
        gotoxy(x + l, y + i);
        putchar((char)col);
    }
    gotoxy(1, h + 3);
}
