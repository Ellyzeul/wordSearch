#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef WORDSEARCH_H_INCLUDED
#define WORDSEARCH_H_INCLUDED

void reverseString(const char *Str, char *Rev);
_Bool patternMatch(const char *String, const char *Search);
_Bool horizontalOccurVerifier(const char *Grid, const int row, const char *Search);
void allignFirstParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void allignSecondParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void gridPlot(const char *Grid);
void gridFiller(char *Grid);
int horizontalWordPlacer(char *Grid, const char *String, const int *exceptList);
int verticalWordPlacer(char *Grid, const char *String, const int *exceptList);
int firstDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList);
int secondDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList);
void resetList(int *List);


void reverseString(const  char *Str, char *Rev){
    int i, tam = strlen(Str), lim = tam -1;
    for (i = 0; i < tam; i++)
        *(Rev + i) = *(Str + lim - i);
   *(Rev + i) ='\0';
    return;
}

_Bool patternMatch(const char *String, const char *Search){
    if(*(String) == '\0' && *(Search) == '\0')
        return(1);
    int StrLen = 20, SrcLen = strlen(Search);
    int StrIndex, SrcIndex, aux = 0;
    for(StrIndex = 0; SrcLen <= StrLen; StrIndex++){
        for(SrcIndex = 0; *(Search + SrcIndex) == *(String + StrIndex + SrcIndex); SrcIndex++){
            aux++;
        }if(aux == SrcLen)
            return(1);
        aux = 0;
        StrLen--;
    }return(0);
}

_Bool horizontalOccurVerifier(const char *Grid, const int row, const char *Search){
    if(patternMatch(Grid + row*20, Search))
        return(1);
    else
        return(0);
}

void allignFirstParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String){
    int i;
    for(i = 0; (iniRow + i) < 20 || (iniCol + i) < 20; i++)
        *(String + i) = *(Grid + (iniRow + i)*20 + (iniCol + i));
    *(String + i) = '\0';
    return;
}

void allignSecondParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String){
    int i;
    for(i = 0; (iniRow + i) < 20 || (iniCol + i) < 20; i++)
        *(String + i) = *(Grid + (iniRow + i)*20 + (iniCol + 19 - i));
    *(String + i) = '\0';
    return;
}

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
            *(Grid + 20*i + j) = '.';
        }
    return;
}

int horizontalWordPlacer(char *Grid, const char *String, const int *exceptList){
    int limit = 20 - strlen(String), iniColumn, i = 0, row, key, aux;
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
    iniColumn = rand()%limit;
    while(*(String + i) != '\0'){
        if(*(Grid + 20*row + iniColumn + i) != *(String + i) && *(Grid + 20*row + iniColumn + i) != '.'){
            i = 0;
            iniColumn = rand()%limit;
        }else
            i++;
    }printf("Palavra: %s\nletra inicial da palavra: %c\nletra no grid: %c\n\n", String, *(String), *(Grid + 20*row + iniColumn));
    for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*row + iniColumn + i) = *(String + i);
    return(row);
}

int verticalWordPlacer(char *Grid, const char *String, const int *exceptList){
    int limit = 20 - strlen(String), iniRow, i = 0, column, key, aux;
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
    iniRow = rand()%limit;
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + column) != '.' && *(Grid + 20*(iniRow + i) + column) != *(String + i)){
            i = 0;
            iniRow = rand()%limit;
        }else
            i++;
    }printf("Palavra: %s\nletra inicial da palavra: %c\nletra no grid: %c\n\n", String, *(String), *(Grid + 20*iniRow + column));
    for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + column) = *(String + i);
    return(column);
}

int firstDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList){
    int limit = 20 - strlen(String), iniColumn, i = 0, iniRow, key, aux;
    srand(time(NULL));
    do{
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
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + iniColumn + i) != *(String + i) && *(Grid + 20*(iniRow + i) + iniColumn + i) != '.'){
            i = 0;
            iniColumn = rand()%limit;
        }else
            i++;
    }printf("Palavra: %s\nletra inicial da palavra: %c\nletra no grid: %c\n\n", String, *(String), *(Grid + 20*iniRow + iniColumn));
    for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + iniColumn + i) = *(String + i);
    return(iniRow - iniColumn);
}

int secondDiagonalWordPlacer(char *Grid, const char *String, const int *exceptList){
    int limit = 20 - strlen(String), shift = strlen(String), iniColumn, i = 0, iniRow, key, aux;
    srand(time(NULL));
    while(*(String + i) != '\0'){
        if(*(Grid + 20*(iniRow + i) + iniColumn - i) != *(String + i) && *(Grid + 20*(iniRow + i) + iniColumn - i) != '.'){
            i = 0;
            do{
                iniRow = rand()%limit;
                iniColumn = rand()%limit + shift;
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
    }printf("shift: %d\niniRow: %d\niniColumn: %d\nPalavra: %s\nletra inicial da palavra: %c\nletra no grid: %c\n\n", shift, iniRow, iniColumn, String, *(String), *(Grid + 20*iniRow + iniColumn));
    for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*(iniRow + i) + iniColumn - i) = *(String + i);
    return(iniRow + iniColumn);
}

void resetList(int *List){
    int i;
    for(i = 0; i < 8; i++){
        *(List + 20) = 20;
    }return;
}


#endif // WORDSEARCH_H_INCLUDED
