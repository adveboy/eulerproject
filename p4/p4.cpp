#include <iostream>
#include <unistd.h>
#include <iostream>
#include <list>   
#include <iterator> 
#include <unistd.h>
#include <sstream>
using namespace std;

string reversestring(string str) {
	string ans = str;
	// cout << str.length() << endl;
	for (int cnt=0; cnt < str.length(); cnt++) {
		ans[cnt] = str[str.length()-cnt-1];
	}
	return ans;
}

int findmax(list<int> myList) {
	int max = 0;
	list<int>::const_iterator iterator;
	for (iterator = myList.begin(); iterator != myList.end(); ++iterator) {
	    if (*iterator > max) 
		max = *iterator;
	}
	return max;
}

int main() {
	// cout << reversestring("hello") << endl;
	list<int> myList;
	for (int i=100; i<999; i++) {
		for (int j=100; j<999; j++) {
			int num = i*j;
			ostringstream temp;  //temp as in temporary
			temp << num;
			string str = temp.str();
			string rev = reversestring(str);
			if (!str.compare(rev)) {
				// cout << "original string = " << str << endl;
				myList.push_back(num);
			}
			// cout << str << endl;
			// usleep(100000);
			//check if this is palyndrom
			//first check if the 
			
		}
	}
	cout << "max palindrom is " << findmax(myList) << endl;
	// cout << "max divisor is " << lastdiv << endl;
	
	return 0;
}