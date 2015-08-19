#include"utilTestSuite.hpp"
#include"defs.hpp"

void utilTestSuite::popcountTest() {
	verifyEqual(32,(int)popcount(-1));
	verifyEqual(1,(int)popcount(1));
	verifyEqual(16,(int)popcount(0x55555555));
}

void utilTestSuite::defineTest3() {
	verifyEqual(3,SUDOKU_BLOCK_SIZE);
	verifyEqual(9,SUDOKU_GRID_SIZE);
	verifyEqual(0x000001FF,SUDOKU_LOW_BIT_MASK);
	verifyEqual(0x01FF0000,SUDOKU_HIGH_BIT_MASK);
}

void utilTestSuite::allbutoneTest() {
	uint32_t v[] = {0x0000FFFF, 0x0000FFFE, 0xFFFFFFEF};
	verifyEqual((uint32_t)0x00000011,bitwiseAllButOne(3,v));
}

void utilTestSuite::lowbitTest() {
	uint32_t v = 0x01000000;
	verifyEqual(v,extractLowBit(v));
	v = 0x01100000;
	verifyEqual((uint32_t)0x00100000,extractLowBit(v));
	v = 0x01234ABC;
	verifyEqual((uint32_t)0x00000004,extractLowBit(v));
}
