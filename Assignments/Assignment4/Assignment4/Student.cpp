#include "Student.h"

// default constructor initializes everything to NULL
Students::Students() {
	id_number = 0;
	first_name = "";
	last_name = "";

	size_or_items = 0;
	maxSize = 10;
	arr = new std::string[maxSize];
}

// overload constructor initializes to arguements passed in
Students::Students(unsigned int _id, std::string& _first, std::string& _last) {
	id_number = _id;
	first_name = _first;
	last_name = _last;

	size_or_items = 0;
	arr = new std::string[maxSize];
}

// deconstructor
Students::~Students() {

}

// returns first name of student
std::string Students::GetFirstName() {
	return first_name;
}

// returns last name of student
std::string Students::GetLastName() {
	return last_name;
}

// returns id number of student
int Students::GetIdNumber() {
	return id_number;
}

// sets first name of student to arguement passed in
void Students::SetFirstName(std::string _name) {
	first_name = _name;
}

// sets last name of student to arguement passed in
void Students::SetLastName(std::string _name) {
	last_name = _name;
}

// sets id number of student to arguement passed in
void Students::SetIdNumber(int _id) {
	if (_id >= 1000 && _id <= 10000) {
		id_number = _id;
	}
	else {
		id_number = 1001;
	}
}

// return the total number of checked out 
int Students::CheckoutCount() {
	return size_or_items;
}

// checkout item
bool Students::CheckOut(const std::string& _item) {
	if (HasCheckedOut(_item)) {
		return false;
	}

	if (size_or_items == 0) {
		arr = new std::string[5];
	}

	arr[size_or_items] = _item;
	size_or_items++;

	if (size_or_items == (maxSize - 1)) {
		resize();
	}

	return true;
}

// checkin item
bool Students::CheckIn(const std::string& _item) {
	if (HasCheckedOut(_item)) {
		for (unsigned int i = 0; i < size_or_items; i++) {
			if (arr[i] == _item) {
				arr[i] = "";
				size_or_items--;
				return true;
			}
		}
	}

	return false;
}

// returns whether a student has any items checkedout
bool Students::HasCheckedOut(const std::string& _item) {
	for (unsigned int i = 0; i < size_or_items; i++) {
		if (arr[i] == _item) {
			return true;
		}
	}

	return false;
}

// resize the dynamic array
void Students::resize() {
	// creates new size 
	int newSize = maxSize * 2;
	// creates new temporary array
	std::string* temp = new std::string[newSize];
	for (unsigned int i = 0; i < size_or_items; i++) {
		// copies data from old array to new array
		temp[i] = arr[i];
	}

	arr = temp;
	maxSize = newSize;
}

// clear student checkin / checkout data
void Students::clear() {
	id_number = 0;
	first_name = "";
	last_name = "";

	delete[] arr;
	maxSize = 10;
	size_or_items = 0;
	std::cout << "CLEARED!" << std::endl;
}

// >> operator overloading
std::istream& operator>>(std::istream& in, Students& _stu) {
	int temp = 0;

	std::cout << "Extraction operator..." << std::endl;

	_stu.clear();

	in >> _stu.id_number >> _stu.first_name >> _stu.last_name >> temp;

	std::cout << _stu.id_number << " " << _stu.first_name << " " << _stu.last_name << " " << temp << std::endl;

	if (temp == 0) {
		std::cout << "No items checked out" << std::endl;
		return in;
	}

	std::string item;

	std::cout << "Adding items... and increasing array capacity" << std::endl;

	_stu.maxSize = 10;
	_stu.arr = new std::string[_stu.maxSize];

	for (int i = 0; i < temp; i++) {
		in >> item;
		_stu = _stu + item;

		std::cout << "index: " << i << " - " << _stu.arr[i] << std::endl;
	}

	return in;
}

// << operator overloading
std::ostream& operator<<(std::ostream& out, Students& _stu) {
	if (_stu.CheckoutCount() > 0) {
		out << _stu.GetIdNumber() << " " << _stu.GetFirstName() << " " << _stu.GetLastName() << "\n";
		out << _stu.CheckoutCount() << "\n";

		for (unsigned int i = 0; i < _stu.size_or_items; i++) {
			out << _stu.arr[i] << " ";
		}
		out << std::endl << std::endl;
		return out;
	}
	else if (_stu.CheckoutCount() <= 0) {
		out << _stu.GetIdNumber() << " " << _stu.GetFirstName() << " " << _stu.GetLastName() << "\n";
		out << _stu.CheckoutCount() << "\n";
		out << std::endl;
		return out;
	}

	return out;
}

// + operator overloading
Students Students::operator+(const std::string& _item) {
	if (!HasCheckedOut(_item)) {
		if (size_or_items == (maxSize - 1)) {
			resize();
		}

		arr[size_or_items] = _item;
		size_or_items++;
	}

	return *this;
}

// += operator overloading
void Students::operator+=(const std::string& _item) {
	while (true) {
		if (!HasCheckedOut(_item)) {
			for (unsigned int i = 0; i < maxSize; i++) {
				if (arr[i] == "") {
					arr[i] = _item;
					size_or_items++;
					return void();
				}
			}
			resize();
		}
	}
}

// == operator overloading
bool Students::operator==(const Students& _cmp) const {
	return (id_number == _cmp.id_number);
}

// != operator overloading
bool Students::operator!=(const Students& _inq) const {
	return !(id_number == _inq.id_number);
}