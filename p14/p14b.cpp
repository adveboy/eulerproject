#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;


int main () {
	long long N = 1000000;
	long long maxl = 0, maxi = 0, curr_num, curr_length;
	for (int cnt = 2; cnt < N; cnt++) {
		curr_num = cnt; curr_length = 1;
		while (curr_num != 1) {
			if (curr_num % 2 == 0) 
				curr_num = curr_num/2;
			else
				curr_num = curr_num*3 + 1;
			curr_length++;
		}
		if (curr_length > maxl) {
			maxl = curr_length;
			maxi = cnt;
		}
	}
	
	cout << "found " << maxi << " at length " << maxl << endl;
}