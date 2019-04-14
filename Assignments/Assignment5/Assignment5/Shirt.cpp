#include "Shirt.h"

Shirt::Shirt() {
	size = "";
}

Shirt::Shirt(double _price, int _quantity, std::string _description, std::string _size) {
	price = _price;
	quantity = _quantity;
	description = _description;
	size = _size;
}

void Shirt::setSize(std::string _size) {
	size = _size;
}

void Shirt::print(std::ostream _os) {
	_os << std::setw(3) << std::right << quantity << " ";
	_os << std::setw(28) << std::left << size + " " + description; 
	_os << "$" << std::setw(7) << std::right << calculateTotal() << std::endl;
}

double Shirt::calculateTotal() {
	// + $1 if shirt is big size
	if ((size == "2XL" || size == "3XL") && !priceInc) {
		price = price + 1; 
		priceInc = true;
	}
	return (quantity * price);
}