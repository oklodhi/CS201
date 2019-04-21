#pragma once

#include <iostream>

// asks for user input on goals and turns
void starting_question(int& tokens_goal, int& num_turns);

// main program logic that handles token manipulation. RECURSION LOGIC
void recursion(int& my_tokens, const int tokens_goal, int& num_turns);

// prints whether solution was found within allotted turns or not
void solution_found_not_found(int num_turns, bool var);

// determines whether user wants to play again
bool play_again();