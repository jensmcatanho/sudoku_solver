#include <stdio.h>

int solve_sudoku();
int next_cell(int *row, int *col);
int check(int value, int row, int col);

int board[9][9];

int main() {
	register int i, j;
	FILE *fp;

	if ( (fp = fopen("input_grid.txt", "r")) == NULL ) {
		printf("%s", "The file could not be opened.\n");
	
	} else {
		// Grid reading
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				fscanf(fp, "%d", &board[i][j]);
			}
		}

		fclose(fp);

		if ( (fp = fopen("solved_grid.txt", "w")) == NULL) {
			printf("%s", "The file could not be opened.\n");

		} else {
			if (solve_sudoku()) {
				for (i = 0; i < 9; i++) {
					for (j = 0; j < 9; j++) {
						if (j == 8)
							fprintf(fp, "%d\n", board[i][j]);
						else
							fprintf(fp, "%d ", board[i][j]);
					}
				}
		
			} else {
				fprintf(fp, "%s", "No solution\n");
			}
		}
	}

	fclose(fp);

	return 0;
}

int solve_sudoku() {
	int row, col, number;

	// Grid solved
	if (!next_cell(&row, &col))
		return 1;

	for (number = 1; number <= 9; number++) {
		if (check(number, row, col)) {
			board[row][col] = number;
			
			if (solve_sudoku())
				return 1;

			board[row][col] = 0; //backtracking

		}
	}


	return 0;
}

int next_cell(int *row, int *col) {
	for (*row = 0; *row < 9; (*row)++) {
		for (*col = 0; *col < 9; (*col)++) {
			if (board[*row][*col] == 0)
				return 1;
		}
	}

	return 0;
}

int check(int value, int row, int col) {
	register int i, j;
	int iStart, iFinish, jStart, jFinish;

	// Checking rows and columns
	for (i = 0; i < 9; i++) {
		if (board[i][col] == value || board[row][i] == value)
			return 0;
	}

	// Checking 3x3 square
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
		iStart = 0;
		jStart = 0;
		iFinish = 2;
		jFinish = 2;

	} else if (row >= 0 && row <= 2 && col >= 3 && col <= 5) {
		iStart = 0;
		jStart = 3;
		iFinish = 2;
		jFinish = 5;

	} else if (row >= 0 && row <= 2 && col >= 6 && col <= 8) {
		iStart = 0;
		jStart = 6;
		iFinish = 2;
		jFinish = 8;

	} else if (row >= 3 && row <= 5 && col >= 0 && col <= 2) {
		iStart = 3;
		jStart = 0;
		iFinish = 5;
		jFinish = 2;

	} else if (row >= 3 && row <= 5 && col >= 3 && col <= 5) {
		iStart = 3;
		jStart = 3;
		iFinish = 5;
		jFinish = 5;

	} else if (row >= 3 && row <= 5 && col >= 6 && col <= 8) {
		iStart = 3;
		jStart = 6;
		iFinish = 5;
		jFinish = 8;

	} else if (row >= 6 && row <= 8 && col >= 0 && col <= 2) {
		iStart = 6;
		jStart = 0;
		iFinish = 8;
		jFinish = 2;

	} else if (row >= 6 && row <= 8 && col >= 3 && col <= 5) {
		iStart = 6;
		jStart = 3;
		iFinish = 8;
		jFinish = 5;

	} else if (row >= 6 && row <= 8 && col >= 6 && col <= 8) {
		iStart = 6;
		jStart = 6;
		iFinish = 8;
		jFinish = 8;

	}

	for (i = iStart; i <= iFinish; i++) {
		for (j = jStart; j <= jFinish; j++) {
			if (board[i][j] == value)
				return 0;
		}
	}

	return 1;
}
