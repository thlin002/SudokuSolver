solve: transform solve.cpp sudoku.o
	g++ -o solve solve.cpp sudoku.o
transform: generate transform.cpp sudoku.o
	g++ -o transform transform.cpp sudoku.o
generate: sudoku.o generate.cpp
	g++ -o generate generate.cpp sudoku.o
sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm sudoku *.o
