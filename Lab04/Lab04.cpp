// Omer Khan
// mokddp@mail.umkc.edu
// Feb 14
// CS201L Lab 04

#include <iostream>
#include <string>
#include <cmath>
#include "checkingmodule.h"


int main() {
	float accountValue = 0.0f, interestRate;
	char userChoice;
	int loanMonths, creditRating;
	bool quit = false;
	std::string str = "\nEnter an amount >> $";

	//deposit(accountValue, 100);

	//std::cout << accountValue; 

	while (quit != true) {

		std::cout << "Account summary: $" << accountValue << std::endl;

		userChoice = MainMenu();

		switch (userChoice) {
		case 'D':
			deposit(accountValue, GetValue(str));
			break;
		case 'W':
			std::cout << "\nMoney in account: $" << accountValue << std::endl;
			Withdraw(accountValue, GetValue(str, accountValue));
			break;
		case 'L':
			std::cout << "\nLets calculate your loans" << std::endl;

			loanMonths = GetLoanMonths();
			creditRating = GetCreditRating();
			interestRate = GetInterestRate(creditRating);

			std::cout << "\nYour loan amount is... $" << CalculateLoanAmount(GetValue(str), interestRate, loanMonths) << std::endl << std::endl;
			break;
		case 'Q':
			quit = true;
			break;
		}
	}

	return 0;
}