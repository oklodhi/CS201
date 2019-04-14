#pragma once

#include "Products.h"
#include <fstream>


class Register {
private: 
	Product *arr; 
	int numProducts;
public:
	Register(); 
	void addProduct();
	void printReceipt(std::ostream _os);
};