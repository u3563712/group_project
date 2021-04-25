#include <iostream>
using namespace std;

void check(int **area, int x, int y,int ** record, int ** count, int a){        //given the map and the record (There are confliction about pointer count on whether num. of mines or the stat. of trial clicking. I assume the latter)
/*	int a=x;
	int b=y;
	while (area[a-1][b]==0){
		record[a-1][b]=1;
		void check (area, x-1, y, record);
	}
	while (area[a+1][b]==0){
		record[a+1][b]=1;
		void check (area, x+1, y, record);
	}
	while (area[a][b-1]==0){
		record[a][b-1]=1;
		void check (area, x, y-1, record);
	}
	while (area[a][b+1]==0){
		record[a][b+1]=1;
		void check (area, x, y+1, record);
	}
	while (area[a-1][b-1]==0){
		record[a-1][b-1]=1;
		void check (area, x-1, y-1, record);
	}
	while (area[a+1][b+1]==0){
		record[a+1][b+1]=1;
		void check (area, x+1, y+1, record);
	}
	while (area[a-1][b+1]==0){
		record[a-1][b+1]=1;
		void check (area, x-1, y+1, record);
	}
	while (area[a+1][b-1]==0){
		record[a+1][b-1]=1;
		void check (area, x+1, y-1, record);
	}
*/



//notation: record[][] == 0 -> undetected
//record[][] == 1 -> already detected no mines 
//I suppose that the starting point is clear of mine. 
	
	record[x][y] = 1;
	
	if((x-1) >= 0 && (x-1) < a && area[x-1][y] == 0 && record[x-1][y] == 0 && count[x][y] == 0){
		check(area, x-1, y, record, count, a);
	}
	if((x+1) >= 0 && (x+1) < a && area[x+1][y] == 0 && record[x+1][y] == 0 && count[x][y] == 0){
		check(area, x+1, y, record, count, a);
	}
	if((y-1) >= 0 && (y-1) < a && area[x][y-1] == 0 && record[x][y-1] == 0 && count[x][y] == 0){
		check(area, x, y-1, record, count, a);
	}
	if((y+1) >= 0 && (y+1) < a && area[x][y+1] == 0 && record[x][y+1] == 0 && count[x][y] == 0){
		check(area, x, y+1, record, count, a);
	}
	
}
 
