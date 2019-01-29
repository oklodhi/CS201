// C++ is an object oriented programming language
    // Encapsulation, Polymorphism, Inheritance

// Every program starts with
    // #include <iostream>
    // using namespace std;

// New C++11 types
    auto x = expression;
    decltype(x*3.5) y;

// Data types
    int _int = 10;
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


	// greater than, equal to etc. > < >= <=
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