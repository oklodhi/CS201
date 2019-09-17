#pragma once

#include <iostream>
#include <vector>
#include <string>

// Main menu loop
void mainMenu(); 

// Part 4a: Lets user edit matrix rows, columns, and values
void editMatrix(std::vector<std::vector<int>> &matrix, int rows, int cols);

// Part 4a: Shows matrix back to user
void showMatrix(std::vector<std::vector<int>> matrix);

// Part 4c: matrix add
void addMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2);

// Part 4d: matrix multiply ---- NOT WORKING
void multiplyMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2);