//#pragma once
//#include <iostream>
//using namespace std;
//template<class T>
//class Vehicle {
//public:
//	T numWheels=0, numDoors=0;
//	T engineEfficiency;
//	inline Vehicle(T w, T d) {
//		numWheels = w;
//		numDoors = d;
//	};
//	inline Vehicle(T w) : Vehicle<T>(w, 4) {};
//	inline Vehicle() : Vehicle(4) {};
//	~Vehicle() {
//		cout << "In  Vehicle Destructor " << endl;
//	};
//	inline void printVehicle() {};
//	inline Vehicle(Vehicle&) :Vehicle(copy.numWheels, copy.numDoors) {};
//	inline Vehicle(Vehicle*) :Vehicle(*copy) {};
//
//};
#pragma once

using namespace std;

class Vehicle {
public:
    int numWheels = 0, numDoors = 0;
    float engineEfficiency = 0;

    Vehicle(int w, int d);
    Vehicle(int w);
    Vehicle();
    ~Vehicle();
    void printVehicle();
    Vehicle(Vehicle&);
    Vehicle(Vehicle*);
    void setParameters(int w, int d);
};