#include <iostream>
#include <ctime>
#include <list>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	// int loopcircles = 0;
	unsigned int x;
	while (b) {
		// loopcircles++;
		x = a % b;
		a = b;
		b = x;
	}
	// cout << "loopcircles: " << loopcircles << endl;
	return a;
}

void showlist(list<int> int_list) {
	// cout << "listlength = " << int_list.size() << endl;
	for(list<int>::iterator list_iter = int_list.begin(); 
		list_iter != int_list.end(); list_iter++) {
		cout << *list_iter << " ";
	}
	cout << endl;
}

int main() {
	// relatively prime 
	clock_t start, tmp_clock;
	list<int> primes;
	double duration;
	start = clock(); tmp_clock = start;
	int phi; int val = -1;
	float mx = -1, tmp;

	for (int i = 1000000; i >= 2; i--) {
		phi = 0; 
		primes.clear();
		for (int j = 1; j < i ; j++) {
			if (gcd(i,j) == 1) {
				primes.push_back(j);
				phi++;
			}
		}
		// cout << "phi = " << phi << endl;
		
		/*
		cout << "------------------" << endl;
		cout << "primes: " ; showlist(primes);
		cout << "i = " << i << " phi = " << phi << " i/(phi) = " << (float)i/(float)phi << endl;
		*/
		
		tmp = (float)i/(float)phi;
		// cout << "phi = " << phi<< "; tmp = " << tmp << endl;
		if (mx < tmp) {	
			mx = tmp; val = i;
			// cout << "max changed" << endl;
		}
		duration = (clock() - tmp_clock) / (double) CLOCKS_PER_SEC;
		if (duration > 100) {
			tmp_clock = clock();
			cout << ((float)i/1000000)*100 << "% job left" << endl;
			// cout << ((1000000 - i)/1000000)*100 << "% job left" << endl;
		}
		
		/*
		if (i%100 == 0) {
			duration = (clock() - tmp_clock) / (double) CLOCKS_PER_SEC;
			tmp_clock = clock();
			cout << "time spent: " << duration << '\n';
		}
		*/
		//cout << "i = " << i << "i/(phi) = " << i/(phi);

	}
	cout << "------------------" << endl;
	cout << "val = " << val << " max = " << mx << endl;
	duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "time spent: " << duration << '\n';
	return 0;
}