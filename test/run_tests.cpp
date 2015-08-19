#include<cpptest.h>
#include"partialSolutionTestSuite.hpp"
#include"utilTestSuite.hpp"
#include"processofEliminationTestSuite.hpp"
#include"starEliminationbyStarTestSuite.hpp"
#include"solverTestSuite.hpp"

int main(void) {
	Test::TextOutput output(Test::TextOutput::Verbose);
	
	partialSolutionTestSuite psts;
	utilTestSuite uts;
	processofEliminationTestSuite poets;
	starEliminationbyStarTestSuite sebsts;
	solverTestSuite sts;
	
	psts.run(output);
	uts.run(output);
	poets.run(output);
	sts.run(output);
	sebsts.run(output);
}
