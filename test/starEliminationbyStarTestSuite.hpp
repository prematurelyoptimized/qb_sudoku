#ifndef SUDOKU_STARELIMINATIONBYSTARTESTSUITE
#define SUDOKU_STARELIMINATIONBYSTARTESTSUITE

#include"equalityTestSuite.hpp"

class starEliminationbyStarTestSuite : public equalityTestSuite {
public:
	starEliminationbyStarTestSuite()
	{
		TEST_ADD(starEliminationbyStarTestSuite::rowByBlocksPositive)
		TEST_ADD(starEliminationbyStarTestSuite::rowByBlocksNegative)
		TEST_ADD(starEliminationbyStarTestSuite::blockByRowsPositive)
		TEST_ADD(starEliminationbyStarTestSuite::blockByRowsNegative)
		TEST_ADD(starEliminationbyStarTestSuite::columnByBlocksPositive)
		TEST_ADD(starEliminationbyStarTestSuite::columnByBlocksNegative)
		TEST_ADD(starEliminationbyStarTestSuite::blockByColumnsPositive)
		TEST_ADD(starEliminationbyStarTestSuite::blockByColumnsNegative)
	}
	
private:
	void rowByBlocksPositive();
	void rowByBlocksNegative();
	void blockByRowsPositive();
	void blockByRowsNegative();
	void columnByBlocksPositive();
	void columnByBlocksNegative();
	void blockByColumnsPositive();
	void blockByColumnsNegative();
};

#endif
