solve: transform solve.cpp sudoku.o
	g++ -o solve.cpp sudoku.o
transform: generate transform.cpp sudoku.o
	g++ -o transform.cpp sudoku.o
generate: generate.cpp sudoku.o
	g++ -o generate.cpp sudoku.o
sudoku.o: sudoku.h sudoku.cpp
	g++ -c sudoku.cpp

clean:
	rm sudoku *.o solve *.o transform *.o generate *.o
