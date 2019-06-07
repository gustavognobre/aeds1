#include <stdio.h>
#include <string.h>
#include "Selecao.h"
#include "Programa.h"

Selecao CriarSelecao(int Linha, int Tamanho)
{
    Selecao S;
    S.Linha=Linha;
    S.Tamanho=Tamanho;
    S.OpcaoAtual=0;
    S.QtdeOpcoes=0;
    return S;
}
Selecao AdicionarOpcao(Selecao S, char Opcao[])
{
    strcpy(S.Opcoes[S.QtdeOpcoes++],Opcao);
    return S;
}
void MostrarSelecao(Selecao S)
{
    int i;
    for(i=0; i<S.QtdeOpcoes; i++)
    {
        gotoxy(5+(i*S.Tamanho), S.Linha);
        printf(" %*s ", -(S.Tamanho-2),S.Opcoes[i]);
    }
}
int AtivarSelecao(Selecao S)
{
    int Tecla;
    while(1)
    {
        gotoxy(5+(S.OpcaoAtual*S.Tamanho),S.Linha);
        TextColor(5);
        printf("%*s", -(S.Tamanho-2),S.Opcoes[S.OpcaoAtual]);
        Tecla=getTecla();
        gotoxy(5+(S.OpcaoAtual*S.Tamanho),S.Linha);
        TextColor(8);
        if (Tecla==TEC_ENTER)
            return S.OpcaoAtual;
        printf(" %*s ", -(S.Tamanho-2),S.Opcoes[S.OpcaoAtual]);
        if (Tecla==TEC_DIR)
            S.OpcaoAtual++;
        if (Tecla==TEC_ESQ)
            S.OpcaoAtual--;
        if (Tecla==TEC_ESC)
            return -1;
        if (S.OpcaoAtual>=S.QtdeOpcoes)
            S.OpcaoAtual=0;
        if (S.OpcaoAtual<0)
            S.OpcaoAtual=S.QtdeOpcoes-1;

    }
}
