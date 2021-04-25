#include <iostream>
using namespace std;

void check(int **area, int x, int y,int ** record, int ** count, int a){        //check if the blocks around a specific block have no mines
										//given the area recording the position of mines, the x,y coordinate of the block that the user choose, the array recording the clicking records and the parametre of the area           
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
 
