#ifndef CHOOSE_H
#define CHOOSE_H

void check(int **area, int x, int y,int **record, int a);
void printmap(int** around,int** click,int** mine,int x);
bool clickall(int** click, int ** mines, int x);
void decide(int** mine, int** click, int** around, int x, int y, int a);

#endif
