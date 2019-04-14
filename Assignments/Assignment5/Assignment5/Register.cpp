#include "Register.h"

Register::Register() {
	numProducts = 0;
}

void Register::addProduct(Product* _ptr) {
	arr[numProducts] = _ptr;
	numProducts++;
}

void Register::printReceipt(std::ostream _os) {
	_os.setf(std::ios::fixed);
	_os.setf(std::ios::showpoint);
	_os.precision(2);

	// total sale amount
	double total = 0.00;

	// heading
	_os << "****************************************\n";
	_os << "*   CS 201 Super Selling Stuff Store   *\n";
	_os << "****************************************\n";
	_os << std::endl;
	_os << "Qty Description                 Total   \n";
	_os << "--- --------------------------- --------\n";

	// iterate through the pointer array for printing
	for (int i = 0; i < numProducts; i++)
	{
		arr[i]->print(_os);
		// add to overrall total
		total += arr[i]->calculateTotal();
	}

	// ending
	_os << std::endl;
	_os << std::setw(13) << std::left << "Grand total: $" << total << std::endl;
	_os << std::setw(13) << std::left << "Items sold: " << numProducts << std::endl << std::endl;
	_os << "* Thank you for shopping at our store! *\n";
}