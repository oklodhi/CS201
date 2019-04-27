#include "func.h"

// asks for user input on goals and turns
void starting_question(int& tokens_goal, int& num_turns) {
	
	// temp variable to check if cin input is valid
	bool valid_input = false;

	// makes sure cin input is INT only
	do {
		std::cout << "Enter the number of tokens you want to reach: " << std::endl;
		std::cin >> tokens_goal;

		if (!(valid_input = std::cin.good())) {
			std::cout << "\nInvalid input! Try again... \n"; 
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input);

	// reset input check flag
	valid_input = false;

	// makes sure cin input is INT only
	do {
		std::cout << "What is the number of turns: " << std::endl;
		std::cin >> num_turns;

		if (!(valid_input = std::cin.good())) {
			std::cout << "\nInvalid input! Try again... \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input);

	std::cout << "\nSearching for a solution within " << num_turns << " turn(s) ..." << std::endl;
}

// main program logic that handles token manipulation. RECURSION LOGIC
void recursion(int& my_tokens, const int tokens_goal, int& num_turns) {
	// token increament value
	const int TOKEN_INCR = 25;
	// boolean flag that checks token equality
	bool var = false;

	// as long as i have turns left and i havent reached the goal
	while (num_turns > 0 && my_tokens != tokens_goal) {

		// always divide tokens by 2 if possible
		if (my_tokens % 2 == 0) {
			my_tokens = my_tokens / 2;

			std::cout << "Reducing by half, you get " << my_tokens << " tokens." << std::endl;
		}
		else { // otherwise increment
			my_tokens = my_tokens + TOKEN_INCR;

			std::cout << "Adding " << TOKEN_INCR << " , you get " << my_tokens << " tokens." << std::endl;
		}

		// take a turn away each time
		num_turns--;
	}

	// at this point, i have no turns left. But are my tokens == goal tokens?
	if (my_tokens == tokens_goal) {
		var = true;
	}

	// print whether a solution was found or not
	solution_found_not_found(num_turns, var);
}

// prints whether solution was found within allotted turns or not
void solution_found_not_found(int num_turns, bool var) {
	if (var) {
		std::cout << "\nSolution was found with " << num_turns << " turn(s) remaining." << std::endl;
	}
	else {
		std::cout << "\nSorry solution wasn't found within allotted turns." << std::endl;
	}
}

// determines whether user wants to play again
bool play_again() {
	char choice;

	while (true) {
		std::cout << "Would you like to play again? [Y/N]" << std::endl;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		choice = toupper(choice);

		switch (choice) {
		case 'Y':
			return true;
		case 'N':
			std::cout << "Thanks for playing!";
			return false;
		default:
			std::cout << "\nWrong input" << std::endl;
		}
	}
}