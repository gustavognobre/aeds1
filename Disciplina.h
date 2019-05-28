#ifndef DISCIPLINA_H_INCLUDED
#define DISCIPLINA_H_INCLUDED

struct Disciplina
int Codigo;
char Nome[51];
double CH;
char Professor[51];
typedef struct Disciplina Disciplina;
Disciplina DigitarDisciplina();
void MostrarDisciplina( Disciplina A );

#endif // DISCIPLINA_H_INCLUDED
