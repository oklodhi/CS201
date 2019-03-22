#include "Func.h"

void file_open_and_read(std::string fname) {
	std::ifstream fin; 

	try {
		fin.open(fname);

		if (!fin) {
			throw fname;
		}
	}
	catch (std::string fname) {
		std::cout << "ERROR: " << fname << std::endl;
	}

	std::string str; 
	while (fin >> str) {
		if (str == 0) {

		}
	}
}

