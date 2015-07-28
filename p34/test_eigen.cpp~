#include <iostream>
// #include <eigen3/Eigen/Dense>
#include "eigen3/Eigen/Dense"
using namespace std;
using namespace Eigen;
#include <math.h>       /* (long)pow */
#include <vector>

long long op(long long n) {
	long long sum = 1; long long tmp = 1;
	for (int i=1; i<=10; i++)  {
		tmp *= n;
		if (i%2 == 0)
			sum += tmp;
		else
			sum -= tmp;
	}
	return sum;
	// equivalent formulation: 
	// return (1 - n + (long)pow(n, 2.0) - (long)pow(n, 3.0) + (long)pow(n, 4.0) - (long)pow(n, 5.0) + (long)pow(n, 6.0) - (long)pow(n, 7.0) + (long)pow(n, 8.0) - (long)pow(n, 9.0) + (long)pow(n, 10.0));
}

long op1(int n) {
	return (long)pow(n,3);
}

void print_vector(vector<long long> vc) {
	for (std::vector<long long>::const_iterator i = vc.begin(); i != vc.end(); ++i)
		std::cout << *i << ' ';
}

long long P(vector<long long> x, vector<long long> y, int n_next) {
	long long sum = 0;
	for (int k=0; k<x.size(); k++) {
		long long nom = 1, den = 1;
		for (int j=0; j<x.size(); j++) {
			if (j != k) {
				nom *= (n_next-x[j]);
				den *= (x[k]-x[j]);
			}
		}
		sum += y[k]*nom/den;
	}
	return (long long)sum;
}


int main() {
	long long sum = 0;
	for (int i=1; i<=10; i++) {
		vector<long long> x(i),y(i);
		for (int cnt=0; cnt<i; cnt++) {
			x[cnt] = cnt+1;
			y[cnt] = op(cnt+1);
		}
		sum += P(x,y,i+1);
	}
	cout << "The answer is "<< sum << endl;
	return 0;
}

