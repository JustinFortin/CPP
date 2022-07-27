#include <iostream>
//header guard, only compile once
#pragma once

using namespace std;
class Fraction {
	int numerator, denominator;

public:
	Fraction();//chaining to other
	//can have  1, or 2 parameters
	Fraction(int, int = 1);
	Fraction(Fraction&);
	Fraction(Fraction*);

	void setNumerator(int);
	int getNumerator(void);

	void setDenominator(int);
	int getDenominator(void);

	float asFloat(void);
};