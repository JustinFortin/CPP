// week4.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Fraction.h"

#include "vectorExample.h"
#include "dequeExample.h"
#include "mapExample.h"

using namespace std;


int main()
{
	VectorExamples::example1();
	VectorExamples::example2();

	DequeExamples::example1();
	DequeExamples::example2();

	MapExamples::example1();
	return 0;
}