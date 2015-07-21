#include <vector>
#include <iostream>
#include <stdlib.h>     /* abs */
/*
b should be prime because n*n + a*n + b = n(n + a) + b is prime for all n = 0 to Nmax. We know that n*n-79n+1601 generates consecutive primes from 0 to 79. we are interested in a,b where number of generated primes i more than 79. if so, b doesn't have divisors less than 80
but minimal number with such property is larger than 79*79 > 1000.
algorithm: 
	- generate primes from 1 to 3*10^6
	- loop through all a's and prime b's
	- go b's from the largest b and stop when Nmax > b
	
*/

using namespace std;
bool isprime(int i) {
	for (int j = 2; j < i; j++) {
		if (i % j == 0) 
			return false;
	}   
	return true;
}

void print_vector(vector<int> vc) { 
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << endl;
}

long long get_length(int a, int b) {
	long long n = 0;
	while (isprime(abs(n*n + a*n + b))) {
		//cout << n*n + a*n + b << "; ";
		n++;
	}
	//cout << endl;
	return n;
}

bool verify_answer(long long a, long long b, long long lng) {
	cout << "a: " << a << "; b = " << b << ": ";
	for (int cnt = 0; cnt < lng; cnt++) {
		if (!isprime(cnt*cnt + a*cnt + b)) {
			cout << "num = " << cnt*cnt + a*cnt + b << " in "<< cnt << "th position is not prime. Declared lng is " << lng << endl;
			return false;
		}
	}
	if (isprime(lng*lng + a*lng + b)) {
			cout << "number of primes sequence is larger than reported" << endl;
			return false;
		}
	cout << "verification is successfully passed" << endl;
	return true;
}

int main ()  {
	vector<int> primes;
	for (int i = 2; i < 1000; i++) {
		if (isprime(i)) {
			primes.push_back(i);
		}
	}
	print_vector(primes);
	
	long long amax, bmax, maxcons, cnt;
	maxcons = 0;
	cout << primes.size() << endl;
	for (long long bi = 0; bi < primes.size(); bi++ ) {
		cout << "b = " << primes[bi] << endl;
		for (long long a = -999; a <= 999; a+=2) {
			cnt = 0;
			int lng = get_length(a,primes[bi]);
			if (lng > maxcons) {
				maxcons = lng;
				amax = a; bmax = primes[bi];
			}
			lng = get_length(a,-primes[bi]);
			if (lng > maxcons) {
				maxcons = lng;
				amax = a; bmax = -primes[bi];
			}
		}
	}
	cout << "amax = " << amax << "; bmax = " << bmax << "; maxcons = " << maxcons << endl;
	verify_answer(amax,bmax,maxcons+1);
	cout << "answer = " << amax*bmax << endl;
	cout << "get_length(-61, 971) = " << get_length(-61, 971) << endl;
	cout << "get_length(-999, 61) = " << get_length(-999, 61) << endl;
}
