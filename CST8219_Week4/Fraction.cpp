
#include "Fraction.h"

//now it knows class Fraction{}

Fraction::Fraction() : Fraction(0) {}//chaining to other

//can have  1, or 2 parameters
Fraction::Fraction(int n, int d) { //default 0/1
	setNumerator(n);
	setDenominator(d);
}

Fraction::Fraction(Fraction& other) :
	Fraction(other.getNumerator(), other.getDenominator())
{
	cout << "Copying from:" << &other << endl;
}

Fraction::Fraction(Fraction* pOther) : Fraction(*pOther)//call other copy constructor
{
	cout << "Copying from:" << pOther << endl;
}


//setNumerator and getNumerator are global functions:
void Fraction::setNumerator(int n) { numerator = n; }
int Fraction::getNumerator(void) { return numerator; }

void Fraction::setDenominator(int d) { denominator = d; }
int Fraction::getDenominator(void) { return denominator; }

float Fraction::asFloat(void) {
	return (float)getNumerator() / getDenominator();
}