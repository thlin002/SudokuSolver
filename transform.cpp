#include<iostream>
#include"sudoku.h"
#include<vector>
using namespace std;

void printVec(vector<vector<int> > a){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << a.at(i).at(j);
            cout << " ";
        }
        cout << endl; 
    }
}

int main(){
    vector<vector<int> > input(9, vector<int> (9));
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> input.at(i).at(j);
        }
    }
    Sudoku trans(input);
    int mode = -1;
    while(mode != 0){
        cin >> mode;
        int x = -1;
        int y = -1;
        switch(mode){
            case 0:
                break;
            case 1:
                cin >> x >> y;
                trans.swapNum(x,y);
                break;
            case 2:
                cin >> x >> y;
                trans.swapRow(x,y);
                break;
            case 3:
                cin >> x >> y;
                trans.swapCol(x,y);
                break;
            case 4:
                cin >> x;
                trans.rotate(x);
                break;
            case 5:
                cin >> x;
                trans.flip(x);
                break;
            default:
                cout << "something went wrong";
                return 0;
        }
    }
    printVec(trans.prob);
	return 0;
}
