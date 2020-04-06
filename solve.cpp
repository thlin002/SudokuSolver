#include<iostream>
#include"sudoku.h"
using namespace std;

void printarr(int n[][9] ){
    for(int i = 0; i < 9 ; ++i){
        for( int j = 0; j < 9; ++j){
            cout << n[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int> > n(9, vector<int> (9,0));
//    cout << "##input" << endl;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> n.at(i).at(j);
        }
    }
    Sudoku sp(n);
    sp.solve();
    cout << sp.state << endl;
    if(sp.state == 1){
        printarr(sp.ans);
    }
	return 0;
}
