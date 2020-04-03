#include"sudoku.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
const vector<vector<int> > Sudoku::gen = {{1,2,3,4,5,6,7,8,9},
                				    	  {4,5,6,7,8,9,1,2,3},
                    				  	  {7,8,9,1,2,3,4,5,6},
                    				   	  {3,1,2,6,4,5,9,7,8},
                				       	  {6,4,5,9,7,8,3,1,2},
                    					  {9,7,8,3,1,2,6,4,5},
                    					  {2,3,1,5,6,4,8,9,7},
                    					  {5,6,4,8,9,7,2,3,1},
                    					  {8,9,7,2,3,1,5,6,4}};

//Constructor
Sudoku::Sudoku(){}
Sudoku::Sudoku(vector<vector<int> > n){
    prob = n;    
}
//Generate
Sudoku Sudoku::generate(){
    int a,b;
    srand(time(NULL));
	Sudoku sgen;
	sgen.prob = sgen.gen;
    for(int i=0; i<20; ++i){
        a = (rand()%9);
        b = (rand()%9);
        sgen.prob.at(a).at(b) = 0;
    }
	return sgen;
}
//Transform
void Sudoku::swapNum(int x, int y){
    int xs[9];
    int ys[9];
    int xe = 0;
    int ye = 0;
    for(int i = 0; i < 9; ++i){
        xe = 0;
        ye = 0;
        for(int j = 0; j < 9; ++j){
            if(prob.at(i).at(j) == x){
                xs[i] = j;
                xe = 1;
            }
            else if(prob.at(i).at(j) == y){
                ys[i] = j;
                ye = 1;
            }
        }
        if(xe == 0){
            xs[i] = -1;
        }
        else if(ye == 0){
            ys[i] = -1;
        }
    }
    
    for(int i = 0; i < 9; ++i){
//        cout << "(" << i << ") :" << xs[i] << "   " << ys[i] << endl;
        if(xs[i] >= 0){
            prob.at(i).at(xs[i]) = y;
        }
        if(ys[i] >= 0){
            prob.at(i).at(ys[i]) = x;
        }
    }
}
void Sudoku::swapRow(int x, int y){}
void Sudoku::swapCol(int x, int y){}
void Sudoku::rotate(int x){}
void Sudoku::flip(int x){}
//Solve
int Sudoku::solve(){
	return 0;
}
