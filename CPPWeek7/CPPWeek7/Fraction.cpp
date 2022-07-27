

#include "Fraction.h"


template<class T>
ostream& operator<<(ostream& out, const Fraction<T>& f)
{
	out << "Numerator:" << f.numerator
		<< " Denominator:" << f.denominator;
	return out;
}

template<class T>
istream& operator>>(istream& in, Fraction<T>& f)
{
	cout << "Enter a numerator first, then denominator" << endl;

	cin >> f.numerator;

	cin >> f.denominator;

	return  in;
}

/*
Fraction Fraction::operator=(const Fraction& other)
{
	numerator = other.numerator;
	if (other.denominator == 0)
		denominator = 1;
	else
		denominator = other.denominator;

	return other;
}*/

template<class T>
Fraction<T> Fraction<T>::operator+(const Fraction<T>& other)   const //can't chage this
{
	return Fraction((numerator * other.denominator) + (denominator * other.numerator),
		denominator * other.denominator);
}

template<class T>
Fraction<T> Fraction<T>::operator+(int other) // this means add int to Fraction
{
	return Fraction(numerator + (other * denominator), denominator);
}