#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int **create_area(int a, int mines, int size){    //create an area according to the input size of the user
                                                  //given the parametre of the area, the number of mines and the size of the area, generate the map and return the pointer. The block with mine will be denoted 1 and 0 otherwise.
	int **area = new int* [a];
	for(int iii = 0; iii < a; iii++){
	area[iii] = new int [a];
	}
	srand (time(NULL));			//randomly choose the position the mines
	int * array2;
	array2 = new int [mines];                     
	int ii, t, flag, k;
	for (k=0; k<mines; ){
		t = (rand() % size);
		flag = 0;
		for(ii = 0; ii < k; ii++){	//to make sure there are no repeated numbers 
			if (array2[ii] == t)
			flag = 1;
		}
		if(flag == 0){
			array2[k] = t;
			k++;
		}
	}
	
	for(int reset1 = 0; reset1 < a; reset1++){		//firstly, change every block in the area to be 0
		for(int reset2 = 0; reset2 < a; reset2++)
		area[reset1][reset2] = 0;
	}
	
	for (int m=0; m<mines; m++){				//display the mines in the area as 1
		int x = array2[m] / a;
		int y = array2[m] % a;
		area[x][y]=1;
	}
	delete array2;						//free the useless arrays
	array2 = NULL;
	return area;
}

int** record_clicking(int a, int ** area){      //create a two-dimensional array to record the blocks being clicked 
						//given the parametre and the former area created in create_area()
	int i, j;
	int **record = new int* [a];
	for(int iii = 0; iii < a; iii++){
	record[iii] = new int [a];
	}
	for (i=0; i<a; i++){			//initially, the clicking record is supposed to be the same as the area recording the position of mines(We assume that the blocks with mines have been clicked.) 
		for (j=0; j<a; j++){
			record[i][j] = area[i][j];
		}
	}
	return record;
} 

int** count_mines(int** area, int a){         //create an array with each block denoted by the number of mines around it.  
					      //given the parametre of the area and the former area created by create_area()
	int ** array3;
	array3 = new int* [a+2];
	for (int i=0; i<a+2; i++){		//create an area that is two lines and two columns larger than the original area, which surround the original area with 0 to make the counting process convenient 
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
	
	
	int **count = new int* [a];		//count the number of mines in the surrounding 8 blocks
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
	for(int Delete = 0; Delete < a+2 ; Delete ++)			//free the unnecessary arrays
	{delete array3[Delete];
	array3[Delete] = NULL;}
	
	delete array3;
	array3 = NULL;
	
	return count;
}

int input(int ** &area, int ** &record, int ** &count){							//let the user input the parametre of area and call the functions above
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



