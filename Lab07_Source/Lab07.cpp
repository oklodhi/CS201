// Omer Khan
// mokddp@mail.umkc.edu	
// March 7
// CS201L Lab 07

#include "func.h"

int main() {
	//initialize vectors
	std::vector<double> miles;
	std::vector<double> gallons;

	bool quit = false; 
	int choice; 

	// main menu loop
	while (quit != true) {

		std::cout << "1. Enter data \n2. Quit (show data)" << std::endl;
		std::cin >> choice;

		// incase user enters a non-numeric value
		while (!std::cin) {
			std::cout << "Invalid input, try again!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (choice) {
			// option 1: enter data
		case 1:
			miles.push_back(GetMiles());
			gallons.push_back(GetGallons());
			break; 
			// option 2: show data and quit
		case 2: 
			std::cout << "Your average MPG is: " << GetMPG(miles, gallons);
			quit = true;
			break;
		}
	}
}