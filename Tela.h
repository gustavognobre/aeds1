#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

enum x { high_l = 218, high_r = 191, low_l = 192, low_r = 217, lin = 196, col = 179 };

void gotoxy(int x, int y);
void TextColor(int Cor);
void Caixa(int X, int Y, int L, int A);

#endif // TELA_H_INCLUDED
