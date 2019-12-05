#include "wordSearch.h"

int main(void){
    int exceptList[8], usedWords[20], i, j, auxIndex = 0, aux = 0, resetKey = 0, op = 0;
    char Grid[20][20], copyGrid[20][20], Rev[20], Search[20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "CAROL", "PIETRA", "LEANDRO", "MARIA"};

    if(!confirm("            !!!Caca Palavras!!!\n\nDeseja comecar? <S/N>"))
        exit(1);

    system("cls");

    do{
        resetList(usedWords, 20);
        resetList(exceptList, 8);
        gridDotFiller(Grid);

        for(i = 0; i < 4; i++){
            if(i == 0)
                exceptList[i] = horizontalWordPlacer(Grid, *(Nomes + randomWord(usedWords, 1)), exceptList, &resetKey);
            else
                exceptList[i] = horizontalWordPlacer(Grid, *(Nomes + randomWord(usedWords, 0)), exceptList, &resetKey);
        }if(resetKey)
            continue;

        for(i = 4; i < 8; i++){
            reverseString(*(Nomes + randomWord(usedWords, 0)), Rev);
            exceptList[i] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        }resetList(exceptList, 8);
        if(resetKey)
            continue;

        for(i = 0; i < 4; i++){
            exceptList[i] = verticalWordPlacer(Grid, *(Nomes + randomWord(usedWords, 0)), exceptList, &resetKey);
        }if(resetKey)
            continue;

        for(i = 4; i < 8; i++){
            reverseString(*(Nomes + randomWord(usedWords, 0)), Rev);
            exceptList[i] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        }resetList(exceptList, 2);
        if(resetKey)
            continue;

        for(i = 0; i < 2; i++){
            exceptList[i] = firstDiagonalWordPlacer(Grid, *(Nomes + randomWord(usedWords, 0)), exceptList, &resetKey);
        }resetList(exceptList, 2);
        if(resetKey)
            continue;

        for(; i < 4; i++){
            exceptList[i] = secondDiagonalWordPlacer(Grid, *(Nomes + randomWord(usedWords, 0)), exceptList, &resetKey);
        }

    }while(resetKey);

    gridCopy(Grid, copyGrid);
    gridCharFiller(Grid);
    invertGrid(Grid, invGrid);
    gridPlot(Grid);
    puts("\n\n\n");
    system("Pause");

    if(!confirm("            !!!Caca Palavras!!!\n\nDeseja mostrar a resolucao? <S/N>"))
        exit(1);
    gridPlot(copyGrid);

    puts("\n\n\nResolucao:\n");

    puts("Palavras na horizontal:\n\n    Orientacao normal:");
    for(i = 0; i < 4; i++){
        showResolution(Grid, *(Nomes + usedWords[i]), 'n');
    }puts("    Orientacao inversa:");
    for(i = 4; i < 8; i++){
        reverseString(*(Nomes + usedWords[i]), Rev);
        showResolution(Grid, Rev, 'r');
    }

    puts("\nPalavras na vertical:\n\n    Orientacao normal:");
    for(i = 8; i < 12; i++){
        showResolution(Grid, *(Nomes + usedWords[i]), 'n');
    }puts("    Orientacao inversa:");
    for(i = 12; i < 16; i++){
        reverseString(*(Nomes + usedWords[i]), Rev);
        showResolution(Grid, Rev, 'r');
    }

    puts("\nPalavras nas diagonais:\n\n    Diagonal principal:");
    for(i = 16; i < 18; i++){
        showResolution(Grid, *(Nomes + usedWords[i]), 'n');
    }puts("    Diagonal secundaria:");
    for(i = 18; i < 20; i++){
        reverseString(*(Nomes + usedWords[i]), Rev);
        showResolution(Grid, Rev, 'r');
    }

    system("Pause");

    return(0);
}
