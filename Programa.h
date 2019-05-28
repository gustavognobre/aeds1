#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

struct programa
{
    int codigo;
    char nome[51];
    int exibicao;
    char canal[51];
    char direcao[51];
    double popularidade;
    char genero[51];
    char comentario[200];
    int sensura;
};
typedef struct programa Programa;
void TelaPrograma();
Programa DigitarPrograma();

#endif // PROGRAMA_H_INCLUDED
