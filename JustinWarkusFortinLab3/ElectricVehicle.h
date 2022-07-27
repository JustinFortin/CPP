#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;
template<class T>
class ElectricVehicle : public Vehicle {
public:
	T currentCharge, maximumCharge;
	inline ElectricVehicle(T maxCharge, T efficiency) {
		maximumCharge = maxCharge;
		currentCharge = maximumCharge;
		engineEfficiency = efficiency;
	};
	inline float calculateRange() {
		return  (float)currentCharge * 100 / engineEfficiency;
	};
	inline float percentEnergyRemaining() {
		return (float)(currentCharge / maximumCharge * 100.0);
	};
	inline void drive(float km) {
		if (currentCharge < 0) {
			cout << "Your car is out of energy!" << endl;
			return;
		}
		currentCharge -= (km / 100) * engineEfficiency;

		if (currentCharge < 0) {
			cout << "Your car is out of energy!" << endl;
			return;
		}
	};

	inline ~ElectricVehicle() {
		cout << "In Electric Vehicle Destructor" << endl;   //Change ClassName to either 

	};
};