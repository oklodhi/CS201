#include "func.h"

// initialize constant strings
const std::string ERROR_MESSAGE = "Invalid input recieved, you must enter a decimal number.";
const std::string LESS_THAN_ZERO = "cannot be less than 0";
const std::string INVALID_VALUE = "Invalid value";

// functions gets the number of miles and returns it 
double GetMiles() {
	int number; 

	do { // do while keeps asking for input if first input was bad
		try {
			std::cout << "Enter number of miles: " << std::endl;
			std::cin >> number;

			if (std::cin.fail()) { // if cin bad
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				throw std::runtime_error(INVALID_VALUE);
			} else if (number < 0) { // if cin < 0

				throw std::runtime_error("Miles " + LESS_THAN_ZERO);
			}
			else { // otherwise return number
				return number;
			}
		}
		catch (std::runtime_error &excpt) {
			std::cout << excpt.what() << std::endl;
		}
	} while (true);
}

double GetGallons() {
	int number;

	do { // do while keeps asking for input if first input was badv
		try {
			std::cout << "Enter number of gallons: " << std::endl;
			std::cin >> number;

			if (std::cin.fail()) { // if cin bad
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				throw std::runtime_error(INVALID_VALUE);
			}
			else if (number < 0) { // if cin < 0 

				throw std::runtime_error("Gallons " + LESS_THAN_ZERO);
			}
			else { // otherwise return number
				return number;
			}
		}
		catch (std::runtime_error &excpt) {
			std::cout << excpt.what() << std::endl;
		}
	} while (true);
}

double GetMPG(std::vector<double> miles, std::vector<double> gallons) {
	double sum = 0;
	int i;

	// iterate through the vectors and find the sum of all MPGS
	for (i = 0; i < miles.size(); i++) {
		sum = sum + (miles.at(i) / gallons.at(i));
	}

	// return avg MPG
	return sum / i;
}
