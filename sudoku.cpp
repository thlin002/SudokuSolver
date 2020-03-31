#include<vector>
#include"sudoku.h"
using namespace std;
/*
const vector<vector<int> > Sudoku::gen = {{1,2,3,4,5,6,7,8,9},
				    	  {4,5,6,7,8,9,1,2,3},
				  	  {7,8,9,1,2,3,4,5,6},
				   	  {3,1,2,6,4,5,9,7,8},
				       	  {6,4,5,9,7,8,3,1,2},
					  {9,7,8,3,1,2,6,4,5},
					  {2,3,1,5,6,4,8,9,7},
					  {5,6,4,8,9,7,2,3,1},
					  {8,9,7,2,3,1,5,6,4}};
*/
//Constructor
Sudoku::Sudoku(){}
//Generate
Sudoku Sudoku::generate(){
	Sudoku sgen;
	sgen.prob;
	return sgen;
}
//Transform
void Sudoku::swapNum(int x, int y){}
void Sudoku::swapRow(int x, int y){}
void Sudoku::swapCol(int x, int y){}
void Sudoku::rotate(int x){}
void Sudoku::flip(int x){}
//Solve
int Sudoku::solve(){
	return 0;
}
