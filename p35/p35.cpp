#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;

vector<long> num2cyp(long num) {
	vector<long> vc;
	while (num > 0) {
		vc.push_back(num%10);
		num = num/10;
	}
	return vc;
}

long cyp2num(vector<long> cyp) {
	long sum = 0;
	for (long i = 0; i< cyp.size(); i++) {
		sum = sum*10 + cyp[i];
	}
	return sum;
}


void print_vector(vector<long> vc) {
	for (long i=0; i<vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << endl;
}

bool isprime(long num) {
	bool prime = true;
	for(long n = 2; n <= num - 1; n++){
		if(num % n == 0){
			prime = false;
		}
	}
	return prime;
}



int main () {
	long num;
	bool prime;
	long roundprime = 0;
	for(long i = 2; i <= 1000000; i++){
		prime = true;
		num = i;
		//cout << "num = " << num << endl;
		if (isprime(num)) {
			vector<long> vc = num2cyp(i);
			sort(vc.begin(),vc.end());
			do {
				// cout << "cyp2num(vc) = " << cyp2num(vc) << endl;
				if (!isprime(cyp2num(vc))) {
					// cout << cyp2num(vc) << " is not prime " << endl;
					prime = false;
					break;
				}
			} while ( next_permutation(vc.begin(), vc.end()));
			if (prime) {
				// cout << "roundprime " << num << endl;
				roundprime++;
			}
		}
		if (i % 100000 == 0) {
			cout << i << endl;
		}
	}
	cout << "roundprime number " << roundprime << endl;
}