#ifndef SUDOKU_PARTIALSOLUTION
#define SUDOKU_PARTIALSOLUTION

#include<iostream>
#include<cstdint>
#include<string>
#include"defs.hpp"

typedef struct {
	/* The high 16 bits indicate which values are definitely correct
	and the low 16 bits indicate which values are definitely incorrect*/
	uint32_t state[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	
	/* Flag indicating whether the puzzle has a solution */
	bool feasible;
	
} partialSolution;

partialSolution fromIntArray(const int in[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
bool isComplete(const partialSolution & sol);
void toIntArray(const partialSolution & sol, int in[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
bool operator==(const partialSolution & lhs, const partialSolution & rhs);
bool operator!=(const partialSolution & lhs, const partialSolution & rhs);

void propagateKnownValues(partialSolution & sol);
void propagateValue(partialSolution & sol, size_t i, size_t j, uint32_t value);

partialSolution parseSDMLine(const char linein[SUDOKU_GRID_SIZE*SUDOKU_GRID_SIZE]);
std::string generateSDMLine(partialSolution sol);

inline void setValue(partialSolution & sol, size_t i, size_t j, uint32_t value) {
	propagateValue(sol,i,j,value);
}

#endif
