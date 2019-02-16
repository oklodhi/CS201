// Header file includes function declarations
#pragma once

// include necessary libraries
#include <iostream> 
#include <string>
#include <fstream>

const int arrSize = 10; 
static bool quit = false;

// Main menu loop and switch statements
void mainMenu();

// Opens file
void openFile();

// Read any files that are open
void readFile();

// Close any files that are opened
void closeFile();

// Option 1 function
void printCustomersData(const int id[], const std::string first[], const std::string last[], const double savings_Account[], const double checking_Account[], int size);

// Option 2 function
void printNames(const int id[], const std::string first[], const std::string last[], int size);

// Option 3 function
void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size);

