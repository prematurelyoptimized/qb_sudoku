#include<cstdlib>
#include"solver.hpp"

void display(const partialSolution &sol) {
	int intSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	toIntArray(sol,intSolution);
	std::cout << "Difficulty rating: " << sol.difficultyRating << '\n';
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++){
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			std::cout << intSolution[i][j] << ", ";
		std::cout << '\n';
	}
	std::cout << '\n';
}

int main(int argc, char* argv[]){
	if(argc>1) {
		std::cout << generateSDMLine(solve(parseSDMLine(argv[1]))) << '\n';
		return 0;
	}

	int samplePuzzle1[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{1, 6, 0, 4, 0, 3, 0, 0, 9},
						 							 {0, 4, 0, 9, 0, 0, 0, 8, 0},
						 							 {0, 0, 0, 0, 0, 0, 0, 4, 0},
													 {5, 0, 0, 0, 2, 0, 0, 0, 6},
													 {0, 0, 7, 1, 0, 5, 2, 0, 0},
													 {3, 0, 0, 0, 9, 0, 0, 0, 4},
													 {0, 2, 0, 0, 0, 0, 0, 0, 0},
													 {0, 3, 0, 0, 0, 4, 0, 5, 0},
													 {7, 0, 0, 8, 0, 6, 0, 1, 2}};
	// Puzzle 277
	int samplePuzzle2[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 4, 0, 0, 0, 0, 0, 0, 3},
						 							 {1, 5, 0, 4, 0, 2, 0, 0, 0},
						 							 {0, 0, 8, 0, 0, 3, 0, 0, 7},
													 {0, 8, 0, 3, 4, 0, 0, 0, 2},
													 {0, 7, 0, 0, 0, 0, 0, 4, 0},
													 {4, 0, 0, 0, 5, 9, 0, 8, 0},
													 {8, 0, 0, 2, 0, 0, 6, 0, 0},
													 {0, 0, 0, 6, 0, 7, 0, 9, 1},
													 {9, 0, 0, 0, 0, 0, 0, 2, 0}};
	
	// Puzzle 389
	int samplePuzzle3[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 6, 0, 3, 0, 2, 0, 1, 0},
						 							 {0, 4, 0, 0, 0, 0, 0, 7, 0},
						 							 {8, 0, 1, 0, 0, 0, 2, 0, 9},
													 {0, 0, 0, 4, 0, 1, 0, 0, 0},
													 {3, 5, 0, 0, 0, 0, 0, 9, 1},
													 {0, 0, 0, 8, 0, 3, 0, 0, 0},
													 {2, 0, 3, 0, 0, 0, 9, 0, 7},
													 {0, 1, 0, 0, 0, 0, 0, 3, 0},
													 {0, 7, 0, 6, 0, 8, 0, 5, 0}};

	// Puzzle 441
	int samplePuzzle4[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 0, 7, 4, 5, 0, 2, 0, 0},
						 							 {0, 0, 9, 0, 0, 0, 0, 0, 1},
						 							 {2, 0, 0, 9, 0, 0, 3, 4, 0},
													 {0, 9, 6, 0, 8, 2, 0, 0, 0},
													 {0, 0, 0, 0, 0, 0, 0, 0, 0},
													 {0, 0, 0, 1, 9, 0, 8, 6, 0},
													 {0, 8, 1, 0, 0, 7, 0, 0, 3},
													 {3, 0, 0, 0, 0, 0, 5, 0, 0},
													 {0, 0, 2, 0, 3, 4, 1, 0, 0}};
													 
	// Puzzle 573
	int samplePuzzle5[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 8, 0, 0, 0, 1, 6, 0, 0},
						 							 {0, 0, 5, 0, 0, 0, 0, 0, 3},
						 							 {3, 0, 0, 0, 0, 0, 0, 9, 0},
													 {8, 5, 0, 9, 1, 0, 0, 0, 7},
													 {0, 0, 9, 2, 0, 5, 3, 0, 0},
													 {1, 0, 0, 0, 7, 4, 0, 5, 2},
													 {0, 3, 0, 0, 0, 0, 0, 0, 6},
													 {9, 0, 0, 0, 0, 0, 2, 0, 0},
													 {0, 0, 8, 6, 0, 0, 0, 1, 0}};

	partialSolution sol = fromIntArray(samplePuzzle1);
	sol = solve(sol);
	display(sol);
	
	sol = fromIntArray(samplePuzzle2);
	sol = solve(sol);
	display(sol);

	sol = fromIntArray(samplePuzzle3);
	sol = solve(sol);
	display(sol);

	sol = fromIntArray(samplePuzzle4);
	sol = solve(sol);
	display(sol);

	sol = fromIntArray(samplePuzzle5);
	sol = solve(sol);
	display(sol);

	return 0;
}

