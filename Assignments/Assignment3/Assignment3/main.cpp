// Omer Khan
// CS201R	M/W 7pm
// Assignment 3

#include "func.h"

int main() {
	const int YEAR = GetYear(); 
	const int START_DAY = GetStartDayNumber();
	std::vector<int> DAYS_IN_MONTH_VEC; 

	//std::cout << YEAR << std::endl;
	//std::cout << START_DAY << std::endl << std::endl;

	std::cout << "CALENDAR - " << YEAR << std::endl;
	// iterates 12 times and gets the respectives total days in each month
	// and stores into vector
	for (int i = 0; i < 12; i++) {
		DAYS_IN_MONTH_VEC.push_back(DaysPerMonth(i, YEAR));

		//std::cout << DAYS_IN_MONTH_VEC.at(i) << std::endl;

		PrintOneMonth(i, YEAR, START_DAY, DAYS_IN_MONTH_VEC.at(i));
	}
}