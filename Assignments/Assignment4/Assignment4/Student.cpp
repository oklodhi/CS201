#include "Student.h"

Students::Students() {
	id_number = 0; 
	first_name = "";
	last_name = "";
}

Students::~Students() {

}

std::string Students::GetFirstName() {
	return first_name;
}

std::string Students::GetLastName() {
	return last_name; 
}

int Students::GetIdNumber() {
	return id_number; 
}

void Students::SetFirstName(std::string _name) {
	first_name = _name;
}

void Students::SetLastName(std::string _name) {
	last_name = _name;
}
void Students::SetIdNumber(int _id) {
	id_number = _id;
}

int Students::CheckoutCount() {

}

bool Students::CheckOut(const std::string& item) {

}

bool Students::CheckIn(const std::string& item) {

}

bool Students::HasCheckedOut(const std::string& item) {

}

void Students::Clear() {

}