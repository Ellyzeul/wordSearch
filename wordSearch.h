#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef WORDSEARCH_H_INCLUDED
#define WORDSEARCH_H_INCLUDED




void reverseString(const char *Str, char *Rev);

_Bool patternMatch(const char *String, const char *Search, int *iniIndex);
void allignFirstDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void allignSecondDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void transposeRow(const char *Grid, const int iniRow, char *String);
void transposeReverseRow(const char *Grid, const int iniRow, char *String);
void transposeColumn(const char *Grid, const int iniCol, char *String);
void transposeReverseColumn(const char *Grid, const int iniCol, char *String);

void gridPlot(const char *Grid);
void gridDotFiller(char *Grid);
void gridCharFiller(char *Grid);
void gridCopy(const char *Grid, char *Copy);

int horizontalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset);
int verticalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset);
int firstDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset);
int secondDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset);
void resetList(int *List, const int Dim);

int randomWord(int *usedWords, const int reset);
_Bool confirm(const char *String);
_Bool charToInt(const char *String, int *num);
void numValidate(int *var, const char *msg);



void reverseString(const  char *Str, char *Rev){
    int i, tam = strlen(Str), lim = tam -1;
    for (i = 0; i < tam; i++)
        *(Rev + i) = *(Str + lim - i);
   *(Rev + i) ='\0';
    return;
}

_Bool patternMatch(const char *String, const char *Search, int *iniIndex){
    int StrLen = 20, SrcLen = strlen(Search);
    int StrIndex, SrcIndex, aux = 0;
    for(StrIndex = 0; SrcLen <= StrLen; StrIndex++){
        for(SrcIndex = 0; *(Search + SrcIndex) == *(String + StrIndex + SrcIndex); SrcIndex++){
            aux++;
        }if(aux == SrcLen){
            *iniIndex = StrIndex;
            return(1);
        }aux = 0;
        StrLen--;
    }return(0);
}

void allignFirstDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String){
    int i, lim;
    if(iniRow == 0)
        lim = 20 - iniCol;
    else
        lim = 20 - iniRow;
    for(i = 0; (iniRow + i) < lim || (iniCol + i) < lim; i++)
        *(String + i) = *(Grid + (iniRow + i)*20 + (iniCol + i));
    *(String + i) = '\0';
    return;
}

void allignSecondDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String){
    int i, lim;
    if(iniRow == 0)
        lim = iniCol + 1;
    else
        lim = iniRow + 1;
    for(i = 0; (iniRow + i) < lim || (iniCol + i) < lim; i++)
        *(String + i) = *(Grid + (iniRow + i)*20 + (iniCol + 19 - i));
    *(String + i) = '\0';
    return;
}

void transposeRow(const char *Grid, const int iniRow, char *String){
    int i;
    for(i = 0; i < 20; i++)
        *(String + i) = *(Grid + 20*iniRow + i);
    *(String + i) = '\0';
    return;
}

void transposeReverseRow(const char *Grid, const int iniRow, char *String){
    int i;
    for(i = 0; i < 20; i++)
        *(String + i) = *(Grid + 20*iniRow + 19 - i);
    *(String + i) = '\0';
    return;
}

void transposeColumn(const char *Grid, const int iniCol, char *String){
    int i;
    for(i = 0; i < 20; i++)
        *(String + i) = *(Grid + 20*i + iniCol);
    *(String + i) = '\0';
    return;
}

void transposeReverseColumn(const char *Grid, const int iniCol, char *String){
    int i;
    for(i = 0; i < 20; i++)
        *(String + i) = *(Grid + 20*(19 - i) + iniCol);
    *(String + i) = '\0';
    return;
}

void gridPlot(const char *Grid){
    int i, j;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 21; j++){
            if(j == 20)
                printf("   %d", i + 1);
            else
                printf(" %c ", *(Grid + 20*i + j));
        }puts("\n");
    }puts("\n");
    for(i = 1; i <= 20; i++){
        if(i < 10)
            printf(" %d ", i);
        else
            printf("%d ", i);
    }return;
}

