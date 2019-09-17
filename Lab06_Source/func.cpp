#include "func.h"

const std::string inputFile = "input.txt";
const std::string outputFile = "output.txt";
const std::string sortedOutputFile = "sorted_output.txt";
const std::string showMenu = "\n1. Read from file \n2. Write to file \n3. Sorted write to file \n4. Quit\n\nEnter your choice >>> ";

std::ifstream fin;
std::ofstream fout;

std::vector<double> resultcoords;

// main menu loop
void main_menu() {
	bool quit = false; 
	unsigned int userChoice;

	while (quit != true) {
		std::cout << showMenu;
		std::cin >> userChoice;

		switch (userChoice) {
		case 1: 
			file_read_open(fin, inputFile, resultcoords);
			break;
		case 2:
			file_write_open(fout, outputFile, resultcoords);
			break;
		case 3:
			file_sorted_write_open(fout, sortedOutputFile, resultcoords);
			break;
		case 4:
			quit = true;
			break;
		}
		
	}
}

// opens and reads from a file
void file_read_open(std::ifstream& fin, std::string finname, std::vector<double>& vec) {
	
	// implement try-catch for file opening
	try {
		fin.open(finname);

		// if fin fails then throw
		if (!fin) {
			throw finname;
		}
	}
	// catch any errors from above
	catch (std::string name) {
		std::cout << "ERROR opening: " << name << std::endl;
	}
	
	// if we get here, code is good

	// while not end-of-file, read data into temporary variables
	while (!fin.eof()) {
		double x1, y1, z1, x2, y2, z2;
		fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		// push_back calculated values into a vec
		vec.push_back(calcDistance(x1, y1, z1, x2, y2, z2));
	}
}

// opens and write to a file
void file_write_open(std::ofstream& fout, std::string foutname, std::vector<double>& vec) {

	// implement try-catch for file opening
	try {
		fout.open(foutname);

		// if file is open, then vector data to file
		if (fout.is_open()) {
			for (const auto& i : vec) {
				fout << i << std::endl;
			}
		}
		else {
			throw foutname;
		}
	}
	// catch any errors from above
	catch (std::string name) {
		std::cout << "ERROR opening: " << name << std::endl;
	}
}

void file_sorted_write_open(std::ofstream& fout, std::string foutname, std::vector<double>& vec) {
	double temp;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (vec[i] > vec[j]) {
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
	
	// implement try-catch for file opening
	try {
		fout.open(foutname);

		// if file is open, then vector data to file
		if (fout.is_open()) {
			for (const auto& i : vec) {
				fout << i << std::endl;
			}
		}
		else {
			throw foutname;
		}
	}
	// catch any errors from above
	catch (std::string name) {
		std::cout << "ERROR opening: " << name << std::endl;
	}
}

// calculate distance between (x1, y1, z1) to (x2, y2, z2)
// result is returned
double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	double distx = (x1 - x2) * (x1 - x2);
	double disty = (y1 - y2) * (y1 - y2);
	double distz = (z1 - z2) * (z1 - z2);
	double underroot = distx + disty + distz;
	double sqrert = sqrt(underroot);
	return sqrert;
}
