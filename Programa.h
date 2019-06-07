#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

struct programa
{
    int codigo;
    char nome[51];
    char direcao[51];
    char genero[51];
    char sinopse[200];
    char estudio[51];
    char exibicao[5];
    int duracao;
};

typedef struct programa Programa;
void TelaPrograma();
Programa DigitarPrograma();

#endif // PROGRAMA_H_INCLUDED
