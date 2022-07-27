

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class VectorExamples {
public:

	static void example1()
	{
		vector<int> vec;  //empty vector

		cout << "vec size=" << vec.size() << endl << "Now adding two numbers:";
		vec.push_back(5);
		vec.push_back(10);
		cout << "\nvec size=" << vec.size() << endl;

		cout << "vec back element:" << vec.back() << endl;  //.back() returns the object at the end but doesn't remove it.
		 

		//accessor methods at( int )   and operator[] ( int )
		cout << "vec[0]=" << vec[0] << endl;
		cout << "vec.at(0)=" << vec.at(0) << endl;

		cout << "What happens when you access an element outside the range?" << endl;
		try {
			cout << "vec.at(6)=" << vec.at(6) << endl;
		}
		catch (out_of_range exc)
		{
			cout << "Out of range exception" << endl;
		}


		//remove from back:
		cout << "popping back:"  << endl;
		vec.pop_back();
		cout << "Size is now:" << vec.size() << endl;

		//add more elements:
		vec.push_back(4);
		vec.push_back(7);
		cout << "Size is now:" << vec.size() << endl;

		//clear the vector:
		vec.clear();
		cout << "Size is now:" << vec.size() << endl;
	}



	//this example shows how to iterate over a vector:
	static void example2()
	{
		//using { initializer list notation }, new in C++11
		std::vector<int> vec = { 1, 2, 3, 4, 5 };

		for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		{
			cout << "Element is:" << (*itr) << endl;
		}

		// The same thing as line 61, but using auto keyword"
		for (auto itr = vec.begin(); itr != vec.end(); itr++)
		{
			cout << "Element is:" << (*itr) << endl;
			if ((*itr) == 4)
				vec.erase(itr--);
		}

		//C++ 11 feature: enhanced for loops, using iterators vec.begin(), vec.end() in the background:
		for (int num : vec)
		{
			cout << "Element is: " << num << endl;
		}
	}


};