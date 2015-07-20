#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<long long int> decompose_number(long long int num) {
	vector<long long int> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	return digits;
}

long long int compose_number(vector<long long int> digits) {
	long long int num = 0;
	for (int cnt = digits.size() -1; cnt >= 0; cnt--) {
		num = 10*num + digits[cnt];
	}
	return num;
}

void output_vector(vector<long long int> vc) {
	cout << "--------------output_vector--------------" << endl;
	for (int cnt = 0; cnt < vc.size(); cnt++) {
		cout << vc[cnt] << " ";
	}
	cout << endl; 
	cout << "--------------/output_vector--------------" << endl;
}

int main() {
	unordered_map <long long int, int> m;
	unordered_map <long long int, vector<long long int>> n;
	vector<long long int> tmp; 
	long long int tmpnum, num = 0, cubic_val = 0;
	while (true) {
		cubic_val = pow(num,3);
		tmp = decompose_number(cubic_val);
		sort(tmp.begin(), tmp.end());
		tmpnum = compose_number(tmp);
		// cout << "tmpnum = " << tmpnum << endl;
		m[tmpnum]++;
		n[tmpnum].push_back(cubic_val);
		if (m[tmpnum] == 5) {
			// cout << "cubical val: " << cubic_val << endl;
			// cout << "nums should be here" << endl;
			output_vector(tmp);
			cout << "leave the loop" << endl;
			break;
		}
		num++;
	}
	cout << "result is " << n[tmpnum][0] << endl;
}
