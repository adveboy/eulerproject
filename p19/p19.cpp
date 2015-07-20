#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
 
int day_of_week(int year, int month, int day) {
    // Using the Gaussian algorithm
	int d = day;

	double m = (double) ((month - 3) % 12 + 1);
	int Y;
	if(m > 10) Y = year - 1;
	else Y = year;
	int y = Y % 100;
	int c = (Y - (Y % 100)) / 100;
	int w = ((d+(int)floor(2.6*m-0.2)+y+ y/4 + c/4 -2*c))%7;
	return w; 
}
 
long months_start_range(int day, int year_start, int year_end) {
/*
	day = 0, it is sunday !
*/
	unsigned long total = 0;
	int year, month;
	for(year = year_start; year < year_end; year++) {
		for(month = 1; month <= 12; month++) {
			cout << "day_of_week: " << day_of_week(year, month, 1) << endl;
			if(day_of_week(year, month, 1) == day) total++;
		}
	}
	return total;
}
 
int main(int argc, char **argv) {

 	int iter = 0;
	long total;
	
	total = months_start_range(0,1901,1902);
	printf("Solution: %ld\n",total);
	
	for (int cnt = 1; cnt <= 7; cnt++) 
		cout << day_of_week(1901,1,cnt) << endl;
	cout << day_of_week(1901,1,1) << endl;
	return 0;
}