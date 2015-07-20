#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 
#include <ctime>

using namespace std;

vector<long> num2cyp(long num) {
	vector<long> vc;
	while (num > 0) {
		vc.push_back(num%10);
		num = num/10;
	}
	return vc;
}

/*
	that was a very bad solution 
*/

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
	for(long n = 2; n <= sqrt(num); n++){
		if(num % n == 0){
			prime = false;
			break;
		}
	}
	return prime;
}

int main () {
	bool prime;
	
	clock_t begin = clock();
	
	long count_size = 0, d = 10;
	long N = 1000000;
	bool roundprime[N+1];
	roundprime[0] = false;
	roundprime[1] = false;
	for (int i = 2; i < N; i++) {
		roundprime[i] = true;
	}
	int total_roundprimes = 0;
	long num;
	int rounds = 0; 
	long mul = 1;
	for (long i = 2; i <= N; i++){
		// cout << "i = " << i <<  endl;
		if (i%(10*mul) == 0) {
			rounds++; mul*=10;
		}
		if (roundprime[i]) {
			num = i;
			if (!isprime(i)) {
				// cout << "let's delete elements by circle for i = " << i <<  endl;
				roundprime[i] = false; 
				// cout << "number of rounds = " << rounds << endl;
				for (int k = 0; k < rounds; k++) { 	
					// cout << "mul = " << mul << endl;
					if (num%10 != 0) {
						num = (num%10)*mul + num/10;
						// cout << "num = " << num <<  endl;
						roundprime[num] = 0;
					} else {
						num = (num%10)*mul + num/10;
					}
					
				}
			}
		}
	}
	
	for (int cnt = 0; cnt<N; cnt++) {
		if (roundprime[cnt]) {
			cout << cnt << " ";
			total_roundprimes++;
		}
	}
	cout << endl;
	
	cout << "total roundprimes found " << total_roundprimes << endl;
	double elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;
	cout << "primes are found at " << elapsed_secs << endl;
	
	
	
	/*
	bool roundprime = false;
	long total_roundprimes = 0;
	
	for(long i = 2; i <= N; i++){
		if (i % d == 0) {
			// cout << "inside if" << endl;
			count_size++;
			d*=10;
		}
		num = i;
		
		cout << "---------------------------------------------" << endl;
		cout << "count_size = " << count_size << endl;
		cout << "num = " << num << endl;
		
		if (primes[i]) {
			roundprime = true;
			for (int cnt = 0; cnt < count_size; cnt++) {
				num = num/10 + (num % 10)*long(pow(10, count_size));
				if (!primes[num]) {
					roundprime = false;
					break;
				}
		//		cout << "num = " << num << endl;
			}
			if (roundprime)
				total_roundprimes++;
				
		}
		// cout << "---------------------------------------------" << endl;
	}
	
	cout << "total roundprimes " << total_roundprimes << endl;
	elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;
	cout << "roundprimes are found at " << elapsed_secs << endl;
	*/
}