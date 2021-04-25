#ifndef CREATE_AREA_H
#define CREATE_AREA_H

int** create_area(int a, int mines, int size);
int** record_clicking(int a, int ** area);
int** count_mines(int** area, int a);
int input(int ** &area, int ** &record, int ** &count);

#endif
