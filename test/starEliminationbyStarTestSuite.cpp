#include"starEliminationbyStarTestSuite.hpp"
#include"partialSolution.hpp"
#include"defs.hpp"
#include"algorithms.hpp"

void starEliminationbyStarTestSuite::rowByBlocksPositive(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[i][j] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[i+SUDOKU_BLOCK_SIZE][j+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	partialSolution correctAnswer = sol;
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		correctAnswer.state[0][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		correctAnswer.state[SUDOKU_BLOCK_SIZE][(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE] = 0x00000002;
	}
	
	verifyEqual(true,rowEliminationbyBlocks(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::rowByBlocksNegative(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
	
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[i][j] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[i+SUDOKU_BLOCK_SIZE][j+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[0][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[SUDOKU_BLOCK_SIZE][(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE] = 0x00000002;
	}
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,rowEliminationbyBlocks(sol));
	verifyEqual(correctAnswer,sol);
}

void starEliminationbyStarTestSuite::blockByRowsPositive(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[0][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[SUDOKU_BLOCK_SIZE][(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE] = 0x00000002;
	}
	
	partialSolution correctAnswer = sol;
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			correctAnswer.state[i][j] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			correctAnswer.state[i+SUDOKU_BLOCK_SIZE][j+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	verifyEqual(true,blockEliminationbyRows(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::blockByRowsNegative(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[0][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[SUDOKU_BLOCK_SIZE][(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE] = 0x00000002;
	}
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[i][j] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[i+SUDOKU_BLOCK_SIZE][j+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,blockEliminationbyRows(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::columnByBlocksPositive(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[j][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[j+SUDOKU_BLOCK_SIZE][i+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	partialSolution correctAnswer = sol;
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		correctAnswer.state[i][0] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		correctAnswer.state[(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE][SUDOKU_BLOCK_SIZE] = 0x00000002;
	}
	
	verifyEqual(true,columnEliminationbyBlocks(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::columnByBlocksNegative(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[j][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[j+SUDOKU_BLOCK_SIZE][i+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[i][0] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE][SUDOKU_BLOCK_SIZE] = 0x00000002;
	}
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,columnEliminationbyBlocks(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::blockByColumnsPositive(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[i][0] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE][SUDOKU_BLOCK_SIZE] = 0x00000002;
	}
	
	partialSolution correctAnswer = sol;
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			correctAnswer.state[j][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			correctAnswer.state[j+SUDOKU_BLOCK_SIZE][i+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	verifyEqual(true,blockEliminationbyColumns(sol));
	verifyEqual(correctAnswer, sol);
}

void starEliminationbyStarTestSuite::blockByColumnsNegative(){
	partialSolution sol;
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			sol.state[i][j] = 0;
			
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		sol.state[i][0] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
		sol.state[(i+SUDOKU_BLOCK_SIZE)%SUDOKU_GRID_SIZE][SUDOKU_BLOCK_SIZE] = 0x00000002;
	}
	for(size_t i=1;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++) {
			sol.state[j][i] = 0x00000001 & SUDOKU_LOW_BIT_MASK;
			sol.state[j+SUDOKU_BLOCK_SIZE][i+SUDOKU_BLOCK_SIZE] = 0x00000002 & SUDOKU_LOW_BIT_MASK;
		}
	
	partialSolution correctAnswer = sol;
	verifyEqual(false,blockEliminationbyColumns(sol));
	verifyEqual(correctAnswer, sol);
}

