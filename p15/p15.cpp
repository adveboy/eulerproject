#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;

void output_matrix(vector< vector<long long> > data) {
	for (int i=0; i<data.size(); i++) {
		for (int j=0; j<data.size(); j++) {
			cout << data[i][j]  << " " ;
		}
		cout << endl;
	}
}


int main () {
	int N = 20;
	vector< vector<long long> > vc(N+1, vector<long long>(N+1));
	vc[0][0] = 0;
	for (int cnt = 1; cnt < vc.size(); cnt++) {
		vc[cnt][0] = 1;
	}
	
	// cout << "vc.size() = " << vc.size() << endl;
	for (int i = 1; i < vc.size(); i++) {
		// cout << "i = " << i << endl;
		// cout << "vc[i].size() = " << vc[i].size() << endl;
		for (int j = 1; j <= i; j++) { 
			// // cout << "j = " << j << endl;
			if (i == j) {
				// cout << "i == j" << endl;
				vc[i][j] = 2*vc[i][j-1];
				// cout << "/i == j" << endl;
			} else {
				vc[i][j] = vc[i][j-1] + vc[i-1][j];
			}
			// cout << "for j end" << endl;
			// cout << "i = " << i << endl;
			
		}
	
	}
	cout << "vc[N][N] = " << vc[N][N] << endl;
	cout << "vc[2][3] = " << vc[3][2] << endl;
	output_matrix(vc);
	return 0;
}