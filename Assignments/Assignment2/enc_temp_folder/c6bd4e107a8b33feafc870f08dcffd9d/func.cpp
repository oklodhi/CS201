// Source file includes function definitions

// include header files here
#include "func.h"

void mainMenu() {
	bool quit = false;
	char menuChoice;

	std::ifstream fileObj;

	const int arrSize = 10;
	int ID[arrSize];
	std::string firstName[arrSize], lastName[arrSize];
	double savingsAcc[arrSize], checkingAcc[arrSize];

	fileHandler("input.txt", fileObj, ID, firstName, lastName, savingsAcc, checkingAcc, arrSize);

	while (quit == false) {
		std::cout << "\n1. Print all customers data" << std::endl;
		std::cout << "2. Print names and IDs" << std::endl;
		std::cout << "3. Print accounts total" << std::endl;
		std::cout << "4. Enter q/Q to quit" << std::endl;

		std::cout << "\nEnter your choice, or 'q' to quit: ";
		std::cin >> menuChoice;

		menuChoice = toupper(menuChoice);

		switch (menuChoice) {
		case '1':
			printCustomersData(ID, firstName, lastName, savingsAcc, checkingAcc, arrSize);
			break;
		case '2':
			printNames(ID, firstName, lastName, arrSize);
			break;
		case '3':
			printTotal(ID, savingsAcc, checkingAcc, arrSize);
			break;
		case '4':
			std::cout << "Option #4" << std::endl;
			quit = true;
			break;
		case 'Q':
			std::cout << "Option Q" << std::endl;
			quit = true;
			break;
		}
	}
}

void fileHandler(std::string filename, std::ifstream& file, int id[], std::string first[], std::string last[], double savings_Account[], double checking_Account[], int size) {
	int n;
	std::string fn, ln;
	float sa, ca;

	file.open(filename);

	if (file.is_open() == true) {
		int i = 0;
		while (file >> n >> fn >> ln >> sa >> ca) {
				id[i] = n;
				first[i] = fn;
				last[i] = ln;
				savings_Account[i] = sa;
				checking_Account[i] = ca;
				i++;
		}
	}
	else {
		std::cout << "ERROR: Can't open file!" << std::endl;
	}

	file.close();
}

void printCustomersData(const int id[], const std::string first[], const std::string last[], const double savings_Account[], const double checking_Account[], int size) {
	std::cout << "\nID " << "\t First " << "\t Last    " << "\tSavings " << "\tChecking " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << id[i] << "\t " << first[i] << "\t " << last[i] << "    \t" << savings_Account[i] << "      \t" << checking_Account[i] << std::endl;
	}
}

void printNames(const int id[], const std::string first[], const std::string last[], int size) {
	std::cout << "\nID " << "\t First " << "\t Last"<< std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << id[i] << "\t " << first[i] << "\t " << last[i] << std::endl;
	}
}

void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size) {
	std::cout << "\nID " << "\tSavings" << " \tChecking" << "\tTotal" << std::endl;
	for (int i = 0; i < size; i++) {
		double total = savings_Account[i] + checking_Account[i];
		std::cout << id[i] << "\t" << savings_Account[i] << "\t     \t" << checking_Account[i] << "\t\t" << total << std::endl;
	}
}