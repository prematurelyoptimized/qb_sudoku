#ifndef SUDOKU_PARTIALSOLUTIONTESTSUITE
#define SUDOKU_PARTIALSOLUTIONTESTSUITE

#include<cstdint>
#include"equalityTestSuite.hpp"
#include"partialSolution.hpp"

class partialSolutionTestSuite : public equalityTestSuite {
public:
	partialSolutionTestSuite()
	{
		TEST_ADD(partialSolutionTestSuite::intArrayConversionFrom)
		TEST_ADD(partialSolutionTestSuite::intArrayConversionTo)
		TEST_ADD(partialSolutionTestSuite::equality)
		TEST_ADD(partialSolutionTestSuite::knownPropagation)
		TEST_ADD(partialSolutionTestSuite::valueSetting)
		TEST_ADD(partialSolutionTestSuite::completionCheck)
		TEST_ADD(partialSolutionTestSuite::SDMLineWriteCheck)
		TEST_ADD(partialSolutionTestSuite::SDMLineReadCheck)
	}
    
protected:
	void setup();
	void tear_down();
	
	partialSolution _sampleData;
	
private:
	static uint32_t _conversions[16];
	static int _sampleSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
									  
	void intArrayConversionFrom();
	void intArrayConversionTo();
	void equality();
	void knownPropagation();
	void valueSetting();
	void completionCheck();
	void SDMLineWriteCheck();
	void SDMLineReadCheck();
};

#endif
