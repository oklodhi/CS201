#include "func.h"

// 1 month's calendar printed to output stream, with day headers
void PrintOneMonth(int MonthNumber, int Year, int StartDayNumber, const int DaysInMonth) {
	std::cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat " << std::endl;

}

// Returns days in that month & year, allowing for leap year
int DaysPerMonth(int MonthNumber, int Year) {

	if (MonthNumber == 0) { // january 
		return (31);
	}
	else if (MonthNumber == 1) {// february 

		// if leap year then february has 29 days
		if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) {
			return (29);
		}
		else { // no leap year, then 28 days
			return (28);
		}
	}
	else if (MonthNumber == 2) { // march 
		return (31);
	}
	else if (MonthNumber == 3) { // april
		return (30);
	}
	else if (MonthNumber == 4) { // may
		return (31);
	}
	else if (MonthNumber == 5) { // june
		return (30);
	}
	else if (MonthNumber == 6) { // july
		return (31);
	}
	else if (MonthNumber == 7) { // august
		return (31);
	}
	else if (MonthNumber == 8) { // september
		return (30);
	}
	else if (MonthNumber == 9) { // october
		return (31);
	}
	else if (MonthNumber == 10) { // november
		return (30);
	}
	else { // december
		return (31);
	}

}

// Returns day of the week as int (Sun = 0, Mon = 1, etc)
int GetStartDayNumber() {
	std::string day;

	// do-while handles any bad input from the user. If good input, then return value
	do {
		std::cout << "What day of the week does Jan 1 fall on this year? >>> ";
		std::cin >> day;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// transform is a way to convert the entire string to lower_case characters
		std::transform(day.begin(), day.end(), day.begin(), ::tolower);
	} while (!(day == "sunday" || day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday"));

	// return the day-equivalent int
	if (day == "sunday") {
		return 0;
	}
	else if (day == "monday") {
		return 1;
	}
	else if (day == "tuesday") {
		return 2;
	}
	else if (day == "wednesday") {
		return 3;
	}
	else if (day == "thursday") {
		return 4;
	}
	else if (day == "friday") {
		return 5;
	}
	else if (day == "saturday") {
		return 6;
	}
}

// Returns a 4-digit number that is the year. Valid number between 1000 - 9999
int GetYear() {
	int year;

	do {
		std::cout << "Enter a 4-digit value for year (1000 -> 9999) >>> ";
		std::cin >> year;

		// if cin gets a bad input (ex: string, char, etc)
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (!(year >= 1000 && year <= 9999)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			return year;
		}
	} while (true);
}
