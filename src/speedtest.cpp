#include<iostream>
#include<fstream>
#include<vector>
#include"solver.hpp"
#include"time.hpp"

int main(void) {
	std::ifstream infile("hardpuzzles.sdm",std::ios_base::in);
	std::string buffer;
	std::vector<partialSolution> problems;
	
	while(infile.good()) {
		std::getline(infile,buffer);
		if(buffer.size()!=SUDOKU_GRID_SIZE*SUDOKU_GRID_SIZE) {
			std::cout << "Failed to read line: " << buffer << '\n';
		} else {
			problems.push_back(parseSDMLine(buffer.c_str()));
		}
	}
	
	precision_time::timestamp_t starttime;
	precision_time::timestamp_t stoptime;
	std::vector<partialSolution> solutions;
	solutions.reserve(problems.size());
	starttime = precision_time::now();
	for(std::vector<partialSolution>::iterator it=problems.begin();it!=problems.end();++it) {
		solutions.push_back(solve(*it));
	}
	stoptime = precision_time::now();
	
	for(std::vector<partialSolution>::iterator it=solutions.begin();it!=solutions.end();++it) {
		std::cout << generateSDMLine(*it);
	}
	std::cout << "Took " << (double)(stoptime-starttime)/precision_time::TICKS_PER_SEC << " seconds\n";
}
