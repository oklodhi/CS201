// Omer Khan 
// Assignment 7
// CS201R - GHARIBI
// MAY 5, 2019

// import all needed libraries 
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

// create a database of maps.
// the map contains a string key
// and vector of int for elements
using database = std::map< std::string, std::vector<int> >;

// fill the database using the input file
// so open and read and store the file info
// into database map
database create_from(std::ifstream& input, std::string filename, int& total_ratings) {

	// database object
	database db; 
	
	// temporary variables for file input
	int ratings;
	std::string restaurants; 

	// open file
	input.open(filename); 

	// if file doenst open
	if (!input) {
		std::cout << "ERROR" << std::endl;
	}

	// read the first line of file which = total reviews
	input >> total_ratings;
	//std::cout << total_ratings << std::endl;

	// as long as file doesnt end, keep reading
	while (!input.eof()) {
		input.ignore();
		std::getline(input, restaurants);
		input >> ratings;

		// storing info into map database
		db[restaurants].push_back(ratings);

		//std::cout << restaurants << "\n" << ratings << std::endl;
	}

	// close file
	input.close();

	return db; 
}

// print the results
void print_result(database db) {
	// variable to store the avg review ratings
	double avg_sum;

	// iterate through map keys
	for (const auto& pair : db) {
		std::cout << pair.first << ": \t";

		avg_sum = 0.0;

		// iterate through map key's elements
		for (int i : pair.second) {
			// this is keeping track of total ratings
			avg_sum = avg_sum + i;
		}
		std::cout << pair.second.size() << " reviewers.\t";

		// take avg ratings 
		avg_sum = avg_sum / pair.second.size();

		std::cout << "Average of " << avg_sum << "/5" << std::endl;
		
		std::cout << std::endl;
	}
}

int main() {
	// file name as CONST
	const std::string FILENAME = "ratings.txt";

	// database is a map of strings, and vector of ints
	using database = std::map< std::string, std::vector<int> >;

	// file stream object
	std::ifstream input; 
	// total ratings in a file
	int total_ratings;

	// database object db is a const, and initiated from function create_from
	const database db = create_from(input, FILENAME, total_ratings);

	// print resulting information
	print_result(db);

	return 0;
}