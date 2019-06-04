#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Programa.h"
#include "Selecao.h"

void TelaPrograma()
{
    Caixa(4,4,74,30);
    gotoxy(20,5);
    printf("=========CADASTRO DE PROGRAMA=========");
    gotoxy(6,8);
    printf("===============Codigo:");
    gotoxy(6,10);
    printf("=================Nome:");
    gotoxy(6,12);
    printf("===Horario de Exibicao:");
    gotoxy(6,14);
    printf("=====Canal de Exibicao:");
    gotoxy(6,16);
    printf("==Direcao do Programa:");
    gotoxy(6,18);
    printf("=Nivel de Popularidade:");
    gotoxy(6,20);
    printf("===Genero do Programa:");
    gotoxy(6,22);
    printf("==========Comentarios:");
    gotoxy(6,24);
    printf("==============Sensura:");
}
Programa DigitarPrograma()
{
    Programa A;
    gotoxy(29,8);
    scanf("%d", &A.codigo);
    gotoxy(29,10);
    scanf(" %[^\n]", A.nome);
    gotoxy(29,12);
    scanf("%d", &A.exibicao);
    gotoxy(29,14);
    scanf(" %[^\n]", A.canal);
    gotoxy(29,16);
    scanf(" %[^\n]", A.direcao);
    gotoxy(29,18);
    scanf("%lf",&A.popularidade);
    gotoxy(29,20);
    scanf(" %[^\n]", A.genero);
    gotoxy(29,22);
    scanf(" %[^\n]", A.comentario);
    gotoxy(29,24);

    Selecao Sensura;
    Sensura=CriarSelecao(26,10);
    Sensura=AdicionarOpcao(Sensura,"L");
    Sensura=AdicionarOpcao(Sensura,"10");
    Sensura=AdicionarOpcao(Sensura,"12");
    Sensura=AdicionarOpcao(Sensura,"14");
    Sensura=AdicionarOpcao(Sensura,"16");
    Sensura=AdicionarOpcao(Sensura,"18");
    MostrarSelecao(Sensura);
    AtivarSelecao(Sensura);

    Selecao Confirm;
    Confirm=CriarSelecao(28,10);
    Confirm=AdicionarOpcao(Confirm,"Confirma");
    Confirm=AdicionarOpcao(Confirm,"Cancela");
    MostrarSelecao(Confirm);
    AtivarSelecao(Confirm);
    FILE*fp = fopen("lala.txt", "ab");
    fwrite(&A, sizeof(Programa), 1, fp);
    fclose(fp);
    return A;
}
