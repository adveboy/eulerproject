#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

vector<double> &split(const string &s, char delim, vector<double> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(atof(item.c_str()));
	}
	return elems;
}

vector<double> split(const string &s, char delim) {
	vector<double> elems;
	split(s, delim, elems);
	return elems;
}

int main() {
	ifstream file("p102_triangles.txt");
	string str; 
	while (getline(file, str)) {
		vector<double> x = split(str, ',');
		for (int cnt=0; cnt<x.size(); cnt++) {
			cout << x[cnt] << " ";
		}
		cout << endl;
	}
	return 0;
}

