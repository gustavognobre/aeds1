#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Teclas.h"
#include "Tela.h"
#include "Selecao.h"
#include "Programa.h"

int main(){
    FILE*fb = fopen("database.txt", "rb");
    if(fb == NULL){
        FILE*fb = fopen("database.txt", "wb");
    }
    fclose(fb);
    Menu();
}
