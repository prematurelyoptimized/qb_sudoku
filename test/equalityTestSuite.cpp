#include"equalityTestSuite.hpp"

void equalityTestSuite::verifyEqual(const uint32_t & expected, const uint32_t & actual) {
	char msg[44];
	sprintf(msg,"Expected: %08X\t Actual: %08X\n",expected,actual);
	TEST_ASSERT_MSG(expected == actual,msg);
}

void equalityTestSuite::verifyEqual(const bool & expected, const bool & actual) {
	char msg[44];
	sprintf(msg,"Expected: %s\t Actual: %s\n",expected ? "true" : "false", actual ? "true" : "false");
	TEST_ASSERT_MSG(expected == actual, msg);
}

void equalityTestSuite::verifyEqual(const int & expected, const int & actual) {
	char msg[44];
	sprintf(msg,"Expected: %u\t Actual: %u\n",expected, actual);
	TEST_ASSERT_MSG(expected == actual, msg);
}

void equalityTestSuite::verifyEqual(const partialSolution & expected, const partialSolution & actual) {
	char msg[128];
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++){
			sprintf(msg,"i: %u\t j: %u\t Expected: %08X\t Actual: %08X\n",i,j,expected.state[i][j],actual.state[i][j]);
			TEST_ASSERT_MSG(expected.state[i][j] == actual.state[i][j],msg);
		}	
}

void equalityTestSuite::verifyEqual(const int expected[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE],
					  							const int actual[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]) {
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++){
			char msg[128];
			sprintf(msg,"i: %u\t j: %u\t Expected: %u\t Actual: %u\n",i,j,expected[i][j],actual[i][j]);
			TEST_ASSERT_MSG(expected[i][j] == actual[i][j],msg);
		}			  
}

void equalityTestSuite::verifyEqual(const std::string expected, const std::string actual){
	char msg[256];
	sprintf(msg,"Expected: %s\t Actual: %s\n",expected.c_str(),actual.c_str());
	TEST_ASSERT_MSG(expected == actual,msg);
}