void gridDotFiller(char *Grid){
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            *(Grid + 20*i + j) = '.';
    return;
}

void gridCharFiller(char *Grid){
    int i, j;
    srand(time(NULL));
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++){
            if(*(Grid + 20*i + j) == '.')
                *(Grid + 20*i + j) = rand()%26 + 65;
        }
    return;
}

void gridCopy(const char *Grid, char *Copy){
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            *(Copy + 20*i + j) = *(Grid + 20*i + j);
    return;
}

int horizontalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset){
    int limit = 19 - strlen(String), iniColumn, i = 0, row, key, aux, cont = 0;
    srand(time(NULL));
    do{
        row = rand()%20;
        for(aux = 0; aux < 8; aux++){
            if(row == *(exceptList + aux)){
                key = 1;
                break;
            }else
                key = 0;
        }
    }while(key);
    iniColumn = rand()%limit + 1;
    while(*(String + i) != '\0'){
        if(*(Grid + 20*row + iniColumn + i) != *(String + i) && *(Grid + 20*row + iniColumn + i) != '.'){
            i = 0;
            cont++;
            if(cont > 100){
                *reset = 1;
                return(0);
            }iniColumn = rand()%limit;
        }else
            i++;
    }for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*row + iniColumn + i) = *(String + i);
    *reset = 0;
    return(row);
}

int verticalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset){
    int limit = strlen(String), iniRow, i = 0, column, key, aux, cont = 0;
    srand(time(NULL));
    do{
        column = rand()%20;
        for(aux = 0; aux < 8; aux++){
            if(column == *(exceptList + aux)){
                key = 1;
                break;
            }else
                key = 0;
        }
    }while(key);
        do{
            iniRow = rand()%limit;
        }while(iniRow == 0);
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + column) != '.' && *(Grid + 20*(iniRow + i) + column) != *(String + i)){
            i = 0;
            cont++;
            if(cont > 100){
                *reset = 1;
                return(0);
            }
            do{
            iniRow = rand()%limit;
            }while(iniRow == 0);
        }else
            i++;
    }for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + column) = *(String + i);
    *reset = 0;
    return(column);
}

int firstDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset){
    int limit = 20 - strlen(String), iniColumn, i = 0, iniRow, key, aux, cont = 0;
    srand(time(NULL));
    iniRow = rand()%limit;
    iniColumn = rand()%limit;
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + iniColumn + i) != *(String + i) && *(Grid + 20*(iniRow + i) + iniColumn + i) != '.'){
            i = 0;
            cont++;
            if(cont > 100){
                *reset = 1;
                return(0);
            }do{
                iniRow = rand()%limit;
                iniColumn = rand()%limit;
                for(aux = 0; aux < 2; aux++){
                    if(iniRow - iniColumn == *(exceptList + aux)){
                        key = 1;
                        break;
                    }else
                        key = 0;
                }
            }while(key);
        }else
            i++;
    }for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + iniColumn + i) = *(String + i);
    *reset = 0;
    return(iniRow - iniColumn);
}

int secondDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList, int *reset){
    int limit, lenght = strlen(String), iniColumn, i = 0, iniRow, key, aux, cont = 0;
    srand(time(NULL));
    do{
        iniColumn = rand()%20;
    }while(iniColumn < lenght);
    limit = 19 - lenght;
    iniRow = rand()%limit + lenght;
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + iniColumn - i) != *(String + i) && *(Grid + 20*(iniRow + i) + iniColumn - i) != '.'){
            i = 0;
            cont++;
            if(cont > 100){
                *reset = 1;
                return(0);
            }do{
                do{
                    iniColumn = rand()%20;
                }while(iniColumn < lenght);
                limit = iniRow + 1 - lenght;
                iniRow = rand()%limit + lenght;
                for(aux = 0; aux < 2; aux++){
                    if(iniRow + iniColumn == *(exceptList + aux)){
                        key = 1;
                        break;
                    }else
                        key = 0;
                }
            }while(key);
        }else
            i++;
    }for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + iniColumn - i) = *(String + i);
    return(iniRow + iniColumn);
}

