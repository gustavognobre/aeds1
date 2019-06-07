#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <assert.h> //Faz asserções no código. Isso funciona como teste unitário.
#include "Programa.h"
#include "Selecao.h"

Programa Altera_Programa(Programa A, int codigo) {
    printf("\n\n=========ALTERAR PROGRAMA=========\n");
    A.codigo = codigo;
    printf("Nome atual: %s\n", A.nome);
    printf("Informe o novo nome: ");
    scanf(" %[^\n]", A.nome);
    printf("\nDiretor atual: %s\n", A.direcao);
    printf("Informe o novo Diretor: ");
    scanf("%s", A.direcao);
    printf("\nGenero atual: %s\n", A.genero);
    printf("Informe o novo Genero: ");
    scanf("%s", A.genero);
    printf("\nSinopse Atual: %s\n", A.sinopse);
    printf("Informe a nova Sinopse: ");
    scanf(" %[^\n]", A.sinopse);
    printf("\nEstudio atual: %s\n", A.estudio);
    printf("Informe o novo Estudio: ");
    scanf("%s", A.estudio);
    printf("\nHorario de exibicao atual: %d\n", A.exibicao);
    printf("Informe o novo horário: ");
    scanf("%d", &A.exibicao);
    printf("\nDuracao atual: %d\n", A.duracao);
    printf("Informe a nova duracao: ");
    scanf("%d", &A.duracao);
    printf("===============Sensura:");
    return A;
}

void Salva_Registro_Arquivo(Programa A){
    FILE*fp = fopen("database.txt", "rb+");
    if(fp==NULL){
        FILE*fp = fopen("database.txt", "wb+");
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&A, sizeof(Programa), 1, fp);
    fclose(fp);
}

void Altera_Registro_no_Database(Programa A, int codigo){
    Programa B;
    FILE*fp = fopen("database.txt", "rb+");
    if(fp == NULL){
        printf("AVISO: O arquivo database.txt nao foi encontrado, um novo database foi gerado.");
        FILE*fp = fopen("database.txt", "wb+");
    }
    while(fread(&B, sizeof(Programa), 1, fp)){
        if(B.codigo == codigo){
            fseek(fp, -sizeof(Programa), SEEK_CUR);
            fwrite(&A, sizeof(Programa), 1, fp);
            fclose(fp);
        }
    }
}

void Exclui_entrada_do_database(int codigo){
    Programa A;
    strcpy(A.nome, "Deletado");
    strcpy(A.direcao, "");
    strcpy(A.genero, "");
    strcpy(A.estudio, "");
    strcpy(A.sinopse, "");
    A.exibicao = 0;
    A.duracao = 0;
    Programa B;
    FILE*fp = fopen("database.txt", "rb+");
    if(fp == NULL){
        printf("AVISO: O arquivo database.txt nao foi encontrado, um novo database foi gerado.");
        FILE*fp = fopen("database.txt", "wb+");
    }
    fseek(fp, 0, SEEK_SET);
    while(fread(&B, sizeof(Programa), 1, fp)){
        if(B.codigo == codigo){
            fseek(fp, -sizeof(Programa), SEEK_CUR);
            fwrite(&A, sizeof(Programa), 1, fp);
            fclose(fp);
        }
    }
}

void pesquisa_entrada_no_database(codigo){
    Programa B;
    FILE*fp = fopen("database.txt", "rb+");
    fseek(fp, 0, SEEK_SET);
    while(fread(&B, sizeof(Programa), 1, fp)){
        if(B.codigo == codigo){
            int sair;
            printf("===========================================\n");
            printf("PROGRAMA: %s\n", B.nome);
            printf("DIRECAO: %s\n", B.direcao);
            printf("GENERO: %s\n", B.genero);
            printf("SINOPSE: %s\n", B.sinopse);
            printf("ESTUDIO: %s\n", B.estudio);
            printf("HORARIO: %d Horas\n", B.estudio);
            printf("DURACAO: %d Minutos\n", B.duracao);
            printf("===========================================\n");
            printf("Aperte 0 para sair: ");
            scanf("%d", &sair);
            if(sair == 0){
                break;
            }
        }
    }
    fclose(fp);
}

void lista_entradas_do_database(codigo){
    int sair;
    Programa B;
    FILE*fp = fopen("database.txt", "rb");
    fseek(fp, 0, SEEK_SET);
    while(fread(&B, sizeof(Programa), 1, fp)){
        printf("===========================================\n");
        printf("PROGRAMA: %s\n", B.nome);
        printf("DIRECAO: %s\n", B.direcao);
        printf("GENERO: %s\n", B.genero);
        printf("SINOPSE: %s\n", B.sinopse);
        printf("ESTUDIO: %s\n", B.estudio);
        printf("HORARIO: %d Horas\n", B.estudio);
        printf("DURACAO: %d Minutos\n", B.duracao);
        printf("===========================================\n");
    }
    fclose(fp);
    printf("Aperte 0 para sair: ");
    scanf("%d", &sair);
    if(sair == 0){
        return 0;
    }
}

