
#ifndef _Fraction_h_
#define _Fraction_h_


#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Fraction {
	int numerator, denominator;
	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);


public:
	typedef T objtype;

	inline Fraction(T n, T d = 1) {
		if (d == 0)
			throw string("divide by 0 exception");

		numerator = n;
		denominator = d;
	}

	inline void setNumerator(int n) { numerator = n; }
	int getNumerator(void) const
	{
		return numerator;
	}

	inline void setDenominator(int d) { denominator = d; }
	inline int getDenominator(void)  const
	{
		if (denominator == 0)
			return 1;
		else 
			return denominator;
	}

	inline float asFloat(void) {
		return (float)getNumerator() / getDenominator();
	}


	inline Fraction operator=(const Fraction& other) {
		numerator = other.numerator;
		if (other.denominator == 0)
			denominator = 1;
		else
			denominator = other.denominator;

		return other;
	}


	
	Fraction operator+(const Fraction& other)   const;

	Fraction operator+(int other);


	bool operator==(const Fraction& other) const   //implicitly inlined
	{
		return numerator == other.numerator && denominator == other.denominator;
	}


	inline Fraction operator+=(const Fraction& other)
	{
		numerator *= other.denominator;
		numerator += (other.numerator * denominator);
		denominator *= other.denominator;

		return Fraction(numerator, denominator);
	}

	int operator[ ] (int index)
	{
		switch (index)
		{
		case 0:
			return numerator;
			break;
		case 1:
			return denominator;
			break;
		default:
			return -1;
		}
	}

	Fraction operator++() //++num 1/3   + 1 = 4/3
	{
		numerator += denominator;
		return Fraction(numerator, denominator);
	}

	Fraction operator++(int i) // num ++
	{
		Fraction copy(numerator, denominator);
		numerator += denominator;
		return copy;
	}

	inline bool operator!(){
		if (numerator == 0)
		{
			return true;
		}
		else
			return false;
	}
};




#endif