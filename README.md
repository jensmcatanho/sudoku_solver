# Sudoku Solver
It's a simple software written in C to solve Sudoku games using <b>backtracking</b>. The program opens a <b>.txt</b> file with the input Sudoku grid and outputs another <b>.txt</b> file with the solved grid or a message if it's impossible to solve.

The input file must contain 9 rows and 9 columns and must be filled with the known numbers of the grid. If a number is not known, it's position is filled with 0 like the example below.

<h4>Sample Input (input_grid.txt)</h4>
	0 2 0 5 0 1 0 9 0
	8 0 0 2 0 3 0 0 6
	0 3 0 0 6 0 0 7 0
	0 0 1 0 0 0 6 0 0
	5 4 0 0 0 0 0 1 9
	0 0 2 0 0 0 7 0 0
	0 9 0 0 3 0 0 8 0
	2 0 0 8 0 4 0 0 7
	0 1 0 9 0 7 0 6 0

<h4>Sample Output (solved_grid.txt)</h4>
	4 2 6 5 7 1 3 9 8
	8 5 7 2 9 3 1 4 6
	1 3 9 4 6 8 2 7 5
	9 7 1 3 8 5 6 2 4
	5 4 3 7 2 6 8 1 9
	6 8 2 1 4 9 7 5 3
	7 9 4 6 3 2 5 8 1
	2 6 5 8 1 4 9 3 7
	3 1 8 9 5 7 4 6 2
