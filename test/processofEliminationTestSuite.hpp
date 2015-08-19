#ifndef SUDOKU_PROCESSOFELIMINATIONTESTSUITE
#define SUDOKU_PROCESSOFELIMINATIONTESTSUITE

#include"equalityTestSuite.hpp"

class processofEliminationTestSuite : public equalityTestSuite {
public:
	processofEliminationTestSuite()
	{
		TEST_ADD(processofEliminationTestSuite::simpleDeductionOnCells)
		TEST_ADD(processofEliminationTestSuite::noDeductionOnCells)
		TEST_ADD(processofEliminationTestSuite::simpleDeductionOnBlocks)
		TEST_ADD(processofEliminationTestSuite::noDeductionOnBlocks)
		TEST_ADD(processofEliminationTestSuite::simpleDeductionOnRows)
		TEST_ADD(processofEliminationTestSuite::noDeductionOnRows)
		TEST_ADD(processofEliminationTestSuite::simpleDeductionOnColumns)
		TEST_ADD(processofEliminationTestSuite::noDeductionOnColumns)
	}
	
private:
	void simpleDeductionOnCells();
	void noDeductionOnCells();
	void simpleDeductionOnBlocks();
	void noDeductionOnBlocks();
	void simpleDeductionOnRows();
	void noDeductionOnRows();
	void simpleDeductionOnColumns();
	void noDeductionOnColumns();
};

#endif
