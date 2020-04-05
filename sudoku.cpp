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
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            for(int k = 0; k < 9; ++k){
                alm[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(prob.at(i).at(j) == 0){  //first double forloop is to identify void location
                for(int k = 0; k < 9; ++k){  // Row check
//                    alm[i][j][k] = 0;        //initialize to all pulled down
                    if(prob.at(i).at(k) > 0){
                        alm[i][j][prob.at(i).at(k)-1] = 1;   // non-available digit's bit is raised
                    }
                }
                for(int k = 0; k < 9; ++k){  //Column check
                    if(prob.at(k).at(j) > 0){
                        alm[i][j][prob.at(k).at(j)-1] = 1;
                    }
                }
                int bc = j/3;
                int br = i/3;
                for(int k = br*3; k < br*3+3; ++k){ //Box check
                    for(int m = bc*3; m < bc*3+3; ++m){
                        if(prob.at(k).at(m) > 0){
                            alm[i][j][prob.at(k).at(m)-1] = 1;
                        }
                    }
                }
            }
            else{   //for filled spuare raise every digit
                for(int k = 0; k < 9; ++k){
                    alm[i][j][k] = 1;
                }
            }
        }
    }

    for(int i = 0; i < 9; ++i){     //print to check alm.
        for(int j = 0; j < 9; ++j){
            cout << "index" << i << ',' << j << " : ";
            for(int k = 0; k < 9; ++k){
                cout << (alm[i][j][k]?0:(k+1)) << " , ";
            }
            cout << endl; 
        }
        cout << endl;
    }
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
void Sudoku::swapRow(int x, int y){
    vector<vector<int> > temp(3, vector<int> (9,0));
    for( int i = 0; i < 3; ++i ){
        int n = 3*x - 3 + i;
        int m = 3*y - 3 + i;
        temp.at(i) = prob.at(n);
        prob.at(n) = prob.at(m);
        prob.at(m) = temp.at(i);
    }
}

void Sudoku::swapCol(int x, int y){
    vector<vector<int> > temp(9, vector<int> (3,0));
    for(int i = 0; i < 3; ++i){
        for(int j =0; j < 9; ++j){
            int n = 3*x - 3 + i;
            int m = 3*y - 3 + i;
            temp.at(j).at(i) = prob.at(j).at(n);
            prob.at(j).at(n) = prob.at(j).at(m);
            prob.at(j).at(m) = temp.at(j).at(i);
        }
    }
}

void Sudoku::rotate(int x){
    vector<vector<int> > temp(9, vector<int> (3,0));
    for(int i = 0; i < x; ++i){
        temp = prob;
        for(int j = 0; j < 9; ++j){
            for(int k = 0; k < 9; ++k){
                prob.at(j).at(8-k) = temp.at(k).at(j);
            }
        }
    }
}
void Sudoku::flip(int x){
    if(x == 0){
        vector<vector<int> > temp(4, vector<int> (9,0));
        for(int i = 0; i < 4; ++i){
            temp.at(i) = prob.at(8-i);
            prob.at(8-i) = prob.at(i);
            prob.at(i) = temp.at(i);
        }
    }
    else{
        vector<vector<int> >temp(9, vector<int> (4,0));
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 9; ++j){
                temp.at(j).at(i) = prob.at(j).at(8-i);
                prob.at(j).at(8-i) = prob.at(j).at(i);
                prob.at(j).at(i) = temp.at(j).at(i);
            }
        }
    }
}
//Solve
int Sudoku::solve(){

	return 0;
}
