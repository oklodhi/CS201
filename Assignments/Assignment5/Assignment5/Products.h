#pragma	once

#include <string>
#include <fstream>

// class product that is a generic product type

class Product {
protected: 
	double price; 
	int quantity; 
	std::string description;

public: 
	// constructors
	Product();
	Product(double _price, int _quantity, std::string _description);

	// setters
	void setPrice(double _price);
	void setQuantity(int _quantity);
	void setDescription(std::string _description);

	// virtual functions
	virtual void print(std::ostream& _os);
	virtual double calculateTotal();
};