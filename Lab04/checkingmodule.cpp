#include "checkingmodule.h"

void deposit(float &account, float amount) {
	account = account + amount;
}

char MainMenu() {
	char output;

	std::cout << "\nEnter a valid option \n(D)eposit, (W)ithdraw, (L)oan or (Q)uit >> ";
	std::cin >> output;
	output = toupper(output);

	switch (output) {
	case 'D':
		return output;
		break;
	case 'W':
		return output;
		break;
	case 'L':
		return output;
		break;
	case 'Q':
		return output;
		break;
	default:
		do {
			std::cout << "Try again >> ";
			std::cin >> output;
			output = toupper(output);
		} while (output != 'D' || output != 'W' || output != 'L' || output != 'Q');
	}
}

float GetValue(std::string str) {
	float amt;
	
	do {
		std::cout << str;
		std::cin >> amt;
		std::cout << std::endl;
	} while (amt < 0); 

	return amt;
}

float GetValue(std::string str, float upper) {
	float amt = 0;

	do {
		if (amt > upper) {
			std::cout << "\nNot enough funds..." << std::endl;
		}
		std::cout << str;
		std::cin >> amt;
	} while (!(amt >= 0 && amt <= upper));

	return amt;
}

float GetInterestRate(int crdSc) {
	float interest = 0; 
	
	if (crdSc <= 500) {
		interest = .05; 
	}
	else if (crdSc > 500 && crdSc <= 700) {
		interest = 0.3; 
	}
	else if (crdSc > 700) {
		interest = .01;
	}

	return interest; 
}

void Withdraw(float &account, float amount) {
	account = account - amount; 
	std::cout << std::endl;
}

int GetLoanMonths() {
	int loan_Months; 

	int valid_months[] = { 12, 24, 36, 60 };

	do {
		std::cout << "Enter loan months (12, 24, 36, 60) >> ";
		std::cin >> loan_Months;

		for (int i = 0; i < 4; i++) {
			if (loan_Months == valid_months[i]) {
				return loan_Months;
			}
		}
	} while (true);

}

int GetCreditRating() {
	int credit_Rating = 0; 

	do {
		std::cout << "\nEnter a valid credit rating (300 - 850) >> ";
		std::cin >> credit_Rating;
	} while (!(credit_Rating >= 300 && credit_Rating <= 850));

	return credit_Rating;
}

float CalculateLoanAmount(float principal, float rate, int months) {
	float amount = std::pow((1 + (rate / 12)), (months / 12)) * principal;

	std::cout << "Months ... " << months << std::endl;
	std::cout << "Interest rate... " << rate << std::endl;
	std::cout << "Principal amount... $" << principal << std::endl;
	
	return amount;
}

void OutputAccount(float amount) {
	std::cout << amount;
}