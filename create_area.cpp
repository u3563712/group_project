#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int **create_area(int a, int mines, int size){    //all functions return the pointers
                                                  //given the parametre of the map, the number of mines and the size of the map, generate the map and return the pointer. The block with mine will be denoted 1 and 0 otherwise.
	int **area = new int* [a];
	for(int iii = 0; iii < a; iii++){
	area[iii] = new int [a];
	}
	srand (time(NULL));
	 
	int * array2;
	array2 = new int [mines];                       //focus on the dynamic array here
	int ii, t, flag, k;
	for (k=0; k<mines; ){
		t = (rand() % size);
		flag = 0;
		for(ii = 0; ii < k; ii++){
			if (array2[ii] == t)
			flag = 1;
		}
		if(flag == 0){
			array2[k] = t;
			k++;
		}
	}
	
	for(int reset1 = 0; reset1 < a; reset1++){
		for(int reset2 = 0; reset2 < a; reset2++)
		area[reset1][reset2] = 0;
	}
	
	for (int m=0; m<mines; m++){
		int x = array2[m] / a;
		int y = array2[m] % a;
		area[x][y]=1;
	}
	delete array2;
	array2 = NULL;
	return area;
}

int** record_clicking(int a, int ** area){      //I think we can do more in this function. Dunno how to write a discription of it. 
	int i, j;
	int **record = new int* [a];
	for(int iii = 0; iii < a; iii++){
	record[iii] = new int [a];
	}
	for (i=0; i<a; i++){
		for (j=0; j<a; j++){
			record[i][j] = area[i][j];
		}
	}
	return record;
} 

int** count_mines(int** area, int a){         //return another map with the same size with area. Each block denoted by the number of mines around it. (For blocks with mines, the result will be num. -1) 
	int ** array3;
	array3 = new int* [a+2];
	for (int i=0; i<a+2; i++){
		int *line = new int [a+2];
		for (int j=0; j<a+2; j++){
			if ((i==0)||(i==a+1))
				line[j]=0;
			else{
				if ((j==0)||(j==a+1)){
					line[j]=0;
				}
				else {
					line[j]=area[i-1][j-1];
				}
			}
		array3[i] = line;
			
		}
	}	
	
/*	int hardtofind1, hardtofind2;
	for(hardtofind1 = 0; hardtofind1 < a+2; hardtofind1++){
		for (hardtofind2 = 0; hardtofind2 < a+2; hardtofind2++){
			cout << array3[hardtofind1][hardtofind2] << " " ;
		}
		cout << endl;
	}*/          //for debugging
	
	
	
	int **count = new int* [a];
	for(int m = 0; m < a; m++){
		int *line1 = new int [a];
		for (int n=0; n < a; n++){
		int x = 0;
			for (int c=m; c<=m+2; c++){
				for (int d=n; d<=n+2; d++){
					if (array3[c][d]==1)
						x++;
				}
			}
			if (array3[m+1][n+1]==1)
				x=x-1;
			line1 [n] =x;
		}
		count[m]=line1;
	}
	for(int Delete = 0; Delete < a+2 ; Delete ++)
	{delete array3[Delete];
	array3[Delete] = NULL;}
	
	delete array3;
	array3 = NULL;
	
	return count;
}

int input(int ** &area, int ** &record, int ** &count){							//??
	int a;
	cout << "Please input the size of the area: ";
	cin >> a;
	int size=a*a;
	int mines = size*0.1;
	area = create_area(a, mines, size);
	record = record_clicking(a, area);
	count = count_mines(area, a);
	return a;
}


/*int **area = new *int [a];
for(int iii = 0; iii < a; iii++){
	int *line = new int [a];
	area[iii] = line;
} */											// prototype


