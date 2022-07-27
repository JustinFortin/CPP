#pragma once
#include "HybridVehicle.h"

HybridVehicle<float>::HybridVehicle(float gasMax, float gasEfficiency, float chargeMax, float electricEfficiency) : GasolineVehicle(gasMax, gasEfficiency)  , ElectricVehicle(chargeMax, electricEfficiency){
};
float HybridVehicle<float>::calculateRange() {
	return  (float)(currentCharge * 100 / ElectricVehicle::engineEfficiency) + (currentGasoline * 100 / GasolineVehicle::engineEfficiency);
};
float HybridVehicle<float>::percentEnergyRemaining() {
	return  (float)((currentCharge / maximumCharge * 100.0) + (currentGasoline / maximumGasoline * 100.0)) / 2;
};
void HybridVehicle<float>::drive(float km) {
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
HybridVehicle<float>::~HybridVehicle() {
	cout << "In Hybrid Vehicle Destructor" << endl;
};