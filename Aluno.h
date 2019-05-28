#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
struct aluno
{
    int matricula;;
    char nome[51];
    char telefone [21];
    double mensalidade;
};
typedef struct aluno Aluno;
void TelaAluno();
Aluno DigitarAluno();

#endif // ALUNO_H_INCLUDED