void resetList(int *List, const int Dim){
    int i;
    for(i = 0; i < Dim; i++){
        *(List + i) = 20;
    }return;
}

int globalCont = 0;

int randomWord(int *usedWords, const int reset){
    int i, wordPlace, key;
    if(reset)
        globalCont = 0;
    srand(time(NULL));
    do{
        wordPlace = rand()%20;
        for(i = 0; i < 20; i++){
            if(wordPlace == *(usedWords + i)){
                key = 1;
                break;
            }else
                key = 0;
        }
    }while(key);
    *(usedWords + globalCont) = wordPlace;
    globalCont++;
    return(wordPlace);
}

_Bool confirm(const char *String){
    char ch;
    do{
        system("cls");
        puts(String);
        ch = getchar();
    }while(ch != 's' && ch != 'n' && ch != 'S' && ch != 'N');
    if(ch == 's' || ch == 'S')
        return(1);
    else
        return(0);
}

_Bool charToInt(const char *String, int *num){
    int i;
    *num = 0;
    for(i = 0; *(String + i) != '\0'; i++){
        if(*(String + i) < 48 || *(String + i) > 57)
            return(0);
        *num *= 10;
        *num += *(String + i) - 48;
    }return(1);
}

void numValidate(int *var, const char *msg){
    char ch[1];
    do{
        system("cls");
        puts(msg);
        gets(ch);
    }while(!charToInt(ch, var));
    return;
}

_Bool EncontrarHorizontal(char *CP, int dim, char *palavra, int linha, int coluna){
    int k=0;
    while(*(palavra+k) != '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna))
            return(0);
        k++;
        coluna++;
    }
    return(1);
}
_Bool EncontrarVertical(char *CP, int dim, char *palavra, int linha, int coluna){
    int k=0;
    while(*(palavra+k) != '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna))
            return(0);
        k++;
        linha++;
    }
    return(1);
}
_Bool EncontrarDiagonalPrincipal(char *CP, int dim, char *palavra, int linha, int coluna){
    int k=0;
    while(*(palavra+k)!= '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna))
            return(0);
        k++;
        coluna++;
        linha++;
    }
    return(1);
}

_Bool EncontrarDiagonalSecundaria(char *CP, int dim, char *palavra, int linha, int coluna){
    int k=0;
    while(*(palavra+k)!= '\0'){
        if(*(palavra+k) != *(CP + linha*dim + coluna))
            return(0);
        k++;
        coluna--;
        linha++;
    }
    return(1);
}

void invertGrid(const char *Grid, char * Inv){
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            *(Inv + 20*i + (19 - j)) = *(Grid + 20*i + j);
    return;
}

char invGrid[20][20];

void showResolution(const char *Grid, const char *Word, const char orientation){
    int i, j, k = 0, length = strlen(Word);
    char Rev[20];
    reverseString(Word, Rev);
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++){
            if(*(Grid + 20*i + j) == *Word){
                if(EncontrarHorizontal(Grid, 20, Word, i, j)){
                    if(orientation == 'n')
                        printf("        A palavra %s comeca nos indices: (%d, %d)\n", Word, i + 1, j + 1);
                    else
                        printf("        A palavra %s comeca nos indices: (%d, %d)\n", Rev, i + 1, j + length);
                    return;
                }if(EncontrarVertical(Grid, 20, Word, i, j)){
                    if(orientation == 'n')
                        printf("        A palavra %s comeca nos indices: (%d, %d)\n", Word, i + 1, j + 1);
                    else
                        printf("        A palavra %s comeca nos indices: (%d, %d)\n", Rev, i + length, j +1);
                    return;
                }if(EncontrarDiagonalPrincipal(Grid, 20, Word, i, j)){
                    printf("        A palavra %s comeca nos indices: (%d, %d)\n", Word, i + 1, j + 1);
                    return;
                }if(EncontrarDiagonalSecundaria(Grid, 20, Word, i, j)){
                    printf("        A palavra %s comeca nos indices: (%d, %d)\n", Word, i + 1, j + 1);
                    return;
                }
            }
        }
    return;
}


#endif // WORDSEARCH_H_INCLUDED
