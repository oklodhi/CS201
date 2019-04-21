// Omer Khan
// Assignment 6
// CS201R Gharibi
// April 21, 2018

#include <iostream>

#include "func.h"

int main() {
	// while user wants to play again, keep looping main

	do {
		// tokens that user has
		int my_tokens = 13; 
		// variables to keep track of goal and turns
		int tokens_goal, num_turns; 

		// asks for user input on goals and turns
		starting_question(tokens_goal, num_turns);

		// program logic
		recursion(my_tokens, tokens_goal, num_turns);

	} while (play_again());

	return 0; 
}