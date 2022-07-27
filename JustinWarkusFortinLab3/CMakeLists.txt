# CMakeList.txt : CMake project for CPPWeek2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.2)

project ("CPPWeek3")

# Add source to this project's executable.
add_executable (CPPWeek3 "CPPWeek2.cpp" "CPPWeek2.h" "Vehicle.h" "Vehicle.cpp"  "ElectricVehicle.cpp" "GasolineVehicle.cpp" "HybridVehicle.cpp" "HybridVehicle.h" "ElectricVehicle.h" "GasolineVehicle.h")

# TODO: Add tests and install targets if needed.
