#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std ;

void  * function1(void * argument);
void  * function2(void * argument);

int main( void ) {
	pthread_t t1, t2 ; // declare 2 threads.
	pthread_create(&t1, NULL, function1, NULL); // create a thread running function1
	pthread_create(&t2, NULL, function2, NULL); // create a thread running function2
	//sleep(1);
	return 0;
}

void * function1(void * argument) {
	cout << " hello " << endl ;
	// sleep(2); // fall alseep here for 2 seconds...
	return 0;
}

void * function2(void * argument) {
	cout << " world "  << endl ;
	return 0;
}