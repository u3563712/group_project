#include <iostream>
#include "choose.h"
#include "create_area.h"
#include "check_connection.h"
using namespace std;

int main() {						//input and display the original area
	int **area, **record, **count;		
	int a;
	a = input(area, record, count);
	printmap(count,record,area,a);

	while(1){					//user input the position of the block and play the game
		cout << "Please enter the block you click (in the format of row first and colomn second. e.g. 3 4)" << endl;
		int x, y;
		cin >> x >> y;
		decide(area, record, count, x, y, a);
		printmap(count,record,area,a);

	}
	
	
	return 0;
}
