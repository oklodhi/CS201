#include "func.h"

void PrintOneMonth(int MonthNumber, int Year, int StartDayNumber) {
	std::cout << "Month" << std::endl;
	std::cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat " << std::endl;
}

int DaysPerMonth(int MonthNumber, int Year) {
	return -1;
}

int GetStartDayNumber() {
	std::string day; 

	do {
		std::cout << "What day of the week does Jan 1 fall on this year? >>> ";
		std::cin >> day;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		

		std::cout << day << std::endl << std::endl;

		std::transform(day.begin(), day.end(), day.begin(), ::tolower);
	} while (!(day == "sunday" || day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday"));
	
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

int GetYear() {
	int year;

	do {
		std::cout << "Enter a 4-digit value for year (1000 -> 9999) >>> ";
		std::cin >> year;
	} while (!(year >= 1000 && year <= 9999));

	return year;
}
