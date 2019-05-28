#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas[101], i, N, T, j, Id, X, pos, cl;
    char Comando[10];
    scanf("%d", &N);
    for (i=0;i<N;i++)
    {
        pos = 0;
        cl = 1;
        scanf("%d", &T);
        for (j=0;j<T;j++)
        {
            scanf("Comando);
            if (strcmp(Comando, "LEFT")==0)
            {
                X = -1;

            }
            if (strcmp(Comando, "RIGHT")==0)
            {
                X = 1;

            }
            if (strcmp(Comando, "SAME")==0)
            {
                scanf("%s", Comando);
				scanf("%d", &Id)
                X = linhas[Id];
            }
            pos = pos + X;
            linhas[cl++] = X;
        }
        printf("%d\n", pos);
    }
    return 0;
}
