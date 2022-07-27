# CMakeList.txt : CMake project for CPPFinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPPFinalProject")

# Add source to this project's executable.
add_executable (CPPFinalProject "CPPFinalProject.cpp" "CPPFinalProject.h")
target_include_directories(CPPFinalProject PUBLIC "C:\\Users\\jt\\source\\repos\\CPPFinalProject\\nana_1.7.4\\nana\\include")
add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO)
target_link_directories(CPPFinalProject PUBLIC "C:\\Users\\jt\\source\\repos\\CPPFinalProject\\nana_1.7.4\\build\\bin")
target_link_libraries(CPPFinalProject "nana_v142_Debug_x64")
# TODO: Add tests and install targets if needed.