#include <iostream>
#include <typeinfo>

// #define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;
const int size = 10;
int ia[size];

template <typename T>
	T min(T a, T b) {
		return ((a) < (b) ? (a) : (b));
	} 

int main() {
	int elem_cnt = 0;
	int *p = &ia[0]; // p is a pointer to ia
	cout << "p is " << typeid(p).name() << '\n';
	cout << "ia is " << typeid(ia).name() << '\n';
	cout << "&ia[size] = " << &ia[size] << endl;
	/*
	while ( min(p++, &ia[size]) != &ia[size] )
		++elem_cnt;
	*/
	cout << "elem_cnt : " << elem_cnt << "\texpecting: " << size << endl;
	return 0;
}