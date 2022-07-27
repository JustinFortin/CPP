# CMakeList.txt : CMake project for CPPWeek10Lab8, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPPWeek10Lab8")
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add executable target with source files listed in SOURCE_FILES variable
#SHARED means make .dll instead of .lib

add_library(MyCPPLibrary0 SHARED "JavaGUI.h" "JavaGUI.cpp" "JavaGUI.java")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   /openmp")

target_include_directories( MyCPPLibrary0 PRIVATE
	"C:\\Program Files\\Java\\jdk1.8.0_261\\include"
	"C:\\Program Files\\Java\\jdk1.8.0_261\\include\\win32")


