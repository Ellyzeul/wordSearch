#include "wordSearch.h"

int main(void){
    int exceptList[8], usedWords[20], i, j, auxIndex = 0, aux = 0, resetKey = 0, op = 0;
    int horizontalWords[8], verticalWords[8], diagonalWords[4];
    char Grid[20][20], copyGrid[20][20], Rev[20], Search[20];
    char *Nomes[20] = {"ANA", "ROBERTO", "CLAUDIA", "CARLOS", "ROGERIO", "PEDRO", "JULIA", "MARCOS", "JOAO", "MARILIA",
                       "GABRIEL", "FELIPE", "SARA", "ALICE", "BRUNA", "GERALDO", "CAROL", "LOREN", "LEANDRO", "MILLENA"};

    if(!confirm("            !!!Caca Palavras!!!\n\nDeseja comecar? <S/N>"))
        exit(1);

    system("cls");

    do{
        resetList(usedWords, 20);
        resetList(exceptList, 8);
        gridDotFiller(Grid);

        for(i = 0; i < 4; i++){
            horizontalWords[i] = randomWord(usedWords);
            exceptList[i] = horizontalWordPlacer(Grid, *(Nomes + horizontalWords[i]), exceptList, &resetKey);
        }if(resetKey)
            continue;

        for(; i < 8; i++){
            horizontalWords[i] = randomWord(usedWords);
            reverseString(*(Nomes + horizontalWords[i]), Rev);
            exceptList[i] = horizontalWordPlacer(Grid, Rev, exceptList, &resetKey);
        }resetList(exceptList, 8);
        if(resetKey)
            continue;

        for(i = 0; i < 4; i++){
            verticalWords[i] = randomWord(usedWords);
            exceptList[i] = verticalWordPlacer(Grid, *(Nomes + verticalWords[i]), exceptList, &resetKey);
        }if(resetKey)
            continue;

        for(; i < 8; i++){
            verticalWords[i] = randomWord(usedWords);
            reverseString(*(Nomes + verticalWords[i]), Rev);
            exceptList[i] = verticalWordPlacer(Grid, Rev, exceptList, &resetKey);
        }resetList(exceptList, 2);
        if(resetKey)
            continue;

        for(i = 0; i < 2; i++){
            diagonalWords[i] = randomWord(usedWords);
            exceptList[i] = firstDiagonalWordPlacer(Grid, *(Nomes + diagonalWords[i]), exceptList, &resetKey);
        }resetList(exceptList, 2);
        if(resetKey)
            continue;

        for(; i < 4; i++){
            diagonalWords[i] = randomWord(usedWords);
            exceptList[i] = secondDiagonalWordPlacer(Grid, *(Nomes + diagonalWords[i]), exceptList, &resetKey);
        }

    }while(resetKey);

    gridCopy(Grid, copyGrid);
    gridCharFiller(Grid);
    gridPlot(Grid);
    puts("\n\n\n");
    system("Pause");

    do{
        numValidate(&op, "Agora sera exibida a resolucao.\nComo deseja vizualizar a grade?\n\n1 - com letras\n2 - somente com as palavras\nInsira aqui sua opcao");
    }while(op != 1 && op != 2);
    system("cls");
    if(op == 1)
        gridPlot(Grid);
    else
        gridPlot(copyGrid);
    puts("\n_________________________________________________________________");

    puts("\n\n\nPalavras na horizontal\n\n    Orientacao normal:");
    for(i = 0; i < 4; i++){
        j = 0;
        while(1){
            transposeRow(Grid, j, Search);
            if(patternMatch(Search, *(Nomes + horizontalWords[i]), &auxIndex))
                break;
            j++;
        }printf("        nas coordenadas (%d, %d) esta a palavra: %s\n", j + 1, auxIndex + 1, *(Nomes + horizontalWords[i]));
    }
    puts("    Orientacao inversa:");
    for(i = 4; i < 8; i++){
        j = 0;
        while(1){
            transposeRow(Grid, j, Search);
            reverseString(Search, Rev);
            if(patternMatch(Rev, *(Nomes + horizontalWords[i]), &auxIndex))
                break;
            j++;
        }printf("        nas coordenadas (%d, %d) esta a palavra: %s\n", j + 1, 20 - auxIndex, *(Nomes + horizontalWords[i]));
    }

    system("Pause");

    return(0);
}
