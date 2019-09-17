// Omer Khan
// mokddp@mail.umkc.edu
// April 18
// CS201L Lab 12

#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string myName) {
	employeeID = id; 
	payRate = 10.0;
	name = myName; 
	balance = 0.0;
}

int Employee::getEmployeeID() {
	return employeeID; 
}

double Employee::getPayRate() {
	return payRate; 
}

double Employee::getBalance() {
	return balance; 
}

string Employee::getName() {
	return name;
}

void Employee::giveRaise(int rate) {
	payRate = payRate + (payRate * (rate * .01));
}

void Employee::pay() {
	balance = balance + payRate; 
}

void Employee::fire() {
	payRate = 0; 
	employed = false; 
}

bool Employee::isEmployed() {
	return employed;
}