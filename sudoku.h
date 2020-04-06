#include<vector>
#ifndef SUDOKU_H
#define SUDOKU_H
using namespace std;
using namespace std;
/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku{
public:
	Sudoku();
    Sudoku(vector<vector<int> > n);
	// generate
	static Sudoku generate();

	// transform
	void swapNum(int x, int y);
	void swapRow(int x, int y);
	void swapCol(int x, int y);
	void rotate(int x);
	void flip(int x);

	// solve
	int solve();

	//Data Member
	static const vector<vector<int> > gen;
	vector<vector<int> > prob;
    vector<vector<int> > ans;
    int alm[9][9][9];
    int v[81];
};
#endif // SUDOKU_H
