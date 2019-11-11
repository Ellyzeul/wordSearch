#include "wordSearch.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

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
            printf("%c", Grid + 20*i + j);
        puts("\n");
    }return;
}

void gridFiller(char *Grid){
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            *(Grid + 20*i + j) = '.';
    return;
}

void horizontalWordPlacer(char *Grid, const char *String, const int row){
    int limit = 20 - strlen(String), iniColumn, i;
    time_t t;
    srand((unsigned)t);
    iniColumn = rand()%limit;
    for(i = 0; *(String + i) != '\0'; i++)
        *(Grid + 20*row + iniColumn + i) = *(String + i);
    return;
}

