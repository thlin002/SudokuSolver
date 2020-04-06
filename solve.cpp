#include<iostream>
#include"sudoku.h"
using namespace std;

void printvec(vector<vector<int> >n){
    for(int i = 0; i < 9 ; ++i){
        for( int j = 0; j < 9; ++j){
            cout << n.at(i).at(j) << ' ';
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int> > n(9, vector<int> (9,0));
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> n.at(i).at(j);
        }
    }
    Sudoku sp(n);
    sp.solve();
    printvec(sp.ans);
	return 0;
}
