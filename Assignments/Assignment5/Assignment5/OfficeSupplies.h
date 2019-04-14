#pragma once

#include "Products.h"

class OfficeSupplies : public Product {
private: 
	int count; 
public: 
	void setCount(int _count);
	void print(std::ostream _os);
};