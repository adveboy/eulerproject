#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <map>
#include <math.h> 
#include <tgmath.h> 

using namespace std;
typedef map<long long, long long>::const_iterator MapIterator;

long long chain_length(long long startpoint, map<long long,long long> &lng_hist) {
	long long curr_num = startpoint, length = 0; 
	vector<long long> path;
	cout << "path: " << startpoint;
	do {
		if (lng_hist.find(curr_num) != lng_hist.end()) {
			
			break;
		} else {
		//new way
			path.push_back(curr_num);
			if (curr_num % 2 == 0) 
				curr_num = curr_num/2;
			else
				curr_num = curr_num*3 + 1;
			cout << "->" << curr_num;
		}
	} while (curr_num != 1);
	long long curr_length;
	if (curr_num == 1) {
		curr_length = 1;
	} else {
		curr_length = lng_hist[curr_num];
		cout << "(already known), distance from here is " << lng_hist[curr_num] << endl;
	}
	cout << endl;
	
	// fill the way we passed
	for (long long cnt = path.size() - 1; cnt >= 0; cnt--) {
		curr_length++;
		lng_hist[path[cnt]] = curr_length;
	}
	
	return curr_length;
}

void show_map(map<long long, long long> m) {
	cout << "Currently map looks like that: " << endl;
	for (MapIterator iter = m.begin(); iter != m.end(); iter++) {
		cout << "From " << iter->first << " distance is " << iter->second << endl;
	}
}
/*
	in case we want to do it faster:
		remember former steps and give it a 
*/

int main () {
	map<long long,long long> lng_hist;
	
	long long max_length = -1, curr_length, num_max;
	for (long long cnt = 2; cnt < 200000; cnt++) {
		cout << "cnt = " << cnt << endl;
		curr_length = 0; curr_length = chain_length(cnt, lng_hist);
		if (curr_length > max_length) {
			max_length = curr_length;
			num_max = cnt;
		}
		show_map(lng_hist);
	}
	cout << "lng_hist.size() = " << lng_hist.size() << endl;
	cout << "max length " << max_length << " achieved starting from " << num_max << endl;
	
	
	cout << "trying to calculate at 4" << endl;
	cout << "length is " << chain_length(4, lng_hist) << endl;
	
	
	/*
	cout << "chain length is " <<  chain_length(13, lng_hist) << endl;
	cout << "chain length is " <<  chain_length(26, lng_hist) << endl;
	cout << "chain length is " <<  chain_length(40, lng_hist) << endl;
	*/
}