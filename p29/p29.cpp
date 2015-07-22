#include <vector>
#include <iostream>
#include <stdlib.h>     /* abs */
#include <set>

/*
b should be prime because n*n + a*n + b = n(n + a) + b is prime for all n = 0 to Nmax. We know that n*n-79n+1601 generates consecutive primes from 0 to 79. we are interested in a,b where number of generated primes i more than 79. if so, b doesn't have divisors less than 80
but minimal number with such property is larger than 79*79 > 1000.
algorithm: 
	- generate primes from 1 to 3*10^6
	- loop through all a's and prime b's
	- go b's from the largest b and stop when Nmax > b
	
*/

using namespace std;

template <class X> void print_set(set<X> st) { 
	typename set<X>::iterator iter;
	for(iter = st.begin(); iter != st.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;
}

int main ()  {
	set<int> setss;
	int kmax = 3;
	
	for (int cnt = 1; cnt <= 100; cnt++) {
		for (int k = 2; k <= kmax; k++) {
			if (setss.find(k*cnt) != combs.end()) {
				cout << k*cnt << " is already in the list: a = " << i << "; b = " << j << endl;
			}
			set2.insert(k*cnt);
		}
	}

	set<int> set2;
	int kmax = 3;
	for (int cnt = 1; cnt <= 2; cnt++) {
		for (int k = 2; k <= kmax; k++) {
			set2.insert(k*cnt);
		}
	}
	print_set(set2);
	int num2 = set2.size();
	cout << set2.size() << endl;	
	for (int cnt = 3; cnt <= 3; cnt++) {
		for (int k = 2; k <= kmax; k++) {
			set2.insert(k*cnt);
		}
	}
	cout << "set2.size() = " << set2.size() << endl;	
	print_set(set2);
	int num3 = set2.size();
	for (int cnt = 4; cnt <= 4; cnt++) {
		for (int k = 2; k <= kmax; k++) {
			set2.insert(k*cnt);
		}
	}
	int num4 = set2.size();
	cout << set2.size() << endl;
	for (int cnt = 5; cnt <= 6; cnt++) {
		for (int k = 2; k <= kmax; k++) {
			set2.insert(k*cnt);
		}
	}
	int num6 = set2.size();
	cout << set2.size() << endl;	
	print_set(set2);
	cout << "result is " << 2 * (99 - (6*2 + 3 + 4 + 6)) + num6 + num4 + num3 + num2*6 << endl;
	set<int> set0;
	
	for (int cnt = 1; cnt <= 5; cnt++) {
		for (int k = 2; k <= 5; k++) {
			set0.insert(k*cnt);
		}
	}
	
	cout << "-------------------------" << endl;
	long long a = 100, b = 3;
	set<long long> combs;
	for (long long i = 2; i <= a; i++) {
		long long prod = i;
		for (long long j = 2; j <= b; j++) {
			prod *= i;
			if (combs.find(prod) != combs.end()) {
				cout << prod << " is already in the list: a = " << i << "; b = " << j << endl;
			}
			combs.insert(prod);
		}
		int ins;
	}
	cout << "combs.size() = " << combs.size() << endl;
	cout << "-------------------------" << endl;	
	print_set(combs);
}
