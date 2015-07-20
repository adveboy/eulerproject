#include <iostream>

using namespace std;

long long int BigInteger Squareroot(int n, int digits) {
    BigInteger limit = BigInteger.Pow(10, digits + 1);
    BigInteger a = 5 * n;
    BigInteger b = 5;
    while (b < limit) {
        if (a >= b) {
            a -= b;
            b += 10;
        } else {
            a *= 100;
            b = (b/10) * 100 + 5;
        }
    }
    return b/100;
}

int main () {
	
}
