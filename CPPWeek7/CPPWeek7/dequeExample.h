
#pragma once
#include <iostream>
#include <deque>

using namespace std;

class DequeExamples {
public:

	static void example1()
	{
		deque<int> deq;  //empty vector

		cout << "deq size=" << deq.size() << endl << "Now adding two numbers:"<<endl;
		deq.push_back(5);
		deq.push_back(10);
		cout << "deq size=" << deq.size() << endl;

		cout << "deq back element:" << deq.back() << endl;  //.back() returns the object at the end but doesn't remove it.


		//accessor methods at( int )   and operator[] ( int )
		cout << "deq[0]=" << deq[0] << endl;
		cout << "deq.at(0)=" << deq.at(0) << endl;

		cout << "What happens when you access an element outside the range?" << endl;
		try {
			cout << "deq.at(6)=" << deq.at(6) << endl;
		}
		catch (out_of_range exc)
		{
			cout << "Out of range exception" << endl;
		}


		//add to front:
		deq.push_front(55);
		deq.push_front(3);

		//remove from back:
		cout << "popping back:" << endl;
		deq.pop_back();
		cout << "Size is now:" << deq.size() << endl;

		//remove from front:
		cout << "popping front:" << endl;
		deq.pop_front();
		cout << "Size is now:" << deq.size() << endl;


		//clear the vector:
		deq.clear();
		cout << "Size is now:" << deq.size() << endl;
	}



	//this example shows how to iterate over a vector:
	static void example2()
	{
		//using { initializer list notation }, new in C++11
		std::deque<int> deq = { 1, 2, 3, 4, 5 };

		for (deque<int>::iterator itr = deq.begin(); itr != deq.end(); itr++)
		{
			cout << "Element is:" << (*itr) << endl;
		}


		// The same thing as line 65 but using auto keyword"
		for (auto itr = deq.begin(); itr != deq.end(); itr++)
		{
			cout << "Element is:" << (*itr) << endl;
		}


		//C++ 11 feature: enhanced for loops, using iterators vec.begin(), vec.end() in the background:
		for (int num : deq)
		{
			cout << "Element is: " << num << endl;
		}

	}


};