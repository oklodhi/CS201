#include "func.h"

void open_and_read(std::string filename) {
	std::ifstream input;
	input.open(filename);

	if (!input) {
		std::cout << "ERROR" << std::endl;
	}

	int _ratings;
	std::string _restaurant;

	while (!input.eof()) {
		input >> _ratings >> _restaurant;

		std::cout << _ratings << " " << _restaurant << std::endl;
	}

	input.close();
}