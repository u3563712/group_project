# group_project
mine sweeper game for the group project.
 
 Mine Sweeper

-Group No.: 115

-Group members: Gou Longxiang 3035637125

-Zhao Chang 3035772717

-Topic: Mine Sweeper

-Link: https://github.com/u3563712/group_project



Game description:
Mine Sweeper is a game which has a rectangular area full of grids with several mines in it. At first, the area doesn’t show anything thus the player won’t know any information about where the mine is. Each time, the player needs to choose one grid in the rectangular area. If the position contains a mine, the player loses. If it does not contain a mine, it will show the number of mines in the 8 grids around it. For example, if there is only one mine in the near 8 grids, it will show 1, and it’ll show 2 if there are 2 mines, and so on. The player can use the information provided to help identify which grid has a mine in it and which doesn’t. If all the grids without a mine are all chosen by the player and the remaining grids are all mines, the player wins. 
In addition, the size of the area can be decided by the player. The player can input a number to decide the size of the area. 

Coding requirements:
1.	Generation of random game sets or events:
The size of the area is determined by the input of the player.
The distribution of grids in every round of game is random.
2.	Data structures for storing game status & Dynamic memory management
There will be several arrays as data bases to store all the initial status of the grids (whether there is a mine or not), the status of girds which have been chosen and the numbers of mines around. Once the player chooses a grid, a series of judgement will be implemented such as whether the grid has a mine inside and how any mines are around. The latter database will be updated correspondingly and the grids you have clicked on cannot be chosen again.
3.	File input/output (e.g., for loading/saving game status)
The first input determine the size of the area.
Then the inputs following indicates the grid player chooses to check. If the grid has no mine, the output is the status of the grid (whether there is a mine) and the number of mines around. If the grid has the mine, the output will be “Game over.”
4.	Program codes in multiple files
The mine sweeper program will be separated into several function section with multiple files.

How to compile?
1. input the text in the Makefile document to complie the program

FLAGS = -pedantic-errors -std=c++11
choose.o:choose.cpp choose.h check_connection.h
	g++ $(FLAGS) -c $<
check_connection.o:check_connection.cpp check_connection.h
	g++ $(FLAGS) -c $<
create_area.o:create_area.cpp create_area.h
	g++ $(FLAGS) -c $<
main.o:main.cpp create_area.h check_connection.h choose.h
	g++ $(FLAGS) -c $<
main:main.o choose.o create_area.o check_connection.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main.o create_area.o check_connection.o choose.o
.PHONY:clean

2. open the shell and input: make main



