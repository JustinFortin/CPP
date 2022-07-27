// CPPWeek 1.cpp : Defines the entry point for the application.
//

#include "CPPWeek 1.h"
#define usingNamespaces 0 

#if usingNamespaces == 0 
using namespace std;
int main(){
#pragma message("Using namespaces")
	cout << "Hello World!." << endl;
	return 0;
}
#elif usingNamespaces 
int main() {
#pragma message("Not using namespaces")
	std::cout << "Bye World!" << std::endl;
	return 0;
}
#endif 