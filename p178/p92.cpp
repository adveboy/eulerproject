#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;

int main () {
	long long sum, num, cyp;
	long long total89 = 0;
	for (long long i = 2; i < 10000000; i++) {
		num = i;
		//cout << num << endl;
		while (num != 1 && num != 89) {
			cyp = num; sum = 0;
			while (cyp > 0) {
				sum = sum + (cyp % 10)*(cyp%10);
				cyp = cyp/10;
			}
			num = sum; 
			//cout << "->" << num;
		}
		//cout << endl;
		if (num == 89)
			total89++;
	}
	cout << "total89 = "  << total89 << endl;
}