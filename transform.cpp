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
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "something went wrong";
                return 0;
        }
    }
    cout << endl;
    printVec(trans.prob);
	return 0;
}
