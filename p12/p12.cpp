#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;

typedef map<int, int>::const_iterator MapIterator;

map<int,int> factorize_num(int num) {
	int res = 0;
	map<int,int> m;
	for ( int i = 2; i <= num; ++i ) {
		while ( num % i == 0 ) {
			if (m.find(i) == m.end()) {
				m[i] = 1;
			} else {
				m[i]++;
			}
			num /= i; res++;
		}
	}
	return m;
}

void show_map(map<int,int> m) {
	
	for (MapIterator iter = m.begin(); iter != m.end(); iter++) {
		cout << "Divisor: " << iter->first << endl << "Degree:" << iter->second << endl;
	}
}

int prod(map<int,int> m) {
	int pr = 1;
	for (MapIterator iter = m.begin(); iter != m.end(); iter++) {
		pr = pr * (iter->second + 1);
	}
	return pr;
}

int triangle(int n) {
	return n*(n+1)/2;
}

int divisors(int n) {
	return prod(factorize_num(n*(n+1)/2));
}

int main () {
	int N = 500;
	int cnt = 1;
	while (divisors(cnt) <= N)
		cnt++;
	cout << "first triangle with more than " << N << " divisors is " << triangle(cnt) << endl;
	
}