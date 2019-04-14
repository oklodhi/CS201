#pragma once

#include <iomanip>
#include "Products.h"

// class officeSuplies that is of type class products

class OfficeSupplies : public Product {
private: 
	int count; 

public: 
	// constructors
	OfficeSupplies();
	OfficeSupplies(double _price, int _quantity, std::string _description, int _count);

	// setters
	void setCount(int _count);

	// overridden virtual functions
	void print(std::ostream _os) override;
};