void gerar_relatorio(){
    int total = 0;
    int mins = 0;
    Programa B;
    FILE*ft = fopen("relatorio.csv", "a");
    FILE*fb = fopen("database.txt", "r");
    fprintf(ft, "Relatório de Programas\n");
    fseek(fb, 0, SEEK_SET);
    fprintf(ft, "CODIGO,PROGRAMA,DIRECAO,GENERO,SINOPSE,ESTUDIO,HORARIO,DURACAO\n");
    while(fread(&B, sizeof(Programa), 1, fb)){
        fprintf(ft,"%d, %s, %, %s, %s, %s, %d Horas, %d minutos\n",
            B.codigo, B.nome, B.direcao, B.genero, B.sinopse, B.estudio, B.exibicao, B.duracao
        );
        total++;
        mins +=B.duracao;
    }
    fprintf(ft, "Total: %d, Horas de Programação: %d", total, mins/60);
    assert(fb);
    assert(ft);
    fclose(ft);
}

Programa Altera_Registro_Database(int codigo, int modo){
    Programa A;
    FILE*fp = fopen("database.txt", "rb");
    assert(fp);
    fseek(fp, 0, SEEK_SET);
    if(modo == 1){
        while(fread(&A, sizeof(Programa), 1, fp)){
            if(A.codigo == codigo){
                fclose(fp);
                return Altera_Programa(A, codigo);
            }
        }
    }
}

int Menu(){
    int OpcaoAtual;
    TextColor(5);
    Selecao Menu;
    Menu=CriarSelecao(2,12);
    Menu=AdicionarOpcao(Menu,"Inserir");
    Menu=AdicionarOpcao(Menu,"Alterar");
    Menu=AdicionarOpcao(Menu,"Excluir");
    Menu=AdicionarOpcao(Menu,"Pesquisar");
    Menu=AdicionarOpcao(Menu,"listar");
    Menu=AdicionarOpcao(Menu,"Relatorio");
    Menu=AdicionarOpcao(Menu,"Sair");
    TextColor(8);
    Caixa(1,1,90,2);

    while(1){
        MostrarSelecao (Menu);
        gotoxy(0,20);
        OpcaoAtual=AtivarSelecao(Menu);
        if(OpcaoAtual==-1){
            break;
        }
        if(OpcaoAtual==0){
            TelaPrograma();
            system("cls");//inserir
        }
        if(OpcaoAtual==1){
            TelaAlterar();//aterar
            system("cls");
        }
        if(OpcaoAtual==2){
            TelaExcluir();//excluir
            system("cls");
        }
        if(OpcaoAtual==3){
            TelaPesquisar();//pesquisa
            system("cls");
        }
        if(OpcaoAtual==4){
            TelaListar(); //lista
            system("cls");
        }
        if(OpcaoAtual==5){
            gerar_relatorio();
            system("cls");
        }
        if(OpcaoAtual==6){
            break;
        }
    }
    return 0;
}

void TelaPrograma(){
    Programa A;
    Caixa(4,4,74,30);
    gotoxy(20,5);
    printf("=========CADASTRO DE PROGRAMA=========");
    gotoxy(6,8);
    printf("================Codigo:");
    gotoxy(31,8);
    scanf("%d", &A.codigo);
    gotoxy(6,10);
    printf("==================Nome:");
    gotoxy(31,10);
    scanf(" %[^\n]", A.nome);
    gotoxy(6,12);
    printf("===============Direcao:");
    gotoxy(31,12);
    scanf(" %[^\n]", A.direcao);
    gotoxy(6,14);
    printf("================Genero:");
    gotoxy(31,14);
    scanf("%s", A.genero);
    gotoxy(6,16);
    printf("===============Sinopse:");
    gotoxy(31,16);
    scanf(" %[^\n]", A.sinopse);
    gotoxy(6,18);
    printf("===============Estudio:");
    gotoxy(31,18);
    scanf("%s",A.estudio);
    gotoxy(6,20);
    printf("===Horario de Exibicao:");
    gotoxy(31,20);
    scanf("%d",& A.exibicao);
    gotoxy(6,22);
    printf("===============Duracao:");
    gotoxy(31,22);
    scanf("%d",& A.duracao);
    gotoxy(6,24);
    printf("===============Sensura:");
    gotoxy(31,24);

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
    if(!AtivarSelecao(Confirm)){
        Salva_Registro_Arquivo(A);
    }

}

void TelaAlterar(){
    Programa A;
    int codigo;
    gotoxy(20,5);
    printf("============ALTERAR PROGRAMA===========");
    gotoxy(6,8);
    printf("================Codigo:");
    gotoxy(31,8);
    scanf("%d", &codigo);
    A = Altera_Registro_Database(codigo, 1);
    Altera_Registro_no_Database(A, codigo);
}

void TelaExcluir(){
    int codigo;
    gotoxy(20,5);
    printf("============EXCLUIR PROGRAMA===========");
    gotoxy(6,8);
    printf("================Codigo:");
    gotoxy(31,8);
    scanf("%d",&codigo);
    Exclui_entrada_do_database(codigo);
}

void TelaPesquisar(){

int codigo;
    gotoxy(20,5);
    printf("============PESQUISAR PROGRAMA===========");
    gotoxy(6,8);
    printf("================Codigo:");
    gotoxy(31,8);
    scanf("%d",&codigo);
    pesquisa_entrada_no_database(codigo);
}

void TelaListar(){

    gotoxy(20,5);
    printf("============PESQUISAR PROGRAMA===========");
    gotoxy(6,8);
    printf("================Codigo:");
    gotoxy(31,8);
    lista_entradas_do_database();
}
