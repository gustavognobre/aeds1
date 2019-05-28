#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Teclas.h"
#include "Tela.h"
#include "Selecao.h"
#include "Programa.h"

int main()
{
    int OpcaoAtual;
    Programa A;
    Selecao Menu;
    Menu=CriarSelecao(2,14);
    Menu=AdicionarOpcao(Menu,"Inserir");
    Menu=AdicionarOpcao(Menu,"Pesquisar");
    Menu=AdicionarOpcao(Menu,"Alterar");
    Menu=AdicionarOpcao(Menu,"Excluir");
    Menu=AdicionarOpcao(Menu,"listar");
    Menu=AdicionarOpcao(Menu,"Sair");
    Caixa(1,1,90,2);

    while(1)
    {
        MostrarSelecao(Menu);
        gotoxy(0,20);
        OpcaoAtual=AtivarSelecao(Menu);
        if (OpcaoAtual==-1)
            break;
        if (OpcaoAtual==0)
        {
            TelaPrograma();
            A=DigitarPrograma();
        }
    }system("cls");

    return 0;
}
