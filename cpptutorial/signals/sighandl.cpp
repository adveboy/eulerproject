#include <iostream>
#include <csignal>
#include <cstdlib>
#include <time.h>

using namespace std;

void signalHandler( int signum ) {
	cout << "Interrupt signal (" << signum << ") received.\n";
	// cleanup and close up stuff here  
	// terminate program  
	exit(signum);  
}

 

void sleep( time_t delay )  { 
	time_t timer0, timer1; 
	time( &timer0 ); 
	do { 
		time( &timer1 ); 
	} while (( timer1 - timer0 ) < delay ); 
}

int main () {
	// register signal SIGINT and signal handler  
	signal(SIGINT, signalHandler);  
	while(1){
		cout << "Going to sleep...." << endl;
		sleep(1500); 
	}
	return 0;
}