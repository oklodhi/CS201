#pragma	once

#include <string>
#include <fstream>

class Product {
private: 
	double price; 
	int quantity; 
	std::string description;

public: 
	Product();
	Product(double _price, int _quantity);
	void setPrice(double _price);
	void setQuantity(int _quantity);
	void setDescription(std::string _description);

	virtual void print(std::ostream _os);
	virtual void calculateTotal();
};