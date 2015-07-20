#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	unsigned int x;
	while (b) {
		x = a % b;
		a = b;
		b = x;
	}
	return a;
}

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {
	// initialize original index locations
	vector<size_t> idx(v.size());
	for (size_t i = 0; i != idx.size(); ++i) 
		idx[i] = i;
	// sort indexes based on comparing values in v
	sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });
	return idx;
}

vector<float> list_to_vector(list<float> lst) {
	vector<float> vct(0);
	copy(lst.begin(), lst.end(), back_inserter(vct));
	return vct;
}

void showlist(list<int> int_list) {
	// cout << "listlength = " << int_list.size() << endl;
	for(list<int>::iterator list_iter = int_list.begin(); 
		list_iter != int_list.end(); list_iter++) {
		cout << *list_iter << " ";
	}
	cout << endl;
}

void showvect(vector<float> vct) {
	for (std::vector<float>::const_iterator i = vct.begin(); i != vct.end(); ++i)
		std::cout << *i << ' ';
	cout << endl;
}

void showvect(vector<size_t> vct) {
	for (std::vector<size_t>::const_iterator i = vct.begin(); i != vct.end(); ++i)
		std::cout << *i << ' ';
	cout << endl;
}

void showlist(list<float> float_list) {
	for(list<float>::iterator list_iter = float_list.begin(); 
		list_iter != float_list.end(); list_iter++) {
		cout << *list_iter << " ";
	}
	cout << endl;
}

int main() {
	list<int> nlist;
	list<int> dlist;
	list<float> dvlist;

	//cout << "listlength = " << nlist.size() << endl;
	//showlist(nlist); 
	for (int d = 2; d <= 8; d++) {
		for (int n = 1; n < d - 1; n++) {
			if (gcd(n,d) == 1) {
				nlist.push_back(n);
				dlist.push_back(d);
				// cout << n/d << " ";
				dvlist.push_back((float)n/d);
			}
		}
	}
	//cout << "listlength = " << nlist.size() << endl;
	showlist(nlist); 
	showlist(dlist);
	showlist(dvlist);
	vector<float> vct = list_to_vector(dvlist);
	// vector<size_t> idxvect = 
	cout << "----------------------" << endl;
	showvect(vct);
	cout << "----------------------" << endl;
	
	cout << "vector size = " << vct.size() << endl;
	cout << "list size size = " << dvlist.size() << endl;
	dvlist.sort();
	
	vector<size_t> indexes = sort_indexes(vct);
	cout << "----------------------" << endl;
	cout << "indexes: " << endl;
	showvect(indexes);
	cout << "----------------------" << endl;
	
	showlist(dvlist);
	return 0;
}