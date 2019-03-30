#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Students {
	// all private member variables
private: 
	std::string first_name; // first name of student
	std::string last_name; // last name of student
 	unsigned int id_number; // id number of student
	unsigned int size_or_items; // total number of items a student checks out
	unsigned int maxSize; // temporary size of dynamic array

	typedef std::string* str_ptr; // dynamic array pointer
	str_ptr arr; 

	// all public member functions 
public: 
	// default constructor initializes everything to NULL
	Students();
	// overload constructor initializes to arguements passed in
	Students(unsigned int _id, std::string& _first, std::string& _last); 
	// deconstructor
	~Students();
	
	// returns first name of student
	std::string GetFirstName();
	// returns last name of student
	std::string GetLastName(); 
	// returns id number of student
	int GetIdNumber(); 

	// sets first name of student to arguement passed in
	void SetFirstName(std::string _name);
	// sets last name of student to arguement passed in
	void SetLastName(std::string _name);
	// sets id number of student to arguement passed in
	void SetIdNumber(int _id); 

	// return the total number of checked out 
	int CheckoutCount();
	// checkout item
	bool CheckOut(const std::string& _item);
	// checkin item
	bool CheckIn(const std::string& _item);
	// returns whether a student has any items checkedout
	bool HasCheckedOut(const std::string& _item);

	// resize the dynamic array
	void resize();
	// clear student checkin / checkout data
	void clear();

	// >> operator overloading
	friend std::istream& operator>>(std::istream& in, Students& _stu); 
	// << operator overloading
	friend std::ostream& operator<<(std::ostream& out, Students& _stu);

	// + operator overloading
	Students operator+(const std::string& _item); 
	// += operator overloading
	void operator+=(const std::string& _item);
	// == operator overloading
	bool operator==(const Students& _cmp) const; 
	// != operator overloading
	bool operator!=(const Students& _inq) const; 
};