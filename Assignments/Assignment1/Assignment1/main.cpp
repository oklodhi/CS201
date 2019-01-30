// Omer Khan, CS201-0002 7pm Mon/Wed
// Assignment #1

// include libraries
#include <iostream>
#include <string>

// variable initialization
int userChoice;
bool quit = false;
char inputAnotherTrans; 
double pointsAssignments, pointsExam1, pointsExam2, pointsFinalExam, pointsTotalGrade; 

int main() {
	// as long as quit != true then keep looping menu
	while (quit != true && (userChoice != 1 || userChoice != 2 || userChoice != 3)) {
		std::cout << "Welcome to the Grade system" << std::endl << "How can we help you today?" << std::endl;
		std::cout << "1. Grade Scale." << std::endl << "2. Calculate your total % and Grade." << std::endl << "3. Exit" << std::endl;
		std::cout << "Enter your choice: " << std::endl; 

		// input userChoice for menu
		// switch case based on userChoice
		std::cin >> userChoice;
		
		switch (userChoice) {
		case 1:
			// display grading scale menu
			std::cout << "A: 90-100 \nB: 80-89 \nC: 69-79 \nD: 60-68 \nF: 0-59" << std::endl;
			
			// loop again or quit based on input
			std::cout << "Do you want to have another transaction?" << std::endl; 
			std::cin >> inputAnotherTrans;

			// check if lowercase == uppercase 
			if (toupper(inputAnotherTrans) == 'Y') {
				main(); 
			}
			else if (toupper(inputAnotherTrans) == 'N') {
				quit = true;
			}
			else {
				std::cin >> inputAnotherTrans;
			}
			break; 
		case 2:
			// diplay grade calculation menu
			std::cout << "Please enter your points in assignments, Exam1, Exam2, and Final Exam" << std::endl;
			std::cout << "Assignments out of 80:" << std::endl;
			std::cin >> pointsAssignments;
			std::cout << "Exam1 out of 80:" << std::endl;
			std::cin >> pointsExam2;
			std::cout << "Exam2 out of 80:" << std::endl;
			std::cin >> pointsExam1;
			std::cout << "Final Exam out of 100:" << std::endl;
			std::cin >> pointsFinalExam;
			 
			// calculate total grade based on points recieved 
			pointsTotalGrade = ((pointsAssignments + pointsExam1 + pointsExam2 + pointsFinalExam) / (80 + 80 + 80 + 100)) * 100; 

			// output total grade as a letter grade
			std::cout << "Your total grade percentage is " + std::to_string(pointsTotalGrade) << std::endl << "Depending on your Grade scale, your Grade is" << std::endl;

			if (pointsTotalGrade >= 90) {
				std::cout << "A" << std::endl; 
			} 
			else if (pointsTotalGrade >= 80) {
				std::cout << "B" << std::endl;
			}
			else if (pointsTotalGrade >= 69) {
				std::cout << "C" << std::endl;
			}
			else if (pointsTotalGrade >= 60) {
				std::cout << "D" << std::endl;
			}
			else {
				std::cout << "F" << std::endl; 
			}

			// loop or quit again based on input
			std::cout << "Do you want to have another transaction?" << std::endl;
			std::cin >> inputAnotherTrans;

			// check lowercase == uppercase
			if (toupper(inputAnotherTrans) == 'Y') {
				main();
			}
			else if (toupper(inputAnotherTrans) == 'N') {
				quit = true;
			}
			else {
				std::cin >> inputAnotherTrans;
			}
			break;
		case 3:
			// user chose to exit so set quit=true to exit loop
			quit = true;
			break;
		default:
			// keep looping menu if input is not 1, 2, or 3
			main();
		}
	}
	
	std::cout << std::endl; 
	return 0; 
}