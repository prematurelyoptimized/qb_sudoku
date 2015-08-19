#include<iostream>
#include<fstream>
#include"solver.hpp"

int main(int argc, char *argv[]) {
	if(argc!=3) {
		std::cout << "Usage:\n";
		std::cout << "\t solveSDM input_file output_file\n";
		return 0;
	}
	
	std::ifstream infile(argv[1],std::ios_base::in);
	std::ofstream outfile(argv[2],std::ios_base::out);
	std::string buffer;
	
	while(infile.good()) {
		std::getline(infile,buffer);
		if(buffer.size()!=SUDOKU_GRID_SIZE*SUDOKU_GRID_SIZE) {
			std::cout << "Failed to read line: " << buffer << '\n';
		} else {
			partialSolution sol = parseSDMLine(buffer.c_str());
			sol = solve(sol);
			outfile << generateSDMLine(sol);
		}
	}
}
