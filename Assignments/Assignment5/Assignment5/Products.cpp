#include "Products.h"


Product::Product() {
	price = 0.0;
	quantity = 0;
	description = "";
}

Product::Product(double _price, int _quantity, std::string _description) {
	price = _price;
	quantity = _quantity;
	description = _description;
}

void Product::setPrice(double _price) {
	price = _price;
}

void Product::setQuantity(int _quantity) {
	quantity = _quantity; 
}

void Product::setDescription(std::string _description) {
	description = _description;
}

void Product::print(std::ostream& _os) {
	// blank
	// will be overridden based on product type
}

double Product::calculateTotal() {
	return (quantity * price);
}