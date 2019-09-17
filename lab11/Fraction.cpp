// Your name
// Your UMKC Email Address
// Today's date
// CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	if (denominator < 0) {
		denominator = abs(denominator);
		numerator = 0 - numerator;
	}
}

// this is the output stream operator overload
ostream& operator<< (ostream& output, const Fraction& fract) {

	output << fract.numerator << " / " << fract.denominator;

	return output;
}

// this is the input stream operator
istream& operator>>(istream& input, Fraction& fract) {
	char slashIgnore; 
	input >> fract.numerator >> slashIgnore >> fract.denominator;

	return input;
}

// this is adding operator overload. Cross multiply
const Fraction Fraction::operator+(Fraction rhs) {
	Fraction fra; 

	fra.numerator = (this->numerator*rhs.denominator) + (this->denominator*rhs.numerator); 
	fra.denominator = this->denominator * rhs.denominator; 
	fra.reduce();
	return fra;
}

// this is subtracting operator overload. Cross multiply
const Fraction Fraction::operator-(Fraction rhs) {
	Fraction fra;

	fra.numerator = (this->numerator*rhs.denominator) - (this->denominator*rhs.numerator);
	fra.denominator = this->denominator * rhs.denominator;
	fra.reduce();
	return fra;
}

// this is multiply operator overload
const Fraction Fraction::operator*(Fraction rhs) {
	Fraction fra;

	fra.numerator = this->numerator*rhs.numerator;
	fra.denominator = this->denominator * rhs.denominator;
	fra.reduce();
	return fra;
}

// this is dividing operator overload
const Fraction Fraction::operator/(Fraction rhs) {
	Fraction fra;

	fra.numerator = this->numerator*rhs.denominator;
	fra.denominator = this->denominator * rhs.numerator;
	fra.reduce();
	return fra;
}

const bool Fraction::operator==(Fraction rhs) {
	if ((this->denominator == rhs.denominator) && (this->numerator == rhs.numerator)) {
		return true; 
	}
	else {
		return false;
	}
}
