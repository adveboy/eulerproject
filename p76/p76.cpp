#include <iostream>

using namespace std;

int main () {
	int target = 100;
	int ways[target + 1];;
	ways[0] = 1;
	 
	for (int i = 1; i <= 99; i++) {
	    for (int j = i; j <= target; j++) {
		ways[j] += ways[j - i];
	    }
	}
	cout << ways[99] << endl;
}