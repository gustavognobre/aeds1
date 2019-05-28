#include "Teclas.h"

int getTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}
