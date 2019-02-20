// C++ is an object oriented programming language
    // Encapsulation, Polymorphism, Inheritance
	// short circuit programming language: boolean checking with logical operators

// Every program starts with
    // #include <iostream>
    // using namespace std;

// New C++11 types
    auto x = expression;
    decltype(x*3.5) y;

// Data types - initialized in the RAM
    int _int = 10; // 2 or 4 bytes
    long _long = 9999999999;
    float _float = 10.983;
    double _double = 123.45678;
    char _char = a;
    bool _bool = true;

// Escape Characters
    // \n - new line
    // \t - tab space
    // \a - alert
    // \\ - 1 backslash
    // \' - single quote
    // \" - double quote

// Raw String literals
    string s = R"(\t\\t\n)";
    // print: \t\\t\n

// Constants
    // value cannot be changed

// Type casting
    // Converting one type to another type

// Short Hand operator
    // ++. --

// Function Overloading (pre and post increment / decrement)
    var++; // uses value then adds 1
    ++var;  // adds value then add 1

// Input and output
    // cin, cout, cerr;
    // <iostream>

// Logical Operators
	// and &&
	// or ||
	// not equal != 
	// is equal == different than single = assignment


	// Comparison Operator: greater than, equal to etc. > < >= <=
	// logical operators have lowest priority

// Strong enums and enum classes
	// creating new class means creating new type
	// aka enums create a new type
	enum class Days = { Sun, Mon, Tues, Wed, Thur, Fri, Sat };
	Days d = Days::Tue; 

// if-else statements
	hrs = 40
	if (hrs > 40) { // block or compound statement
		return true; // single statement 
	}
	else {
		return false; // semi-colon ; is called a statement
	}

// Nested loops / statements 
	// Having multiple statements and loops inside one another in a "nest"

// Switch statements 
	int 1_or_2; 
	cin >> 1_or_2; 

	switch (1_or_2)
	{
	case 1:
		cout << "You picked 1";
		break;
	case 2:
		cout << "You picked 2";
		break;
	default:
		cout << "Not a valid number";
	}

// While loop
	int i = 0; 
	while (/* boolean statement */ i < 10) {
		cout << i << endl; 

		//increment 
		i++; 
	}

// For loop
	// for (initialization statement; boolean statement; controlling statement)
	for (int i = 0; i < 10; i++) {

	}

// Do-While loop 
	do {

	} while (/* boolean expression */); 

// Continue vs Break
	// Break: leave the current loop at the point of break
	// Continue: leaves the current iteration of the loop

// Reading and printing from file
	// #include <fstream>
	// #include <string>

	int i = 0, id; 
	string fName, lName; 

	ifstream f; 
	ofstream fout("results.txt");
	
	f.open("data.txt");

	while (f.eof()) { // .eof() - end of file. Predefined C++ function 
		f >> fName >> lName >> id;
		fout << fName << lName << id;
	}

// Functions
	// A set of reusable code
	// Procedures, subprograms, methods, functions

	// I-P-O
	// input , process , output 

	// void: functions that dont output anything
	// data type: the type of the return statement

	// Parameter goes in the function definition\
	// Arguements are what we pass into the function

	//default parameter: 
	void func(int a, int b = 5) {
		a + b; 
	} // B has been given a default value, but no default on A

// Arrays
	// Arrays are a collection of data of same data type
	// Array values / elements
	// Array indexing starting from 0
	// array[]

	// & referrence / address of operator 
	// * value / pointer operator 

	// Loops are used to do any iteration through an array

// Multidimentional arrays
	// array[][]

// Sorting Algorithms and time complexity
	// Big O Notation: the way we talk about how long it takes an algorithm to run
	// worst - O(n)
	// best - omega(1)
	// avg - theta(n)

	// multidimentional array complexity: n*m*k where n, m, and k are array dimensions

	// Binary search: only works in a sorted list, starts from the middle
	// IMPORTANT 
	// log (n)
	const int size = 3;
	int arr1[size] = { 3, 4, 5 }; 
	int target = 7; 

	binary_search(arr1, 0, size, target, arr[size/2]);

	binary_search(int arr[], int left, int right, int target, int mid) {
		while (left <= right) {
			mid = left + (right - left) / 2; 

			if (arr[mid] == target) {
				return mid;
			}

			if (target < arr[mid]) {
				right = mid - 1; 
			}
			else {
				left = mid + 1; 
			}
		}
		return -1; 
	}

	// Selection sort: selecting the index and checking minimum, then swapping
	// O(n^2)
	void selectionSort(int a[], int numberUsed) {
		int indexOfNextSmallest;
		for (int index = 0; index < numberUsed - 1; index++) {
			indexOfSmallest;
		}
	}

	// Insertion sort: 

	// Merge sort: 
	// uses recursion: when the function calls itself or we do the same thing again and again
	// Time complexity: n*log(n)

	// Quick sort: 

	// Vectors
	// similar to arrays
#include <vector>

	std::vector<int> v; 
	v.push_back(/* data here */); // appends values to the end of the vector
	v.size(); // returns the size of vector
	v.capacity(); // returns capacity (how many items the vector can hold)
	v.reserve(/* value here */) // sets capacity to 32

	for (unsined int i = 0; i < v.size(); i++) {

	}
