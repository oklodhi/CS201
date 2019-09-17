// Omer Khan
// mokddp@mail.umkc.edu
// CS201L lab 13
// April 25

#include <iostream>
#include <string>
using namespace std;

// this function finds the factorial value for the number passed in
double factorial_r(double value) {
	if (value == 0) {
		return 1;
	}
	else {
		return value * factorial_r(value - 1);
	}
}

// this function finds the next fibonnaci value in the sequence for the number passed in
int fibonnaci_r(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return (fibonnaci_r(n - 1) + fibonnaci_r(n - 2));
	}
}

// this function checks whether the number passed is a prime or not
bool is_prime_r(int value, int n) {
	if (value <= 2) {
		if (n == 2) {
			return true;
		}
		else {
			return false;
		}
	}
	if (value % n == 0) {
		return false;
	}
	if (n * n > value) {
		return true;
	}

	return is_prime_r(value, n + 1);
}

// this function finds the sum of a int arr
int sum_r(int list[], int list_size) {

	if (list_size == 0) {
		return 0;
	}
	else {
		return (list[list_size - 1] + sum_r(list, list_size - 1));
	}
}

// this function prints the arr in reverse order
void output_reverse_list_r(int list[], int list_size) {
	if (list_size == 0) {
		return;
	}

	cout << list[list_size - 1] << " ";
	output_reverse_list_r(list, list_size - 1); 
}

int main() {
	// temporary values
	int num_int;
	double num_double; 
	int num_arr[5];

	cout << "Enter a double for FACTORIAL >> "; 
	cin >> num_double;

	cout << "\nFactorial(" << num_double << ") = " << factorial_r(num_double) << endl;

	cout << "\nEnter an int for FIBONNACI >> ";
	cin >> num_int;

	cout << "\nFibonnaci(" << num_int << ") = " << fibonnaci_r(num_int) << endl;

	cout << "\nEnter an int for PRIME >> ";
	cin >> num_int;

	if (is_prime_r(num_int, 2)) {
		cout << num_int << " is a PRIME NUMBER!" << endl;
	}
	else {
		cout << num_int << " is not a PRIME NUMBER!" << endl;
	}

	cout << "\nEnter 5 int for array sum: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter int #" << i << " for SUM >> ";
		cin >> num_arr[i]; 
	}

	cout << "\nSum of all values is = " << sum_r(num_arr, 5) << endl;
	cout << "\nThe list output in reverse is = ";
	output_reverse_list_r(num_arr, 5);

	cout << endl;


	return 0;
}