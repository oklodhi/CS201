// Omer Khan
// mokddp@mail.umkc.edu
// April 18
// CS201L Lab 12

#include "func.h"
#include "Employee.h"

using namespace std;

int main() {
	const string INPUT_FILE = "input.txt";
	const string OUTPUT_FILE = "output.txt";

	vector<Employee> myVec;

	open_and_read_file(myVec, INPUT_FILE);

	/*for (int i = 0; i < myVec.size(); i++){
		cout << myVec[i].getName() << " " << myVec[i].getEmployeeID() << endl;
	}*/


	open_and_write_file(myVec, OUTPUT_FILE);
}