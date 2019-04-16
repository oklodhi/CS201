// Omer Khan
// Assignment 5
// CS 201R, Gharibi

#include "OfficeSupplies.h"
#include "Products.h"
#include "Register.h"
#include "Shirt.h"

int main() {
	// input and output stream
	std::ifstream fin("products.txt");
	std::ofstream fout("receipt.txt");

	// Register class object
	Register reg; 

	// variables to hold .txt info
	std::string type, description, size; 
	int quantity, count;
	double price; 

	// keep reading from file as long as there is something there
	while (fin >> type) {
		// Product ptr
		Product *item; 
		item = new Product;

		if (type == "SHIRT") {
			// ignore newline characters
			fin.ignore();
			getline(fin, description);
			getline(fin, size);
			fin >> quantity >> price;
			fin.ignore();

			// ptr will point to shirt
			item = new Shirt(price, quantity, description, size);

			// add shirt ptr to array
			reg.addProduct(item);
		}
		else if (type == "SUPPLIES") {
			fin.ignore();
			getline(fin, description);
			fin >> count >> quantity >> price;
			fin.ignore();

			// Product pointer now points at the supplies
			item = new OfficeSupplies(price, quantity, description, count);

			// Add supplies to the register array
			reg.addProduct(item);
		}
	}

	// print the items to receipt
	reg.printReceipt(fout);

	// close file streams
	fin.close();
	fout.close();

	return 0;
}