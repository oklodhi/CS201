#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies() {

}

OfficeSupplies::OfficeSupplies(double _price, int _quantity, std::string _description, int _count) {
	price = _price;
	quantity = _quantity;
	description = _description;
	count = _count;
}

void OfficeSupplies::setCount(int _count) {
	count = _count;
}

void OfficeSupplies::print(std::ostream& _os) {
	_os << std::setw(3) << std::right << quantity << " ";
	_os << std::setw(28) << std::left << description + " (" + std::to_string(count) + " count)";
	_os << "$" << std::setw(7) << std::right << calculateTotal() << std::endl;
}