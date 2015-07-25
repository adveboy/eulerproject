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


int get_size(int bmax, int reps) {
/*
	see example in p29:
	2^2, 2^3, ..., 2^5
	4^2, 4^3, ..., 4^5
	bmax here is 5 (max degree of a number), reps is 2 (2 and 4 are the issue)
*/
	set<int> st;

	cout << "bmax = " << bmax << "; reps = " << reps << endl;
	for (int k = 1; k <= reps; k++) {
		cout << "------------------------------------------------" << endl;
		for (int cnt = 2; cnt <= bmax; cnt++) {
			if (st.find(cnt*k) != st.end()) {
				cout << "k = " << k << "; cnt = " << cnt << endl;
			} else {
				st.insert(cnt*k);
			}
		}
	}
	return st.size();
}


int main() {
	int a = 100, b = 100;
	int res = (b-1) * (99 - (6 + 4 + 3 + 6*2)) + get_size(100,6) + get_size(100,4) + get_size(100,3) + get_size(100,2)*6;
	cout << "result is " << res << endl;
// 	cout << "result is " << get_size(100,3) << endl;
	//	cout << "result is " << 4*2 + get_size(5,2) << endl;
}
