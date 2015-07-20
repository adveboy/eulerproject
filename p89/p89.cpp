/*
algorithm:
	- read the file
	- translate into decimal number
		IX, IV, XL, XC, CD, CM are to be processed separately
		
	- create the shortest combination from decimal
	
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 
#include <ctime>
#include <unordered_map>
#include <string>
#include <fstream>


x
using namespace std;
typedef std::unordered_map<string, int>  Map_cyp; 
typedef std::unordered_map<int, string>  Map_cyp_back; 
Map_cyp subst ({{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}});
Map_cyp_back subst_back ({{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"}, {1000,"M"}, {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}});
int subst_vals [] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
 
int parse_string(string str) {
	int sum = 0; int cnt = 0;
	while (cnt < str.size()) {
		if (subst.find(str.substr(cnt,2)) == subst.end() || cnt == str.size()-1) {
			sum += subst[str.substr(cnt,1)];
			cnt++;
		} else {
			sum += subst[str.substr(cnt,2)];
			cnt +=2;
		}
	}
	return sum;
}

string repeat( const std::string &word, int times ) {
	std::string result ;
	result.reserve(times*word.length()); // avoid repeated reallocation
	for ( int a = 0 ; a < times ; a++ ) 
	result += word ;
	return result ;
}

string generate_min(int num) {
	string latin = "";
	int quant; 
	while (num > 0) {
		int pos = (sizeof(subst_vals)/sizeof(*subst_vals)) - 1;
		while (subst_vals[pos] > num) {
			pos--;
		}
		quant = num/subst_vals[pos];
		num -= quant*subst_vals[pos];
		latin += repeat(subst_back[subst_vals[pos]], quant);
	}
	return latin;
}

int main () {
	ifstream infile("p089_roman.txt");
	string a, anew;
	int sum = 0;
	while (infile >> a ) {
		anew = generate_min(parse_string(a));
		sum += a.length() - anew.length();
	}
	cout << "final difference is " << sum << endl;
	return 0;
}	