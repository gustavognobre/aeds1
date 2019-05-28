#ifndef SELECAO_H_INCLUDED
#define SELECAO_H_INCLUDED
#include <string.h>
#include "Teclas.h"
#include "Tela.h"

struct selecao
{
    char Opcoes[10][31];
    int Linha;
    int Tamanho;
    int OpcaoAtual;
    int QtdeOpcoes;
};
typedef struct selecao Selecao;
Selecao CriarSelecao(int Linha, int Tamanho);
Selecao AdicionarOpcao(Selecao S, char Opcao[]);
void MostrarSelecao();
int AtivarSelecao();

#endif // SELECAO_H_INCLUDED
