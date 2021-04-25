#include <iostream>
#include "check_connection.h"
#include <iomanip>
using namespace std;

void printmap(int** around, int** click, int** mine, int x){
    int i,j;
    cout << "   ";
    for(i = 0; i < x; i++){
    	cout << " "  << setw(2) << i+1 ;
	}
	cout << endl << endl;
    for (i=0;i<x;i++){
    	cout << setw(2) << i+1 << "   " ;
      for (j=0;j<x;j++){
        if (click[i][j]==0){
          cout<<"X  ";
        }
        else if (mine[i][j]==1){
          cout<<"X  ";
        }
        else {
          cout<<around[i][j]<<"  ";
        }
      }
      cout<<endl;
    }
}

bool clickall(int** click, int ** mines, int x){               // What's that for?
  	int flag = 0;
 	for (int i=0;i<x;i++){
    	for (int j=0;j<x;j++){
     		if (click[i][j]==0){
       		flag = 1;
      		}
    	}
  	}
 	if(flag == 1)
  		return false;
 	else
  		return true;
}

void decide(int** mine, int** click, int** around, int x, int y, int a){
  if (mine[x-1][y-1]==1){
    click[x-1][y-1]=1;
    cout<<"You lose."<<endl;
    for(int i = 0; i < a; i++){
    	delete mine[i];
    	mine[i] = NULL;
    	delete click[i];
    	click[i] = NULL;
    	delete around[i];
    	around[i] = NULL;
	}
	delete mine;
	mine = NULL;
    delete click;
    click = NULL;
    delete around;
    around = NULL;
    exit(0);
  }
  else{
    check(mine, x-1, y-1, click, around, a);
  }
  
  if (clickall(click, mine, a)){                            //in order to give the result, I have to put in another number.
    cout<<"You win."<<endl;
    for(int i = 0; i < a; i++){
    	delete mine[i];
    	mine[i] = NULL;
    	delete click[i];
    	click[i] = NULL;
    	delete around[i];
    	around[i] = NULL;
	}
	delete mine;
	mine = NULL;
    delete click;
    click = NULL;
    delete around;
    around = NULL;
    exit(0);
  }
}
