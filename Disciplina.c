#include "Disciplina.h"

Disciplina DigitarDisciplina()
{
    struct Disciplina A;
    printf("Código:\n");
    scanf("%d", &A.Codigo);
    printf("Nome:\n");
    scanf(" %[^\n]", A.Nome);
    printf("Carga horária:\n");
    scanf("%lf", A.CH);
    printf("Professor:\n");
    scanf(" %[^\n]",&A.Professor);
    return A;
}
void MostrarDisciplina(Disciplina A)
{
    printf("Codigo: %d\n", A.Codigo);
    printf("Nome: %s\n", A.Nome);
    printf("Carga Horária: %s\n", A.CH);
    printf("Professor: R$ %.2lf\n", A.Professor);
}
