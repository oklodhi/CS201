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
	std::cout << "student array created\n" << std::endl;

	// input stream object and const file name
	std::ifstream fin;
	std::ofstream fout; 
	const std::string UPDATED_STUDENTS_FILE = "Updated_Students.txt";
	const std::string STUDENT_FILE = "students.txt"; 
	const std::string CHECKOUT_FILE = "checkouts.txt";
	const std::string CHECKIN_FILE = "checkins.txt";
	
	// try to open file. if error occurs, catch file name
	try {
		fin.open(STUDENT_FILE);
		std::cout << STUDENT_FILE << " stream opened\n" << std::endl;

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

	std::cout << "\nArray created" << std::endl;

	for (int i = 0; i < num_stu; i++) {
		//std::cout << "TESTING: " << arr[i]; 
	}
	std::cout << "\nChecking CHECKOUT stage\n" << std::endl;

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
		std::cout << "\nTESTING1: " << arr[i];
	}

	// close file
	fin.close(); 

	std::cout << "\nChecking CHECKIN stage" << std::endl;

	// open ItemsCheckedIN file
	fin.open(CHECKIN_FILE); 

	// while there is data in file, read and store into ITEM
	int i = 0;
	while (!fin.eof()) {
		fin >> item; 

		// iterate through all students and check in items
		while (i < num_stu) {
			if (arr[i].HasCheckedOut(item)) {
				arr[i].CheckIn(item);
				std::cout << item << " was removed from " << arr[i].GetIdNumber() << std::endl;
			}
			break;
		}
		i++;
	}

	for (int i = 0; i < num_stu; i++) {
		std::cout << "\nTESTING2: " << arr[i];
	}

	// close file
	fin.close();

	std::cout << "\nChecking OUTPUT stage" << std::endl;

	// try to open output file
	try {
		fout.open(UPDATED_STUDENTS_FILE);
		std::cout << UPDATED_STUDENTS_FILE << " stream opened" << std::endl;
		// if anything wrong happens while accessing output file, then throw file name
		if (!fout) {
			throw UPDATED_STUDENTS_FILE;
		}
	}
	catch (std::string filename) {
		// catch and handle file name
		std::cout << "ERROR: " << filename << std::endl;
	}

	// print updated student data to output file
	for (int i = 0; i < num_stu; i++) {
		fout << arr[i];
	}

	std::cout << "Updated file complete" << std::endl;

	// close file
	fout.close(); 
}