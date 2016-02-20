/*  Noah Benham
	Miniproject 2
	18 Feb 2015
	C++ */

#include <iostream>
#include <fstream>

#include "Executive.h"

int main(int argc, char* argv[]) {
	std::ifstream intStr;
	if (argc > 1) {
		intStr.open(argv[1]); // attempt to open file given as attribute
	}
	else {
		intStr.open("dict.txt"); // assume filename is data.txt
	}

	// Check valid filename
	if (!intStr.is_open()) {
		std::cout << "Error: File did not open. Check filename!\n";
	}
	else {
		Executive* exec = new Executive(intStr);
		exec->mainProcess();
		delete exec;
	}

	intStr.close(); // close filestream
	return 0;
}
