#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordSearch.h"



int main(void){
    int exceptList[4] = {20, 20, 20, 20};
    char Grid[20][20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "DAYANA", "LOREN", "LEANDRO", "MILLENA"};
    gridFiller(Grid);
    exceptList[0] = horizontalWordPlacer(Grid, *(Nomes), exceptList);
    exceptList[1] = horizontalWordPlacer(Grid, *(Nomes + 1), exceptList);
    exceptList[2] = horizontalWordPlacer(Grid, *(Nomes + 2), exceptList);
    exceptList[3] = horizontalWordPlacer(Grid, *(Nomes + 3), exceptList);
    exceptList[0] = 20;
    exceptList[1] = 20;
    exceptList[2] = 20;
    exceptList[3] = 20;
    exceptList[0] = verticalWordPlacer(Grid, *(Nomes + 4), exceptList);
    exceptList[1] = verticalWordPlacer(Grid, *(Nomes + 5), exceptList);
    exceptList[2] = verticalWordPlacer(Grid, *(Nomes + 6), exceptList);
    exceptList[3] = verticalWordPlacer(Grid, *(Nomes + 7), exceptList);
    gridPlot(Grid);
    system("Pause");
    return(0);
}
