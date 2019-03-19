#pragma once
#include <iostream>
#include <string>

class Students {
private: 
	std::string first_name; 
	std::string last_name; 
	unsigned int id_number; 
	unsigned int size_or_items; 
	std::string *str_ptr;

public: 
	Students();
	~Students();
	
	std::string GetFirstName();
	std::string GetLastName(); 
	int GetIdNumber(); 

	void SetFirstName(std::string _name);
	void SetLastName(std::string _name);
	void SetIdNumber(int _id); 

	int CheckoutCount();
	bool CheckOut(const std::string& item);
	bool CheckIn(const std::string& item);
	bool HasCheckedOut(const std::string& item);

	void Clear();
};