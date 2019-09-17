#include "func.h"

// opens and read the input files
void open_and_read_file(vector<Employee> &EmpVec, string filename) {
	string emp_action;
	int emp_id;
	string emp_first, emp_last;
	double emp_rate;

	// input stream object
	ifstream fin;

	// try to open file 
	try {
		fin.open(filename);

		// if bad things happen then throw filename
		if (!fin) {
			throw filename;
		}
	}
	catch (std::string filename) {
		// catch filename
		cout << "ERROR: " << filename << endl;
	}

	//cout << "HERE1" << endl;

	// read one line at a time, and store it
	while (!(fin.eof())) {

		// reads the first action keyword
		// and performs necessary steps based on that
		fin >> emp_action; 

		//cout << emp_action << endl;

		if (emp_action == "NEW") {
			// if NEW then pushback the employee into the vector

			fin >> emp_id >> emp_first >> emp_last;

			string emp_name = emp_first + emp_last;

			EmpVec.push_back(Employee(emp_id, (emp_name)));
		}
		else if (emp_action == "RAISE") {
			// if RAISE then give the employee a raise

			fin >> emp_id >> emp_rate;

			for (int i = 0; i < EmpVec.size(); i++) {
				if (EmpVec[i].getEmployeeID() == emp_id) {
					EmpVec[i].giveRaise(emp_rate);
				}
			}
		}
		else if (emp_action == "PAY") {
			// if PAY then give the employee pay

			for (int i = 0; i < EmpVec.size(); i++) {
				EmpVec[i].pay();
			}
		}
		else if (emp_action == "FIRE") {
			// if FIRE then give the employee fire

			fin >> emp_id;

			for (int i = 0; i < EmpVec.size(); i++) {
				if (EmpVec[i].getEmployeeID() == emp_id) {
					EmpVec[i].fire();
				}
			}
		}
	}
}

// opens and writes to output files
void open_and_write_file(vector<Employee> &EmpVec, string filename) {
	// output stream object
	ofstream fout; 

	// print out checked out books to txt
	try {
		fout.open(filename);

		// if something bad happens then throw -1
		if (!fout) {
			throw - 1;
		}
	}
	catch (int a) {
		// catch all the bad stuff here
		std::cout << "ERROR: " << a << std::endl;
	}

	for (int i = 0; i < EmpVec.size(); i++) {
		if (EmpVec[i].isEmployed() == true) {
			fout << EmpVec[i].getName() << ", ID Number " << EmpVec[i].getEmployeeID() << ":" << endl;

			fout << "Current pay rate: $" << EmpVec[i].getPayRate() << endl;

			fout << "Pay earned to date: $" << EmpVec[i].getBalance() << endl << endl;
		}
		else if (EmpVec[i].isEmployed() == false) {
			fout << EmpVec[i].getName() << ", ID Number " << EmpVec[i].getEmployeeID() << ":" << endl;

			fout << "Not employed with the company/" << endl;

			fout << "Pay earned to date: $" << EmpVec[i].getBalance() << endl << endl;
		}
	}

}

