#pragma once

#include "Products.h"
#include <fstream>
#include <ios>
#include <iomanip>

// class register. everything happens here

class Register {
private: 
	static const int max = 50;
	Product *arr[max];
	int numProducts;

public:
	// constructors
	Register(); 

	// member functions
	void addProduct(Product* _ptr);
	void printReceipt(std::ostream _os);
};