#include<iostream>
#include"sudoku.h"

int main(){
    Sudoku a =  Sudoku::generate();    
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << a.prob.at(i).at(j);
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
