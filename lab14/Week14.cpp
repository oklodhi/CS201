// Omer Khan
// CS201L 
// mokddp@mail.umkc.edu
// May 2, 2019

#include <fstream>
#include <iostream>
#include <string>

using namespace std; 

// swaps the position of two values in array
template <class T>
void mySwap(T arr[], int pos1, int pos2) {
	T temp = arr[pos1]; 
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

// searches for MIN value in array
template <class T>
T myMin(T arr[]) {
	T min = arr[0];
	for (int i = 0; i < 100; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

// searches for MAX value in array
template <class T>
T myMax(T arr[]) {
	T max = arr[0];
	for (int i = 0; i < 100; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

// searches if TARGET is in array
template <class T>
int mySearch(T arr[], T target) {
	for (int i = 0; i < 100; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	const string DOUBLE_FILE = "doubles.txt";
	const string INTEGER_FILE = "integers.txt";
	const string STRING_FILE = "strings.txt";

	int arrInt[100];
	double arrDouble[100];
	string arrString[100];

	ifstream input;

	// *** INTEGER FILE READING AND STORING ***
	input.open(INTEGER_FILE);

	int tempInt; 
	int k = 0;

	while (!input.eof()) {
		input >> tempInt;
		arrInt[k] = tempInt;
		k++;
	}

	input.close();

	// *** DOUBLE FILE READING AND STORING ***
	input.open(DOUBLE_FILE);

	double tempDouble;
	int d = 0;

	while (!input.eof()) {
		input >> tempDouble;
		arrDouble[d] = tempDouble;
		d++;
	}

	input.close();

	// *** STRING FILE READING AND STORING ***
	input.open(STRING_FILE);

	string tempString;
	int s = 0;

	while (!input.eof()) {
		input >> tempString;
		arrString[s] = tempString;
		s++;
	}

	input.close();

	// *** OUTPUT ***
	ofstream output;
	output.open("output.txt");

	int int1 = 1;
	int int2 = 5;
	double dub1 = 4.62557;
	double dub2 = 1.23456;
	string string1 = "Shoes";
	string string2 = "Pumpkin"; 

	// integer output
	output << "INTEGERS: " << endl;;
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10]" << arrInt[10] << " [20]" << arrInt[20] << endl;
	mySwap(arrInt, 10, 20);
	output << "After: [10]" << arrInt[10] << " [20]" << arrInt[20] << endl;
	output << "Minimum: " << myMin(arrInt) << endl;
	output << "Maximum: " << myMax(arrInt) << endl;
	output << "The number 1 is at position: " << mySearch(arrInt, int1) << endl;
	output << "The number 5 is at position: " << mySearch(arrInt, int2) << endl;

	// double output
	output << "\nDOUBLES: " << endl;;
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10]" << arrDouble[10] << " [20]" << arrDouble[20] << endl;
	mySwap(arrDouble, 10, 20);
	output << "After: [10]" << arrDouble[10] << " [20]" << arrDouble[20] << endl;
	output << "Minimum: " << myMin(arrDouble) << endl;
	output << "Maximum: " << myMax(arrDouble) << endl;
	output << "The number 4.62557 is at position: " << mySearch(arrDouble, dub1) << endl;
	output << "The number 1.23456 is at position: " << mySearch(arrDouble, dub2) << endl;

	// string output
	output << "\nSTRING: " << endl;;
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10]" << arrString[10] << " [20]" << arrString[20] << endl;
	mySwap(arrString, 10, 20);
	output << "After: [10]" << arrString[10] << " [20]" << arrString[20] << endl;
	output << "Minimum: " << myMin(arrString) << endl;
	output << "Maximum: " << myMax(arrString) << endl;
	output << "The word shoes is at position: " << mySearch(arrString, string1) << endl;
	output << "The word pumpkin is at position: " << mySearch(arrString, string2) << endl;
}