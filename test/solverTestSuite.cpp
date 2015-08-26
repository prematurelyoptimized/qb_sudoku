#include<cstdint>
#include"solverTestSuite.hpp"
#include"partialSolution.hpp"
#include"solver.hpp"

void solverTestSuite::eliminationTest() {
	int samplePuzzle[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{1, 6, 0, 4, 0, 3, 0, 0, 9},
						 							 {0, 4, 0, 9, 0, 0, 0, 8, 0},
						 							 {0, 0, 0, 0, 0, 0, 0, 4, 0},
													 {5, 0, 0, 0, 2, 0, 0, 0, 6},
													 {0, 0, 7, 1, 0, 5, 2, 0, 0},
													 {3, 0, 0, 0, 9, 0, 0, 0, 4},
													 {0, 2, 0, 0, 0, 0, 0, 0, 0},
													 {0, 3, 0, 0, 0, 4, 0, 5, 0},
													 {7, 0, 0, 8, 0, 6, 0, 1, 2}};
	
	int correctAnswer[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
																{{1, 6, 5, 4, 8, 3, 7, 2, 9},
									 							 {2, 4, 3, 9, 7, 1, 6, 8, 5},
									 							 {9, 7, 8, 5, 6, 2, 3, 4, 1},
																 {5, 8, 4, 3, 2, 7, 1, 9, 6},
																 {6, 9, 7, 1, 4, 5, 2, 3, 8},
																 {3, 1, 2, 6, 9, 8, 5, 7, 4},
																 {4, 2, 1, 7, 5, 9, 8, 6, 3},
																 {8, 3, 6, 2, 1, 4, 9, 5, 7},
																 {7, 5, 9, 8, 3, 6, 4, 1, 2}};
																 
	partialSolution sol = fromIntArray(samplePuzzle);
	sol = solve(sol);
	int sampleSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	toIntArray(sol,sampleSolution);
	
	verifyEqual(correctAnswer,sampleSolution);
}

void solverTestSuite::partialEliminationTest() {
	int samplePuzzle[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 0, 7, 4, 5, 0, 2, 0, 0},
						 							 {0, 0, 9, 0, 0, 0, 0, 0, 1},
						 							 {2, 0, 0, 9, 0, 0, 3, 4, 0},
													 {0, 9, 6, 0, 8, 2, 0, 0, 0},
													 {0, 0, 0, 0, 0, 0, 0, 0, 0},
													 {0, 0, 0, 1, 9, 0, 8, 6, 0},
													 {0, 8, 1, 0, 0, 7, 0, 0, 3},
													 {3, 0, 0, 0, 0, 0, 5, 0, 0},
													 {0, 0, 2, 0, 3, 4, 1, 0, 0}};
	
	int correctAnswer[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{6, 3, 7, 4, 5, 1, 2, 8, 9},
						 							 {8, 4, 9, 2, 7, 3, 6, 5, 1},
						 							 {2, 1, 5, 9, 6, 8, 3, 4, 7},
													 {4, 9, 6, 3, 8, 2, 7, 1, 5},
													 {1, 5, 8, 7, 4, 6, 9, 3, 2},
													 {7, 2, 3, 1, 9, 5, 8, 6, 4},
													 {5, 8, 1, 6, 2, 7, 4, 9, 3},
													 {3, 7, 4, 8, 1, 9, 5, 2, 6},
													 {9, 6, 2, 5, 3, 4, 1, 7, 8}};
																 
	partialSolution sol = fromIntArray(samplePuzzle);
	sol = solve(sol);
	int sampleSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	toIntArray(sol,sampleSolution);
	
	verifyEqual(correctAnswer,sampleSolution);
}

void solverTestSuite::branchTest() {
	int samplePuzzle[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{0, 0, 7, 4, 5, 0, 2, 0, 0},
						 							 {0, 0, 9, 0, 0, 0, 0, 0, 1},
						 							 {2, 0, 0, 9, 0, 0, 3, 4, 0},
													 {0, 9, 6, 0, 8, 2, 0, 0, 0},
													 {0, 0, 0, 0, 0, 0, 0, 0, 0},
													 {0, 0, 0, 1, 9, 0, 8, 6, 0},
													 {0, 8, 1, 0, 0, 7, 0, 0, 3},
													 {3, 0, 0, 0, 0, 0, 5, 0, 0},
													 {0, 0, 2, 0, 3, 4, 1, 0, 0}};
	
	int correctAnswer[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
													{{6, 3, 7, 4, 5, 1, 2, 8, 9},
						 							 {8, 4, 9, 2, 7, 3, 6, 5, 1},
						 							 {2, 1, 5, 9, 6, 8, 3, 4, 7},
													 {4, 9, 6, 3, 8, 2, 7, 1, 5},
													 {1, 5, 8, 7, 4, 6, 9, 3, 2},
													 {7, 2, 3, 1, 9, 5, 8, 6, 4},
													 {5, 8, 1, 6, 2, 7, 4, 9, 3},
													 {3, 7, 4, 8, 1, 9, 5, 2, 6},
													 {9, 6, 2, 5, 3, 4, 1, 7, 8}};
																 
	partialSolution sol = fromIntArray(samplePuzzle);
	sol = solve(sol);
	int sampleSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	toIntArray(sol,sampleSolution);
	
	verifyEqual(correctAnswer,sampleSolution);
}

