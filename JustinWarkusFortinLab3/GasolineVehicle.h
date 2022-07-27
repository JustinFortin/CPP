#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;
template<class T>
class GasolineVehicle : public Vehicle {
public:
	T currentGasoline, maximumGasoline;

	inline GasolineVehicle(T maxGas, T efficiency) {
		maximumGasoline = maxGas;
		currentGasoline = maximumGasoline;
		engineEfficiency = efficiency;
	};
	inline float calculateRange() {
		return  (float)currentGasoline * 100 / engineEfficiency;
	}
	inline float percentEnergyRemaining() {
		return  (float)(currentGasoline / maximumGasoline * 100.0);
	};
	inline void drive(float km) {
		if (currentGasoline < 0) {
			cout << "Your car is out of energy!" << endl;
			return;
		}
		currentGasoline -= (km / 100) * engineEfficiency;

		if (currentGasoline < 0) {
			cout << "Your car is out of energy!" << endl;
			return;
		}
	};
	inline ~GasolineVehicle() {
		cout << "In Gasoline Vehicle Destructor" << endl;
	};
};