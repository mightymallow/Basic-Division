// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  
// Date: 

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

// default constructor for no parameters
Fraction::Fraction(void) {
	numerator = 0;
	denominator = 1;
}

//constructor that requires 1 parameter at least
Fraction::Fraction(long long num, long long denom) {
	numerator = num;
	denominator = denom;

	simplify();
}

//adds two fractions together and then simplifies/fixes negative signs
const Fraction & Fraction::plusEq(const Fraction & op)
{
	long long temp = denominator;
	long long temp2 = op.numerator;

	numerator *= op.denominator;
	denominator *= op.denominator;
	temp2 *= temp;
	numerator += temp2;

	simplify();

	return (*this);
}

//subtracts one fraction from another and then simplifies/fixes negative signs
const Fraction & Fraction::minusEq(const Fraction & op)
{
	long long temp = denominator;
	long long temp2 = op.numerator;

	numerator *= op.denominator;
	denominator *= op.denominator;
	temp2 *= temp;
	numerator -= temp2;

	simplify();

	return (*this);
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

//multiplies two fractions together and then simplifies/fixes negative signs
const Fraction & Fraction::divideEq(const Fraction & op) {
	
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();

	return (*this);
}

//returns a Fraction object that is the negation of the object it is invoked on
Fraction Fraction::negate (void)const {
	long long x = numerator;
	long long y = denominator;

	if ((x < 0 && y < 0) || (x > 0 && y < 0)) {
		y *= -1;
	}
	else {
		x *= -1;
	}

	return Fraction(x, y);
}

//accessor for numerator field
long long Fraction::getNum(void)const {
	return numerator;
}

//accessor for denominator field
long long Fraction::getDenom(void)const {
	return denominator;
}

//displays the fraction on the screen in correct format
void Fraction::display(void)const {
	cout << numerator << "/" << denominator;
}

//fixes negative signs and then simplifies using gcd template
void Fraction::simplify(void) {
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}

	long long temp = gcd(numerator, denominator);
	numerator /= temp;
	denominator /= temp;

}
