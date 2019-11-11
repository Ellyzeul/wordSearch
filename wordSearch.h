#ifndef WORDSEARCH_H_INCLUDED
#define WORDSEARCH_H_INCLUDED

void reverseString(const char *Str, char *Rev);
_Bool patternMatch(const char *String, const char *Search);
_Bool horizontalOccurVerifier(const char *Grid, const int row, const char *Search);
void allignFirstParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void allignSecondParallelDiagonal(const char *Grid, const int iniRow, const int iniCol, char *String);
void gridPlot(const char *Grid);
void gridFiller(char *Grid);
void horizontalWordPlacer(char *Grid, const char *String, const int row);

#endif // WORDSEARCH_H_INCLUDED
