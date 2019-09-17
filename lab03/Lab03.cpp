#include <iostream>
#include <string>
#include <iomanip>

int main() {
	int dayNum = 1,
		count_Children = 0, total_Children = 0,
		count_Adults = 0, total_Adults = 0,
		count_Seniors = 0, total_Seniors = 0,
		count_VIP = 0, total_VIP = 0;
	const double cost_Children = 10.95, cost_Adults = 19.99, cost_Seniors = 18.99, cost_VIP = 7.99;
	double revenue_Children = 0, revenue_Adults = 0, revenue_Seniors = 0, revenue_VIP = 0, revenue_Total = 0, revenue_Day = 0;
	char menuSelection;
	// bool quit = false; 

	std::cout.precision(2);

	std::cout << "Welcome to Fun Park Menu System !!" << std::endl;
	std::cout << "Starting day" + std::to_string(dayNum) << std::endl;

	while (true) {
		std::cout << "\nEnter (C)hild, (A)dult, (S)enior, (V)IP, or (Q)uit >> ";

		std::cin >> menuSelection;
		menuSelection = toupper(menuSelection);

		switch (menuSelection) {
		case 'C':
			std::cout << "\nHow many Children? ";
			std::cin >> count_Children;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else if (count_Children >= 0) {
				total_Children = total_Children + count_Children;
			}
			else {
				std::cout << "invalid entry \n\n";
			}
			break;
		case 'A':
			std::cout << "\nHow many Adults? ";
			std::cin >> count_Adults;
			total_Adults = total_Adults + count_Adults;
			break;
		case 'S':
			std::cout << "\nHow many Seniors? ";
			std::cin >> count_Seniors;
			total_Seniors = total_Seniors + count_Seniors;
			break;
		case 'V':
			std::cout << "\nHow many VIPs? ";
			std::cin >> count_VIP;
			total_VIP = total_VIP + count_VIP;
			break;
		case 'Q':
			revenue_Children = cost_Children * total_Children;
			revenue_Adults = cost_Adults * total_Adults;
			revenue_Seniors = cost_Seniors * total_Seniors;
			revenue_VIP = cost_VIP * total_VIP;

			std::cout << "\nDay " + std::to_string(dayNum) << std::endl;

			std::cout << "\tChild " + std::to_string(total_Children) + " @ 10.95 = " << std::fixed << revenue_Children << std::endl;
			std::cout << "\tAdult " + std::to_string(total_Adults) + " @ 19.99 = " << std::fixed << revenue_Adults << std::endl;
			std::cout << "\tSenior " + std::to_string(total_Seniors) + " @ 18.99 = " << std::fixed << revenue_Seniors << std::endl;
			std::cout << "\tVIP " + std::to_string(total_VIP) + " @ 7.99 = " << std::fixed << revenue_VIP << std::endl << std::endl;

			revenue_Day = revenue_Adults + revenue_Children + revenue_Seniors + revenue_VIP;

			std::cout << "\tTotal = " << std::fixed << revenue_Day << std::endl << std::endl;

			revenue_Total = revenue_Total + revenue_Day;

			std::cout << "The total for all days is " << std::fixed << revenue_Total << std::endl << std::endl;

			dayNum++;
			std::cout << "Starting day " + std::to_string(dayNum);
			break;
		default:
			std::cin >> menuSelection;
			menuSelection = toupper(menuSelection);
		}
	}
	return 0;
}