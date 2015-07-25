#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

template <size_t N>
void splitString(string (&arr)[N], string str) {
	int n = 0;
	istringstream iss(str);
	for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		arr[n] = *it;
}

int main() {
	string line = "test one two    three.";
	string arr[4];
	splitString(arr, line);
	for (int i = 0; i < 4; i++)
		cout << arr[i] << endl;
}


