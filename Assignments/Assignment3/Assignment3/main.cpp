// Omer Khan
// CS201R	M/W 7pm
// Assignment 3

#include "func.h"

int main() {
	const int YEAR = GetYear(); 
	const int START_DAY = GetStartDayNumber();
	std::vector<int> DAYS_IN_MONTH_VEC; 

	// calendar heading
	std::cout << "\n          CALENDAR - " << YEAR << std::endl;

	// iterates 12 times and gets the respectives total days in each month
	// and stores into vector
	for (int i = 0; i < 12; i++) {
		DAYS_IN_MONTH_VEC.push_back(DaysPerMonth(i, YEAR));
	}

	// Prints the calendar, one month at a time
	PrintOneMonth(YEAR, START_DAY, DAYS_IN_MONTH_VEC);
}