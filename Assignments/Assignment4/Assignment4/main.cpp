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
		std::cout << arr[i]; 
	}
	std::cout << "Array created... Checking CHECKOUT stage" << std::endl;

	// close file
	fin.close();

	// open ItemsCheckedOUT file
	fin.open("ItemsCheckedOUT.txt"); 

	// temporary variables to store ID and ITEM from file
	unsigned int id; 
	std::string item; 

	// peek the next data in file and store into ID or ITEM
	while (fin.peek()) {
		fin >> id >> item; 
		std::cout << id << " " << item;

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
		std::cout << arr[i];
	}
}