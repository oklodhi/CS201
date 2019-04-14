#pragma once

#include <iomanip>
#include "Products.h"

// class shirt that is a type of class product

class Shirt : public Product {
private:
	std::string size; 
	bool priceInc = false; // keeps track of price increase for big size shirts

public:
	// constructor
	Shirt();
	Shirt(double _price, int _quantity, std::string _description, std::string _size);

	// setters
	void setSize(std::string _size);

	// overridden virtual functions
	void print(std::ostream _os) override; 
	double calculateTotal() override;
};