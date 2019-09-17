// Omer Khan
// mokddp@mail.umkc.edu	
// March 14
// CS201L Lab 08

#include "func.h"

int main() {
	const std::string INPUT_FILE = "input.txt";
	const std::string OUTPUT_FILE = "output.txt";

	const std::string DVD = "DVD";
	const std::string TV = "TV";
	const std::string MUSIC = "MUSIC";

	std::vector<std::string> categorie_vector; 
	std::vector<double> amount_vector;
	std::vector<double> tempVec;
	std::ifstream fin; 
	std::ofstream fout; 

	// open files and read from and write to another file
	file_open_read(fin, INPUT_FILE, categorie_vector, amount_vector);

	file_open_write(fout, OUTPUT_FILE, categorie_vector, amount_vector, tempVec);

	return 0;
}