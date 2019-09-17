// Omer Khan, C201L Thr 5:30
// Lab02 Jan 31

#include <iostream> 
#include <string>

int main() {
	/*string name = "John"; 
	float homeworkScore; 
	homeworkScore = 89.2; 

	std::cout << "Hello, " << name << std::endl; 
	std::cout << "	Homework : " << homeworkScore << std::endl; */

	std::string name; 
	int homeworkScore, testScore, quizScore, attendanceScore, totalScore; 

	std::cout << "Please enter the students name >>> "; 
	std::cin >> name; 
	std::cout << "\nPlease enter the homework score >>> "; 
	std::cin >> homeworkScore; 
	std::cout << "\nPlease enter the test score >>> ";
	std::cin >> testScore;
	std::cout << "\nPlease enter the quiz score >>> ";
	std::cin >> quizScore;
	std::cout << "\nPlease enter the attendance score >>> ";
	std::cin >> attendanceScore;

	totalScore = (homeworkScore * .20) + (testScore * .5) + (quizScore * .20) + (attendanceScore * .10); 

	std::cout << "\nGrades for " << name << std::endl; 
	std::cout << "	Homework \t : " + std::to_string(homeworkScore) << std::endl; 
	std::cout << "	Test \t\t : " + std::to_string(testScore) << std::endl;
	std::cout << "	Quiz \t\t : " + std::to_string(quizScore) << std::endl;
	std::cout << "	Attendance \t : " + std::to_string(attendanceScore) << std::endl;

	for (int i = 0; i < 40; i++) {
		std::cout << "*"; 
	}
	std::cout << std::endl;

	std::cout << "	Total Score \t : " + std::to_string(totalScore) << std::endl; 

	return 0; 
}