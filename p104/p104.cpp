#include <iostream>
#include <gmp.h>
#include <set>

using namespace std;
 
bool pandigital(string str) {
	set<char> st; 
	for (int i=0; i<str.size(); i++) {
		st.insert(str[i]);
	}
	st.erase('0');
	return (st.size() == 9);
}

int main (int argc, char **argv) {
	MP_INT a,b,c;
	mpz_init_set_str(&a, "1", 10);
	mpz_init_set_str(&b, "1", 10);
	mpz_init(&c);
	string str;
	int cnt = 0;
	do {
		mpz_add(&c,&a,&b);
		mpz_set(&b,&a);
		mpz_set(&a,&c);
		char *ch = mpz_get_str(NULL, 10, &c);
		str = string(ch);
		delete[] ch;
		if (str.size() >= 9) {
			if (pandigital(str.substr(0,9))) {
				cout << "first elems at " << cnt << endl;
				cout << "str.size() = " << str.size() << endl;
			}
			if (pandigital(str.substr(str.size()-9,9))) {
				cout << "last elems at " << cnt << endl;
			}
		}
		cnt++;
	} while (!(pandigital(str.substr(0,9)) && pandigital(str.substr(str.size()-9,9))));
	return 0;
}
