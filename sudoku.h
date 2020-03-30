#include<vector>
#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku
{
public:
    Sudoku();

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

    static constant vector<int> gen = {{1,2,3,4,5,6,7,8,9},
			      	       {4,5,6,7,8,9,1,2,3},
				       {7,8,9,1,2,3,4,5,6},
				       {3,1,2,6,4,5,9,7,8},
				       {6,4,5,9,7,8,3,1,2},
				       {9,7,8,3,1,2,6,4,5},
				       {2,3,1,5,6,4,8,9,7},
				       {5,6,4,8,9,7,2,3,1},
				       {8,9,7,2,3,1,5,6,4}};
};

#endif // SUDOKU_H
