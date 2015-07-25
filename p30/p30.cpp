#include <vector>
#include <iostream>
#include <stdlib.h>     /* abs */
#include <set>
#include <math.h>       /* pow */

using namespace std;
long get_sum5(long num, int powv) {
	int r;
	long sum = 0;
	while (num > 0) {
		sum +=  (int) pow ((num % 10), powv);
		num = (int) num / 10;
	}
	return sum;
}

int main() {
// 	cout << get_sum5(1634,4) << endl;
	long totalsum = 0;
	for (long cnt = 2; cnt < 1000000; cnt++) {
		if (get_sum5(cnt,5) == cnt) {
			totalsum += cnt;
		}
	}
	cout << totalsum << endl;
}
