#include <iostream>
#include "check_connection.h"
#include <iomanip>
using namespace std;

void printmap(int** around, int** click, int** mine, int x){    //This is used to print out the game board. The three arrays and the size of them will be the input and the [pfunction will print out the game board.
    int i,j;
    cout << "   ";
    for(i = 0; i < x; i++){                         //This is used to print out the number of each column to help the player identify the position of the grid he wants to click on.
    	cout << " "  << setw(2) << i+1 ;
	}
	cout << endl << endl;
    for (i=0;i<x;i++){
    	cout << setw(2) << i+1 << "   " ;           //This is used to print out the number of each row.
      for (j=0;j<x;j++){
        if (click[i][j]==0){                   //If the grid has not been clicked, it will print "X" showing that it has not been clicked.
          cout<<"X  ";
        }
        else if (mine[i][j]==1){               //If the grid contains a mine it will also print "X".
          cout<<"X  ";
        }
        else {                                 //If the grid has already been clicked it will print out the number of mines around this specif grid.
          cout<<around[i][j]<<"  ";   
        }
      }
      cout<<endl;
    }
}

bool clickall(int** click, int ** mines, int x){       // This is used to check whether all the grids without a mine have all been clicked. It will receive the click array, mine array and the size of them and return true if it has and return false if it hasn't.
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

void decide(int** mine, int** click, int** around, int x, int y, int a){        //This is used to determine whether the game should keeep running or end. We input the three arrays, the size of them, and the position of the grid clicked, and the game will keep going if the player hasn't fail or win, and will stop if the player has finished the game.
  if (mine[x-1][y-1]==1){                                     //If you click on a grid with a mine, you will lose and the game will stop.
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
  else{                                          //If the grid has not been clicked, it will print out the numeber of mines around it or expand outward.
    check(mine, x-1, y-1, click, around, a);
  }
  
  if (clickall(click, mine, a)){                            //If all the grids without a mine have been clicked, you will win the game and the game will stop.
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
