#ifndef SUDOKU_EQUALITY_TESTSUITE
#define SUDOKU_EQUALITY_TESTSUITE

#include<cpptest.h>
#include<cstdint>
#include<string>
#include"partialSolution.hpp"
#include"defs.hpp"

class equalityTestSuite : public Test::Suite {
	
protected:
	void verifyEqual(const uint32_t & expected, const uint32_t & actual);
	void verifyEqual(const partialSolution & expected, const partialSolution & actual);
	void verifyEqual(const bool & expected, const bool & actual);
	void verifyEqual(const int & expected, const int & actual);
	void verifyEqual(const int expected[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE],
						  const int actual[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
	void verifyEqual(const std::string expected, const std::string actual);
};

#endif
