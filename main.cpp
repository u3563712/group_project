#include <iostream>
#include "choose.h"
#include "create_area.h"
#include "check_connection.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*void test(int ** area, int ** click, int ** count, int a){           //for debugging
	cout << endl;
	cout << "THE MAP:" << endl;
	int i, j;
	for(i = 0; i < a; i++){
		for (j = 0; j<a; j++){
			cout << area[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
	cout << "THE COUNT:" << endl;
	for(i = 0; i < a; i++){
		for (j = 0; j<a; j++){
			cout << count[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
	cout << "THE CLICK:" << endl;
	for(i = 0; i < a; i++){
		for (j = 0; j<a; j++){
			cout << click[i][j] << " " ;
		}
		cout << endl;
	}
}*/



int main() {
	int **area, **record, **count;
	int a;
	a = input(area, record, count);
	printmap(count,record,area,a);
//	test(area, record, count, a);
	while(1){
		cout << "Please enter the block you click (in the format of row first and colomn second. e.g. 3 4)" << endl;
		int x, y;
		cin >> x >> y;
		decide(area, record, count, x, y, a);
		printmap(count,record,area,a);
//		test(area, record, count, a);
	}
	
	
	return 0;
}
