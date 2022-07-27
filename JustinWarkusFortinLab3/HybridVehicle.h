#pragma once
#include "ElectricVehicle.h"
#include "GasolineVehicle.h"

template<class T>
class HybridVehicle : public ElectricVehicle<T>, public GasolineVehicle<T> {
public:
	inline HybridVehicle(T gasMax, T gasEfficiency, T chargeMax, T electricEfficiency) : GasolineVehicle(gasMax, gasEfficiency), ElectricVehicle(chargeMax, electricEfficiency) {
	};
	inline float calculateRange() {
		return  (float)(currentCharge * 100 / ElectricVehicle::engineEfficiency) + (currentGasoline * 100 / GasolineVehicle::engineEfficiency);
	};
	inline float percentEnergyRemaining() {
		return  (float)((currentCharge / maximumCharge * 100.0) + (currentGasoline / maximumGasoline * 100.0)) / 2;
	};
	inline void drive(float km) {
		if (km > ElectricVehicle::calculateRange()) {
			km -= ElectricVehicle::calculateRange();
			currentCharge = 0;
		}
		if (currentCharge > 0) {
			currentCharge -= (km / 100) * ElectricVehicle::engineEfficiency;
		}
		else {
			currentGasoline -= (km / 100) * GasolineVehicle::engineEfficiency;
			if (currentGasoline < 0) {
				cout << "Your car has run out of energy!" << endl;
			}
		}
	};
	inline ~HybridVehicle() {
		cout << "In Hybrid Vehicle Destructor" << endl;
	};
};