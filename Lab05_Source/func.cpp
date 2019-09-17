// Incluce header files
#include "func.h"

// Initialize variables
bool quit = false;
static int rows = 0, cols = 0;
std::vector<std::vector<int>> matrix1;
std::vector<std::vector<int>> matrix2;
std::string err_size = "\nERROR: Can't be processed. Check matrix sizes!";

// Main menu loop
void mainMenu() {
	int choice; 
	
	while (quit == false) {
		std::cout << "\n1. Edit matrix 1" << std::endl;
		std::cout << "2. Edit matrix 2" << std::endl;
		std::cout << "3. Show both matrix" << std::endl;
		std::cout << "4. Add matrix" << std::endl;
		std::cout << "5. Multiply matrix" << std::endl;
		std::cout << "6. Quit >> " << std::endl;

		std::cout << "\nWhat do you want to do? >> ";
		std::cin >> choice;
		choice = toupper(choice);

		switch (choice) {
		case 1:
			system("CLS");
			editMatrix(matrix1, rows, cols);
			break;
		case 2:
			system("CLS");
			editMatrix(matrix2, rows, cols);
			break;
		case 3:
			system("CLS");
			std::cout << "\nMatrix 1:" << std::endl;
			showMatrix(matrix1);

			std::cout << "\nMatrix 2:" << std::endl;
			showMatrix(matrix2);

			std::cout << std::endl;
			break;
		case 4:
			system("CLS");
			addMatrix(matrix1, matrix2);
			break;
		case 5:
			system("CLS");
			multiplyMatrix(matrix1, matrix2);
			break;
		case 6:
			quit = true;
			break;
		}
	}
}

// Part 4a: Lets user edit matrix rows, columns, and values
void editMatrix(std::vector<std::vector<int>> &matrix, int rows, int cols) {
	std::cout << "\nEnter the number of ROWS in this matrix >> ";
	std::cin >> rows;

	std::cout << "Enter the number of COLUMNS in this matrix >> ";
	std::cin >> cols;

	matrix.resize(rows);
	for (auto &it : matrix) {
		it.resize(cols);
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << "Enter VALUE at (" << i << ", " << j << ") >> ";
			std::cin >> matrix[i][j];
		}
	}
}

// Part 4a: Shows matrix back to user
void showMatrix(std::vector<std::vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Part 4c: matrix add
void addMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2) {
	if (matrix1.size() == matrix2.size() && matrix1[0].size() == matrix2[0].size()) {
		std::vector<std::vector<int> > result_matrix;

		result_matrix.resize(matrix1.size());
		for (auto &it : result_matrix) {
			it.resize(matrix2[0].size());
		}

		std::cout << "\nHere is the result ADD matrix:" << std::endl;

		for (int i = 0; i < result_matrix.size(); i++) {
			for (int j = 0; j < result_matrix[i].size(); j++) {
				result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];

				std::cout << result_matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else {
		system("CLS");
		std::cout << err_size << std::endl;
	}
}

// Part 4d: matrix multiply ---- NOT WORKING
/* Logically, this should work... But it doesnt. I give up*/
void multiplyMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2) {

	// Matrix multiplication for AxB * BxC
	
	// checks if cols of matrix1 is == rows matrix 2
	// if B == B
	if (matrix1[0].size() == matrix2.size()) {

		std::vector<std::vector<int> > result_matrix;

		// resizes result_matrix to rows = rows matrix1, 
		// cols = cols matrix2 
		// size AxC
		result_matrix.resize(matrix1.size());
		for (auto &it : result_matrix) {
			it.resize(matrix2[0].size());
		}

		std::cout << "\nHere is the result MULTIPLY matrix:" << std::endl;
		
		// iterates over matrix1 rows, A
		for (int i = 0; i < matrix1.size(); i++) {
			// iterates over matrix2 cols, C
			for (int j = 0; j < matrix2[0].size(); j++) {
				// iterates over matrix1 cols OR matrix2 rows, B
				for (int p = 0; p < matrix1[0].size(); i++) {
					// result_matrix at i,j = AxB * BxC
					result_matrix[i][j] += matrix1[i][p] * matrix2[p][j];
				}
				std::cout << result_matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else {
		system("CLS");
		std::cout << err_size << std::endl;
	}
}