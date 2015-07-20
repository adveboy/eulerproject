#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
	long long a = 1, b = 2, tmp;
	long long sum = 2; //even
	for (;;) {
		tmp = b;
		b = a + b;
		a = tmp;
		if (b >= 4000000) break;
		//cout << b << endl;
		// usleep(100000);
		if (b%2 == 0) {
			sum += b;
		}
	}
	cout << sum << endl;
	return 0;
}