#include "wordSearch.h"


int main(void){
    int exceptList[8] = {20, 20, 20, 20, 20, 20, 20, 20};
    char Grid[20][20], Rev[20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "DAYANA", "LOREN", "LEANDRO", "MILLENA"};
    gridFiller(Grid);


    exceptList[0] = horizontalWordPlacer(Grid, *(Nomes), exceptList);
    exceptList[1] = horizontalWordPlacer(Grid, *(Nomes + 1), exceptList);
    exceptList[2] = horizontalWordPlacer(Grid, *(Nomes + 2), exceptList);
    exceptList[3] = horizontalWordPlacer(Grid, *(Nomes + 3), exceptList);
    reverseString(*(Nomes + 4), Rev);
    exceptList[4] = horizontalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 5), Rev);
    exceptList[5] = horizontalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 6), Rev);
    exceptList[6] = horizontalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 7), Rev);
    exceptList[7] = horizontalWordPlacer(Grid, Rev, exceptList);
    resetList(exceptList);

    exceptList[0] = verticalWordPlacer(Grid, *(Nomes + 8), exceptList);
    exceptList[1] = verticalWordPlacer(Grid, *(Nomes + 9), exceptList);
    exceptList[2] = verticalWordPlacer(Grid, *(Nomes + 10), exceptList);
    exceptList[3] = verticalWordPlacer(Grid, *(Nomes + 11), exceptList);
    reverseString(*(Nomes + 12), Rev);
    exceptList[4] = verticalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 13), Rev);
    exceptList[5] = verticalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 14), Rev);
    exceptList[6] = verticalWordPlacer(Grid, Rev, exceptList);
    reverseString(*(Nomes + 15), Rev);
    exceptList[7] = verticalWordPlacer(Grid, Rev, exceptList);
    resetList(exceptList);

    exceptList[0] = firstDiagonalWordPlacer(Grid, *(Nomes + 16), exceptList);
    exceptList[1] = firstDiagonalWordPlacer(Grid, *(Nomes + 17), exceptList);
    resetList(exceptList);

    exceptList[0] = secondDiagonalWordPlacer(Grid, *(Nomes + 18), exceptList);
    exceptList[1] = secondDiagonalWordPlacer(Grid, *(Nomes + 19), exceptList);


    gridPlot(Grid);
    system("Pause");
    return(0);
}
