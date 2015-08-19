#ifndef SUDOKU_UTILTESTSUITE
#define SUDOKU_UTILTESTSUITE

#include"equalityTestSuite.hpp"
#include"utils.hpp"

class utilTestSuite : public equalityTestSuite {
public:
	utilTestSuite()
	{
		TEST_ADD(utilTestSuite::popcountTest);
		TEST_ADD(utilTestSuite::defineTest3);
		TEST_ADD(utilTestSuite::allbutoneTest);
		TEST_ADD(utilTestSuite::lowbitTest);
	}
	
private:
	void popcountTest();
	void defineTest3();
	void allbutoneTest();
	void lowbitTest();
};

#endif
