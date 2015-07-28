#include <iostream>
// #include <eigen3/Eigen/Dense>
#include "eigen3/Eigen/Dense"
using namespace std;
using namespace Eigen;
#include <math.h>       /* (long)pow */
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */

struct fPoint {
	double x;
	double y;
};

float sign (fPoint p1, fPoint p2, fPoint p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3) {
	bool b1, b2, b3;
	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}

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
	fPoint A,B,C,O;
	O.x = 0; O.y = 0;
	long sum = 0;
	while (getline(file, str)) {
		vector<double> x = split(str, ',');
		A.x = x[0]; A.y = x[1];
		B.x = x[2]; B.y = x[3];
		C.x = x[4]; C.y = x[5];
//		cout << PointInTriangle(O,A,B,C) << endl;
		sum += PointInTriangle(O,A,B,C);
	}
	cout << sum << endl;
	return 0;
}

