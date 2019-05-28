#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Selecao.h"

void TelaAluno()
{
    Caixa(4,4,74,15);
    gotoxy(20,5);
    printf("Cadastro de Alunos");
    gotoxy(6,8);
    printf("Matricula : ");
    gotoxy(6,10);
    printf("Nome : ");
    gotoxy(6,12);
    printf("Telefone : ");
    gotoxy(6,14);
    printf("Mensalidade : ");
}
Aluno DigitarAluno()
{
    Aluno A;
    gotoxy(21,8);
    scanf("%d", &A.matricula);
    gotoxy(21,10);
    scanf(" %[^\n]", A.nome);
    gotoxy(21,12);
    scanf("%s", A.telefone);
    gotoxy(21,14);
    scanf("%lf",&A.mensalidade);
    Selecao Confirm;
    Confirm=CriarSelecao(17,10);
    Confirm=AdicionarOpcao(Confirm, "Confirma");
    Confirm=AdicionarOpcao(Confirm, "Cancela");
    MostrarSelecao(Confirm);
    AtivarSelecao(Confirm);
    return A;
}
