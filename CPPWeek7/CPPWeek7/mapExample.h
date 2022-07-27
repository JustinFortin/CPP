




#pragma once
#include <iostream>
#include <map>

using namespace std;

class MapExamples {
public:

	static void example1()
	{
		map<string, int> dataTable;		// map structure with keys that are string, and values that are int


		dataTable.insert(make_pair("Eric", 1));

		dataTable.insert(make_pair("A", 44));

		dataTable.insert(make_pair("B", 2));

		cout << "Map size=" << dataTable.size();

		map<string, int>::iterator answer = dataTable.find("ABC"); //now have to use * to find element
		if(answer != dataTable.end())
			cout << "Found value:" << (*answer).first << " and second:" << (*answer).second << endl;

		//query:
		answer = dataTable.find("A");
		if(answer != dataTable.end())
			cout << "Found value:" << (*answer).first << " and second:" << (*answer).second << endl;


		//Iterate over all pairs in the map:
		for (auto val : dataTable)
		{

			cout << "Key:" << val.first << " value:" << val.second << endl;
		}
 

	}


};