// Header file includes function declarations
#pragma once

// include necessary libraries
#include <iostream> 
#include <string>
#include <fstream>

// Main menu loop and switch statements
void mainMenu();

// Opens, reads, closes file
void fileHandler(std::string filename, std::ifstream& file, int id[], std::string first[], std::string last[], double savings_Account[], double checking_Account[], int size);

// Option 1 function
void printCustomersData(const int id[], const std::string first[], const std::string last[], const double savings_Account[], const double checking_Account[], int size);

// Option 2 function
void printNames(const int id[], const std::string first[], const std::string last[], int size);

// Option 3 function
void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size);

