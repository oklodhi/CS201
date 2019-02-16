// Source file includes function definitions

// include header files here
#include "func.h"

void mainMenu() {
	// add switch inside while loop
	char menuChoice;

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
			std::cout << "Option #1" << std::endl;
			break;
		case '2':
			std::cout << "Option #2" << std::endl;
			break;
		case '3':
			std::cout << "Option #3" << std::endl;
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

void openFile() {

}

void readFile() {

}

void closeFile() {

}

void printCustomersData(const int id[], const std::string first[], const std::string last[], const double savings_Account[], const double checking_Account[], int size) {

}

void printNames(const int id[], const std::string first[], const std::string last[], int size) {

}

void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size) {

}