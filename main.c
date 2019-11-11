#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordSearch.h"

void gridPlot(const char *Grid){
    int i, j;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++)
            printf(" %c ", *(Grid + 20*i + j));
        puts("\n");
    }return;
}

void gridFiller(char *Grid){
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++){
            if(j == 10)
                *(Grid + 20*i + j) = 'z';
            else
                *(Grid + 20*i + j) = ' ';
        }
    return;
}

void horizontalWordPlacer(char *Grid, const char *String, const int except){
    int limit = 20 - strlen(String), iniColumn, i, row = -1;
    srand(time(NULL));
    do{
        row = rand()%20;
    }while(row == except);
    iniColumn = rand()%limit;
    for(i = 0; *(String + i) != '\0'; i++){
        if(*(Grid + 20*row + iniColumn + i) != ' ' && *(Grid + 20*row + iniColumn + i) != *(String + i)){
            for(i--; i >= 0; i--)
                *(Grid + 20*row + iniColumn + i) = ' ';
            iniColumn = rand()%limit;
        }
        *(Grid + 20*row + iniColumn + i) = *(String + i);
    }
    return;
}



int main(void){
    char Grid[20][20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "DAYANA", "LOREN", "LEANDRO", "MILLENA"};
    gridFiller(Grid);
    horizontalWordPlacer(Grid, *(Nomes + 19), 20);
    gridPlot(Grid);
    system("Pause");
    return(0);
}
