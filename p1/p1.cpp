#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int cnt = 1; cnt < 1000; cnt++) {
		if (cnt % 5 == 0 || cnt % 3 == 0 || cnt % 15 == 0) {
			cout << cnt << " ";
			sum += cnt;
		}
		/*
		if (cnt % 15 == 0) {
			cout << cnt << " ";
			sum += cnt;
		}
		*/
	}
	cout << sum << endl;
	return 0;
}