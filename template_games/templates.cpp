#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/*
	template <class VARIABLE_NAME> class 
*/

template <class A_Type> class calc {
	public:
		A_Type multiply(A_Type x, A_Type y);
		A_Type add(A_Type x, A_Type y);
};

template <class A_Type> A_Type calc<A_Type>::multiply(A_Type x,A_Type y) {
	return x*y;
}

template <class A_Type> A_Type calc<A_Type>::add(A_Type x, A_Type y) {
	return x+y;
}

int main() { 
	calc <int> a_calc_class;
	cout << a_calc_class.add(10.1,15.2) << endl;
	return 0;
}