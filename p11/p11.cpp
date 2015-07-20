#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 

using namespace std;

#define MATRIX_SIZE 20
#define FILE_NAME_H "mx.txt"


void output_matrix(vector< vector<int> > data) {
	for (int i=0; i<data.size(); i++) {
		for (int j=0; j<data.size(); j++) {
			cout << data[i][j]  << " " ;
		}
		cout << endl;
	}
}

long leftright(vector< vector<int> > data) {
	long maxprod = 0, curr_prod = 0; 
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size() - 4; j++) {
			// cout << "i = " << i << "; j = " << j << endl;
			curr_prod = data[i][j]*data[i][j+1]*data[i][j+2]*data[i][j+3];
			// cout << "curr_prod = " << curr_prod << endl;
			if (curr_prod > maxprod)  {
				maxprod = curr_prod;
				// cout << "maxprod = " << maxprod << endl;
			}
		}
	}
	return maxprod;
}

long updown(vector< vector<int> > data) {
	long maxprod = 0, curr_prod = 0; 
	for (int i = 0; i < data.size() - 3; i++) {
		for (int j = 0; j < data[i].size(); j++) {
			// cout << "i = " << i << "; j = " << j << endl;
			curr_prod = data[i][j]*data[i+1][j]*data[i+2][j]*data[i+3][j];
			// cout << "curr_prod = " << curr_prod << endl;
			if (curr_prod > maxprod)  {
				maxprod = curr_prod;
				// cout << "maxprod = " << maxprod << endl;
			}
		}
	}
	return maxprod;
}

long diag1(vector< vector<int> > data) {
	long maxprod = 0, curr_prod = 0; 
	for (int i = 0; i < data.size() - 3; i++) {
		for (int j = 0; j < data[i].size() - 3; j++) {
			// cout << "i = " << i << "; j = " << j << endl;
			curr_prod = data[i][j]*data[i+1][j+1]*data[i+2][j+2]*data[i+3][j+3];
			// cout << "curr_prod = " << curr_prod << endl;
			if (curr_prod > maxprod)  {
				maxprod = curr_prod;
				// cout << "maxprod = " << maxprod << endl;
			}
		}
	}
	return maxprod;
}

long diag2(vector< vector<int> > data) {
	long maxprod = 0, curr_prod = 0; 
	for (int i = 0; i < data.size() - 3; i++) {
		for (int j = 3; j < data[i].size(); j++) {
			// cout << "i = " << i << "; j = " << j << endl;
			curr_prod = data[i][j]*data[i+1][j-1]*data[i+2][j-2]*data[i+3][j-3];
			// cout << "curr_prod = " << curr_prod << endl;
			if (curr_prod > maxprod)  {
				maxprod = curr_prod;
				// cout << "maxprod = " << maxprod << endl;
			}
		}
	}
	return maxprod;
}


int main () {
	vector< vector<int> > data(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
	ifstream file(FILE_NAME_H);
	for (int i = 0; i < MATRIX_SIZE; ++i) {
	    for (int j = 0; j < MATRIX_SIZE; ++j) {
		data[0][0] = i+j;
		file >> data[i][j];
	    }
	}
	/*
	output_matrix(data);
	cout << leftright(data) << endl;
	cout << updown(data) << endl;
	cout << diag1(data) << endl;
	cout << diag2(data) << endl;
	*/
	
	cout << "max product is " << max(max(leftright(data),updown(data)),max(diag1(data),diag2(data))) << endl;
}