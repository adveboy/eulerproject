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

template <class X> void testfun(set<X> st) { 
	typename set<X>::iterator iter = st.begin();
	cout << *iter << endl;
}

int main ()  {
	set<int> intset;
	intset.insert(123);
	set<string> strset;
	strset.insert("string");
	testfun(intset);
	testfun(strset);
//	testfun(a);
//	testfun(str);
	return 0;
}

