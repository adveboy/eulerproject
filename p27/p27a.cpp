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

vector<int> primes;

bool isprime(int i) {
	for (int j = 2; j < i; j++) {
		if (i % j == 0) 
			return false;
	}   
	return true;
}


bool isPrime(int testNumber) {
	int i = 0;
	while (primes[i] <= testNumber) {
		if (primes[i] == testNumber) {
	    		return true;
		}
		i++;
	}
	return false;
}


int main ()  {
	cout << "adding prime" << endl;
	for (int i = 2; i < 87400; i++) {
		if (isprime(i)) {
			// cout << "adding prime" << endl;
			primes.push_back(i);
		}
	}
	
	int aMax = 0, bMax = 0, nMax = 0;
	for (int a = -1000; a <= 1000; a++) {
		// cout << "a = " << a << endl;
		for(int b = -1000; b <= 1000; b++) {
			int n = 0;
			while (isPrime(abs(n * n + a * n + b))) {
				    n++;
			}
			if (a == -999 && b == 61) {
				cout << "a == -999; b == 61; n * n + a * n + b = " << n * n + a * n + b << endl;
			}

			if (n > nMax) {
				aMax = a;
				bMax = b;
				nMax = n;
			}
		}
	}
	
	cout << "aMax = " << aMax << "; bMax = " << bMax << "; nMax = " << nMax << endl;
}


