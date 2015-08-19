#ifndef SUDOKU_SOLVERTESTSUITE
#define SUDOKU_SOLVERTESTSUITE

#include"equalityTestSuite.hpp"

class solverTestSuite : public equalityTestSuite {
public:
	solverTestSuite()
	{
		TEST_ADD(solverTestSuite::eliminationTest)
		//TEST_ADD(solverTestSuite::partialEliminationTest)
		TEST_ADD(solverTestSuite::branchTest)
	}
	
private:
	void eliminationTest();
	void partialEliminationTest();
	void branchTest();
};

#endif
