#include "func.h"

// opens and reads file data into respective vectors
void file_open_read(std::ifstream& fin, std::string finname, std::vector<std::string>& CategVec, std::vector<double>& AmtVec) {
	try {
		fin.open(finname); 

		// if any problems opening file then throw file name
		if (!fin) {
			throw finname; 
		}
	}
	catch (std::string filename) { // catch problems here
		std::cout << "ERROR WITH " << filename << std::endl;
	}

	// if we make it here, then nothing bad happened
	std::string str;
	double amt;
	while (!fin.eof()) {
		fin >> str >> amt;

		// storing file data into vectors
		CategVec.push_back(str);
		AmtVec.push_back(amt);
	}
}

double calcTotal(std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str) {
	double total = 0; 
	for (int i = 0; i < AmtVec.size(); i++) {
		if (CategVec.at(i) == str) {
			total = total + AmtVec.at(i);
		}
	}

	return total;
}

// calculate the mean
double calcMean(std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str) {
	double total = 0;
	int x = 0;
	for (int i = 0; i < AmtVec.size(); i++) {
		if (CategVec.at(i) == str) {
			total = total + AmtVec.at(i);
			x++;
		}
	}
	
	double mean = total / x;

	return mean;
}

// calculate the median
double calcMedian(std::vector<double>& tempVec, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str) {
	tempVec.clear();
	// sort the vector before calculating finding median
	SelectionSort(tempVec, CategVec, AmtVec, str);

	double median = 0;
	if (tempVec.size() != 0) {
		if (tempVec.size() % 2 == 0) {
			median = (tempVec.at(tempVec.size() / 2) + tempVec.at((tempVec.size() / 2) + 1)) / 2;
			return median;
		}
		else {
			median = tempVec.at(tempVec.size() / 2);
			return median;
		}
	}
	else {
		return -1;
	}
}

// sorts the vectors 
void SelectionSort(std::vector<double>& tempVec, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str) {
	int j = 0;
	for (int i = 0; i < AmtVec.size(); i++) {
		if (CategVec.at(i) == str) {
			tempVec.push_back(AmtVec.at(i));
		}
	}

	// temporary variable used for swapping values
	double temp;

	// iterate through the entire array
	for (int i = 0; i < tempVec.size(); i++) {

		// iterate through remaining, unsorted array, and find index of smallest element
		int min_idx = i;
		for (int j = i + 1; j < tempVec.size(); j++) {

			// keep track of the smallest element
			if (tempVec.at(min_idx) > tempVec.at(j)) {
				min_idx = j;
			}
		}

		// swapping the value of the smallest element (in unsorted array), and appending to the sorted part of the array
		temp = tempVec.at(min_idx);
		tempVec[min_idx] = tempVec.at(i);
		tempVec[i] = temp;
	}
}

// opens and write to file
void file_open_write(std::ofstream& fout, std::string foutname, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::vector<double>& tempVec) {
	try {
		// try to open file
		fout.open(foutname); 

		// if any problems occurs while opening file, then throw file name
		if (!fout) {
			throw foutname;
		}
	}
	catch (std::string filename) { // catch file name from above
		std::cout << "ERROR WITH " << filename << std::endl;
	}

	// writing data to file

	if (calcMean(CategVec, AmtVec, "DVD") == -1) {
		fout << "DVD \t" << calcTotal(CategVec, AmtVec, "DVD") << "\t" << "NaN" << "\t" << calcMedian(tempVec, CategVec, AmtVec, "DVD") << std::endl;
	}
	else {
		fout << "DVD \t" << calcTotal(CategVec, AmtVec, "DVD") << "\t" << calcMean(CategVec, AmtVec, "DVD") << "\t" << calcMedian(tempVec, CategVec, AmtVec, "DVD") << std::endl;
	}

	if (calcMean(CategVec, AmtVec, "TV") == -1) {
		fout << "TV  \t" << calcTotal(CategVec, AmtVec, "TV") << "\t" << "NaN" << "\t" << calcMedian(tempVec, CategVec, AmtVec, "TV") << std::endl;
	}
	else {
		fout << "TV  \t" << calcTotal(CategVec, AmtVec, "TV") << "\t" << calcMean(CategVec, AmtVec, "TV") << "\t" << calcMedian(tempVec, CategVec, AmtVec, "TV") << std::endl;
	}

	if (calcMean(CategVec, AmtVec, "MUSIC") == -1) {
		fout << "MUSIC \t" << calcTotal(CategVec, AmtVec, "MUSIC") << "\t" << "NaN" << "\t" << calcMedian(tempVec, CategVec, AmtVec, "MUSIC") << std::endl;
	}
	else {
		fout << "MUSIC \t" << calcTotal(CategVec, AmtVec, "MUSIC") << "\t" << calcMean(CategVec, AmtVec, "MUSIC") << "\t" << calcMedian(tempVec, CategVec, AmtVec, "MUSIC") << std::endl;
	}
}
