#include "wordSearch.h"

int main(void){
    int exceptList[8] = {20, 20, 20, 20, 20, 20, 20, 20}, i, j, aux;
    int resetKey = 0;
    char Grid[20][20], Rev[20], Search[20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "DAYANA", "LOREN", "LEANDRO", "MILLENA"};


    do{
        gridDotFiller(Grid);

        exceptList[0] = horizontalWordPlacer(Grid, *(Nomes), exceptList, &resetKey);
        exceptList[1] = horizontalWordPlacer(Grid, *(Nomes + 1), exceptList, &resetKey);
        exceptList[2] = horizontalWordPlacer(Grid, *(Nomes + 2), exceptList, &resetKey);
        exceptList[3] = horizontalWordPlacer(Grid, *(Nomes + 3), exceptList, &resetKey);
        reverseString(*(Nomes + 4), Rev);
        exceptList[4] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        reverseString(*(Nomes + 5), Rev);
        exceptList[5] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        reverseString(*(Nomes + 6), Rev);
        exceptList[6] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        reverseString(*(Nomes + 7), Rev);
        exceptList[7] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        resetList(exceptList);

        exceptList[0] = verticalWordPlacer(Grid, *(Nomes + 8), exceptList, &resetKey);
        if(resetKey)
            continue;
        exceptList[1] = verticalWordPlacer(Grid, *(Nomes + 9), exceptList, &resetKey);
        if(resetKey)
            continue;
        exceptList[2] = verticalWordPlacer(Grid, *(Nomes + 10), exceptList, &resetKey);
        if(resetKey)
            continue;
        exceptList[3] = verticalWordPlacer(Grid, *(Nomes + 11), exceptList, &resetKey);
        if(resetKey)
            continue;
        reverseString(*(Nomes + 12), Rev);
        exceptList[4] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        if(resetKey)
            continue;
        reverseString(*(Nomes + 13), Rev);
        exceptList[5] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        if(resetKey)
            continue;
        reverseString(*(Nomes + 14), Rev);
        exceptList[6] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        if(resetKey)
            continue;
        reverseString(*(Nomes + 15), Rev);
        exceptList[7] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        if(resetKey)
            continue;
        resetList(exceptList);

        exceptList[0] = firstDiagonalWordPlacer(Grid, *(Nomes + 16), exceptList, &resetKey);
        if(resetKey)
            continue;
        exceptList[1] = firstDiagonalWordPlacer(Grid, *(Nomes + 17), exceptList, &resetKey);
        if(resetKey)
            continue;
        resetList(exceptList);

        exceptList[0] = secondDiagonalWordPlacer(Grid, *(Nomes + 18), exceptList, &resetKey);
        if(resetKey)
            continue;
        exceptList[1] = secondDiagonalWordPlacer(Grid, *(Nomes + 19), exceptList, &resetKey);
        if(resetKey)
            continue;
    }while(resetKey);

    gridCharFiller(Grid);
    gridPlot(Grid);

    puts("\n\n\n\n");
    transposeRow(Grid, 5, Search);
    puts(Search);
    if(patternMatch(Search, *(Nomes + 1), &aux))
        printf("\n\nA palavra %s comeca nas cooedenadas (%d, %d)", *(Nomes + 1), 6, aux + 1);
    else
        puts("\n\nPalavra nao achada\n\n");

    system("Pause");
    return(0);
}
