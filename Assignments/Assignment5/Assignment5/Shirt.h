#pragma once

#include "Products.h"

class Shirt : public Product {
private:
	std::string size; 
public:
	Shirt();
	void setSize(std::string _size);
	void print(std::ostream _os); 
	void calculateTotal();
};