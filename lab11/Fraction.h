#pragma once
// Your Name
// Today's date
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int numerator;
	int denominator; 
	int getGCD(int num1, int num2);

public:
	Fraction();
	void reduce();
	friend ostream& operator<< (ostream& output, const Fraction& fract);
	friend istream& operator>> (istream& input, Fraction& fract);

	const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	const bool Fraction::operator==(Fraction rhs);
};

