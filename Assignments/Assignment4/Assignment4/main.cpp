// Omer Khan
// CS 201R - MW 7pm
// Prof. Gharibi
// March 28, 2019

#include "Student.h"

int main() {
	// initialize a STUDENT class object
	typedef Students* stu; 

	// create new dynamic array of type STUDENT
	stu arr = new Students[30];
	std::cout << "student array created" << std::endl;

	// input stream object and const file name
	std::ifstream fin;
	const std::string STUDENT_FILE = "students.txt"; 
	const std::string CHECKOUT_FILE = "checkouts.txt";
	const std::string CHECKIN_FILE = "checkins.txt";
	
	// try to open file. if error occurs, catch file name
	try {
		fin.open(STUDENT_FILE);
		std::cout << STUDENT_FILE << " stream opened" << std::endl;

		if (!fin) {
			throw STUDENT_FILE;
		}
	}
	catch (std::string file) { //  something bad went wrong
		std::cout << "ERROR: " << file << std::endl;
	}

	// if we get here... file opened successfully
	// read through file data
	int num_stu = 0; 
	while (!fin.eof()) {
		fin >> arr[num_stu]; 
		num_stu++;
	}

	for (int i = 0; i < num_stu; i++) {
		//std::cout << arr[i]; 
	}
	std::cout << "Array created... Checking CHECKOUT stage" << std::endl;

	// close file
	fin.close();

	// open ItemsCheckedOUT file
	fin.open(CHECKOUT_FILE); 

	// temporary variables to store ID and ITEM from file
	unsigned int id; 
	std::string item; 

	// while there is data in file, read and store into ID or ITEM
	while (!fin.eof()) {
		fin >> id >> item; 

		// iterate through all students and checkout items accordingly
		for (int i = 0; i < num_stu; i++) {
			if (arr[i].GetIdNumber() == id) {
				arr[i] += item;
				std::cout << item << " was added to " << arr[i].GetIdNumber() << std::endl;
				break;
			}
		}
	}

	for (int i = 0; i < num_stu; i++) {
		//std::cout << "TESTING: " << arr[i];
	}

	fin.close(); 

	std::cout << "Checking CHECKIN stage\n" << std::endl;

	// open ItemsCheckedIN file
	fin.open(CHECKIN_FILE); 

	// while there is data in file, read and store into ITEM
	int i = 0;
	while (!fin.eof()) {
		fin >> item; 

		//std::cout << "item: " << item << std::endl;

		while (i < num_stu) {

			std::cout << "ITEM: " << item << std::endl;
			std::cout << "ALL: " << arr[i] << std::endl;



			if (arr[i].HasCheckedOut(item)) {
				std::cout << "BEFORE: " << arr[i] << std::endl;
				arr[i].CheckIn(item);
				std::cout << "AFTER: " << arr[i] << std::endl;
				break;
			}
			else {
				i++;
			}
		}
		//i++;
	}
}