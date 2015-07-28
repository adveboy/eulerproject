#include <iostream>
#include <gmp.h>
#include <set>

using namespace std;

int main (int argc, char **argv) {
	MP_INT a,b,c;
	mpz_init(&c);
	mpz_init_set_str(&a, "1", 10);
	mpz_init_set_str(&b, "2", 10);
	do  {
		mpz_add(&c, &a, &b);
//		mpz_set (&a, &b);			
	} while (true);
	return 0;
}
