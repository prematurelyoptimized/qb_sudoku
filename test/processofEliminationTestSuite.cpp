#include"processofEliminationTestSuite.hpp"
#include"partialSolution.hpp"
#include"defs.hpp"
#include"algorithms.hpp"

void processofEliminationTestSuite::simpleDeductionOnCells() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	sol.state[0][0] = 0x0000FFF7 & SUDOKU_LOW_BIT_MASK;
	sol.state[1][1] = 0x00040000 & SUDOKU_HIGH_BIT_MASK;
	sol.state[2][2] = 0x0000FFFA & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	correctAnswer.state[0][0] = 0x0008FFF7 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	propagateValue(correctAnswer,0,0,0x00000008);
	
	verifyEqual(true,processOfEliminationbyCells(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::noDeductionOnCells() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	sol.state[1][1] = 0x0004FFFB & SUDOKU_HIGH_BIT_MASK;
	sol.state[2][2] = 0x0000FFFA & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,processOfEliminationbyCells(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::simpleDeductionOnBlocks() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=0;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++)
			sol.state[i][j] = 0x00000021 & SUDOKU_LOW_BIT_MASK;
			
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[0][1] = 0x0000FFD1 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	correctAnswer.state[0][0] = 0x0001FFFE & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[0][1] = 0x0020FFDF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	propagateValue(correctAnswer,0,0,0x00000001);
	propagateValue(correctAnswer,0,1,0x00000020);
	
	verifyEqual(true,processOfEliminationbyBlocks(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::noDeductionOnBlocks() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=0;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++)
			sol.state[i][j] = 0x0000FF21 & SUDOKU_LOW_BIT_MASK;
			
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[0][1] = 0x0100FEFF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	sol.state[1][1] = 0x0000FF20 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,processOfEliminationbyBlocks(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::simpleDeductionOnRows() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
	
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		sol.state[0][i] = 0x00000021 & SUDOKU_LOW_BIT_MASK;
		
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[0][1] = 0x0000FFD1 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	correctAnswer.state[0][0] = 0x0001FFFE & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[0][1] = 0x0020FFDF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	propagateValue(correctAnswer,0,0,0x00000001);
	propagateValue(correctAnswer,0,1,0x00000020);
	
	verifyEqual(true,processOfEliminationbyRows(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::noDeductionOnRows() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
	
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		sol.state[0][i] = 0x00000F21 & SUDOKU_LOW_BIT_MASK;
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[0][1] = 0x0100FEFF & (SUDOKU_LOW_BIT_MASK + SUDOKU_HIGH_BIT_MASK);
	sol.state[0][2] = 0x0000FF20 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,processOfEliminationbyRows(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::simpleDeductionOnColumns() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
	
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		sol.state[i][0] = 0x00000021 & SUDOKU_LOW_BIT_MASK;
		
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[1][0] = 0x0000FFD1 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	correctAnswer.state[0][0] = 0x0001FFFE & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[1][0] = 0x0020FFDF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	propagateValue(correctAnswer,0,0,0x00000001);
	propagateValue(correctAnswer,1,0,0x00000020);
	
	verifyEqual(true,processOfEliminationbyColumns(sol));
	verifyEqual(correctAnswer, sol);
}

void processofEliminationTestSuite::noDeductionOnColumns() {
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
	
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		sol.state[i][0] = 0x00000F21 & SUDOKU_LOW_BIT_MASK;
	sol.state[0][0] = 0x0000FF2E & SUDOKU_LOW_BIT_MASK;
	sol.state[1][0] = 0x0100FEFF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	sol.state[2][0] = 0x00000F20 & SUDOKU_LOW_BIT_MASK;
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,processOfEliminationbyColumns(sol));
	verifyEqual(correctAnswer, sol);
}

