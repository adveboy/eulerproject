// unordered_map::count
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main () {
	std::unordered_map<std::string, double> mymap = {
		{"Burger",2.99},
		{"Fries",1.99},
		{"Soda",1.50} };

	cout << "Fries: " << mymap.count("Fries") << endl;
	/*
	for (auto& x: {"Burger", "Pizza", "Salad", "Soda"}) {
		if (mymap.count(x) > 0)
			std::cout << "mymap has " << x << std::endl;
		else
			std::cout << "mymap has no " << x << std::endl;
	}
	*/
	return 0;
}