#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
	long long number = 600851475143L;
	int lastdiv;
	while (number > 1) {
		//cout << "inside loop while" << endl;
		for (long i = 2; i <= number; i++) {
			//cout << "inside loop" << endl;
			if (number % i == 0) {
				cout << "divisor = " << i << "; ";
				cout << "number = " << number << endl;
				cout << number << endl;
				number = number / i;
				lastdiv = i;
				break;
			}
		}
	}
	cout << "max divisor is " << lastdiv << endl;
	return 0;
}