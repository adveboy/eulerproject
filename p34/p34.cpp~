#include <vector>
#include <iostream>
#include <stdlib.h>     /* abs */
#include <set>
#include <math.h>       /* pow */
#include <vector>       /* pow */

using namespace std;
vector<int> vc(10);

int factorial(int a) {
	int prod = 1;
	for (int i = 2; i <= a; i++) {
		prod *= i;
	}
	return prod;
}

bool check_number(long x) {
	long tmp = x; long sum = 0;
	while (tmp > 0) {
		sum += vc[tmp%10];
		tmp = tmp/10;
	}
	return (x == sum);
}

int main() {
	vc[0] = 1; vc[1] = 1; vc[2] = 2;
	for (int i = 3; i <= 9; i++) {
		vc[i] = factorial(i);
	}
	for (int cnt = 3; cnt <= 10000000; cnt++) {
			if (check_number(cnt))
			cout << cnt << endl;
	}
}
