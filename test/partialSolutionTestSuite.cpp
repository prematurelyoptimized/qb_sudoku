#include"partialSolutionTestSuite.hpp"
#include"partialSolution.hpp"

uint32_t partialSolutionTestSuite::_conversions[16]={0x0001FFFE,
														  			 0x0002FFFD,
														  			 0x0004FFFB,
														  			 0x0008FFF7,
														  	 		 0x0010FFEF,
														  			 0x0020FFDF,
														  			 0x0040FFBF,
														  			 0x0080FF7F,
														  			 0x0100FEFF,
														  			 0x0200FDFF,
														  			 0x0400FBFF,
														  			 0x0800F7FF,
														  			 0x1000EFFF,
														  			 0x2000DFFF,
														  			 0x4000BFFF,
														  			 0x80007FFF};
														  			 
int partialSolutionTestSuite::_sampleSolution[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]=
																{{1, 6, 5, 4, 8, 3, 7, 2, 9},
									 							 {2, 4, 3, 9, 7, 1, 6, 8, 5},
									 							 {9, 7, 8, 5, 6, 2, 3, 4, 1},
																 {5, 8, 4, 3, 2, 7, 1, 9, 6},
																 {6, 9, 7, 1, 4, 5, 2, 3, 8},
																 {3, 1, 2, 6, 9, 8, 5, 7, 4},
																 {4, 2, 1, 7, 5, 9, 8, 6, 3},
																 {8, 3, 6, 2, 1, 4, 9, 5, 7},
																 {7, 5, 9, 8, 3, 6, 4, 1, 2}};

void partialSolutionTestSuite::setup() {
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++)
		for(size_t j=0;j<SUDOKU_GRID_SIZE;j++)
			_sampleData.state[i][j] = 0;
			
	_sampleData.state[0][0] = 0x00010000 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	_sampleData.state[1][1] = 0x00100000 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
}

void partialSolutionTestSuite::tear_down() {

}

void partialSolutionTestSuite::intArrayConversionFrom() {
	int testgrid[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	partialSolution correctAnswer;
	
	for(size_t i=0;i<SUDOKU_GRID_SIZE;i++) {
		testgrid[0][i] = i+1;
		correctAnswer.state[0][i] = _conversions[i] & (SUDOKU_HIGH_BIT_MASK | SUDOKU_LOW_BIT_MASK);
		testgrid[1][i] = 30;
		correctAnswer.state[1][i] = 0;
		testgrid[2][i] = -5;
		correctAnswer.state[2][i] = 0;
		for(int j=3;j<SUDOKU_GRID_SIZE;j++) {
			testgrid[j][i] = 0;
			correctAnswer.state[j][i] = 0;
		}
	}
	
	partialSolution answer = fromIntArray(testgrid);
	verifyEqual(correctAnswer,answer);
}

void partialSolutionTestSuite::intArrayConversionTo() {
	int answer[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE];
	partialSolution sol = fromIntArray(_sampleSolution);
	toIntArray(sol,answer);
	verifyEqual(_sampleSolution,answer);
}

void partialSolutionTestSuite::equality() {
	partialSolution different = _sampleData;
	different.state[3][3] = ~different.state[3][3];
	TEST_ASSERT(different==different);
	TEST_ASSERT(different!=_sampleData);
}

void partialSolutionTestSuite::knownPropagation() {
	partialSolution localSampleData = _sampleData;
	propagateKnownValues(localSampleData);
	
	partialSolution correctAnswer = _sampleData;
	correctAnswer.state[0][0] = 0x0001FFFE & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[0][1] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[0][2] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[1][0] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[1][1] = 0x0010FFEF & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[1][2] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[2][0] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[2][1] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	correctAnswer.state[2][2] = 0x00000011 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++) {
		correctAnswer.state[0][i] = 0x00000001 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
		correctAnswer.state[i][0] = 0x00000001 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
		correctAnswer.state[1][i] = 0x00000010 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
		correctAnswer.state[i][1] = 0x00000010 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	}
	
	verifyEqual(correctAnswer, localSampleData);
}

void partialSolutionTestSuite::valueSetting() {
	partialSolution localSampleData = _sampleData;
	setValue(localSampleData,2,2,0x00000002);

	partialSolution correctAnswer = _sampleData;
	for(size_t i=0;i<SUDOKU_BLOCK_SIZE;i++)
		for(size_t j=0;j<SUDOKU_BLOCK_SIZE;j++)
			correctAnswer.state[i][j] |= 0x00000002 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	for(size_t i=SUDOKU_BLOCK_SIZE;i<SUDOKU_GRID_SIZE;i++){
		correctAnswer.state[i][2] = 0x00000002 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);	
		correctAnswer.state[2][i] = 0x00000002 & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
	}
	correctAnswer.state[2][2] = 0x0002FFFD & (SUDOKU_LOW_BIT_MASK | SUDOKU_HIGH_BIT_MASK);
}

void partialSolutionTestSuite::completionCheck() {
	partialSolution localSampleData = fromIntArray(_sampleSolution);
	verifyEqual(false,isComplete(_sampleData));
	verifyEqual(true,isComplete(localSampleData));		
}

void partialSolutionTestSuite::SDMLineWriteCheck() {
	verifyEqual(std::string("165483729243971685978562341584327196697145238312698574421759863836214957759836412\n"),
					generateSDMLine(fromIntArray(_sampleSolution)));
}

void partialSolutionTestSuite::SDMLineReadCheck() {
	verifyEqual(fromIntArray(_sampleSolution),parseSDMLine("165483729243971685978562341584327196697145238312698574421759863836214957759836412\n"));
}

