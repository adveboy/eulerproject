#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SS {
	int sum;
	int elems;
};

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {
	vector<size_t> idx(v.size());
	for (size_t i = 0; i != idx.size(); ++i) 
		idx[i] = i;
	sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

	return idx;
}

bool test_i(vector<SS> ss) {
	vector<int> sums(ss.size());
	// extract sums
	for (int cnt = 0; cnt < ss.size(); cnt++) {
		sums[cnt] = ss[cnt].sum;
	}
	int sizecurr = sums.size();
	sort(sums.begin(),sums.end());
	sums.erase(unique(sums.begin(), sums.end()), sums.end());
	return (sizecurr == sums.size());
}

bool test_ii(vector<SS> ss) {
	// extract elemsnum
	vector<int> elemsnum(ss.size());
	for (int cnt = 0; cnt < ss.size(); cnt++) {
		elemsnum[cnt] = ss[cnt].elems;
	}
	
	vector<size_t> getix = sort_indexes(elemsnum);
	
	// extract sums
	vector<int> sums(ss.size());
	for (int cnt = 0; cnt < ss.size(); cnt++) {
		sums[cnt] = ss[cnt].sum;
	}
	
	int curr_elem_num = 0; 
	int min = -1, max = -1, min_old, max_old;
	for (int cnt = 0; cnt < getix.size()-1; cnt++) {
		if (elemsnum[getix[cnt]] > curr_elem_num) {

  			curr_elem_num = elemsnum[getix[cnt]];
			min_old = min; max_old = max;
			max = -1; min = 1000;
		}

		if (sums[getix[cnt]] > max) {
			max = sums[getix[cnt]];
		}
		if (sums[getix[cnt]] < min) {
			min = sums[getix[cnt]];
		}

		if (max_old > min) {
			return false;
		}
	}

	
	return true;
}

void print_array(vector<int> arr) {
	for (int cnt = 0; cnt < arr.size(); cnt++) {
		cout << arr[cnt] << " ";
	}
	
	cout << endl;
}

int incr(vector<int> &vc, int max, int min) {
	int pos = vc.size()-1;
	while (vc[pos] == max)
		pos--;
	if (pos < 0)
		return -1;
	else {
		vc[pos] = vc[pos]++;
		for (int cnt = pos + 1; cnt < vc.size(); cnt++) {
			vc[cnt] = min;
		}
		return 0;
	}
}


vector<SS> sumelems(vector<int> arr) {
	vector<SS> ss;
	vector<int> pres(arr.size());
	for (int cnt = 0; cnt < arr.size(); cnt++) {
		pres[cnt] = 0;
	}
	while (incr(pres,1,0) != -1) {
		SS e; e.elems = 0; e.sum = 0;
		for (int cnt = 0; cnt < pres.size(); cnt++) {
			if (pres[cnt] == 1) {
				e.sum += arr[cnt];
				e.elems++;
			}
		}
		ss.push_back(e);
	}
	return ss;
}

vector<int> generate_start(vector<int> prev) {
	vector<int> near_opt(prev.size() + 1);
	int b = prev[prev.size()/2];
	near_opt[0] = b;
	for (int cnt = 1; cnt < near_opt.size(); cnt++) {
		near_opt[cnt] = b + prev[cnt-1];
	}
	return near_opt;
}

vector<int> sum(vector<int> &v1, vector<int> &v2) {
	vector<int> vc(v1.size());
	for (int cnt=0; cnt<v1.size(); cnt++) {
		vc[cnt] = v1[cnt] + v2[cnt];
	}
	return vc;
}

int S(vector<int> vc) {
	int sum = 0;
	for (int cnt=0; cnt<vc.size(); cnt++) {
		sum += vc[cnt];
	}
	return sum;
}

void print_ss(vector<SS> ss) {
	for (int cnt = 0; cnt < ss.size(); cnt++) {
		cout << "sum = " << ss[cnt].sum << "; elems = " << ss[cnt].elems << endl;
	}
}

bool equal(vector<int> v1, vector<int> v2) {
	for (int cnt=0; cnt<v1.size(); cnt++) {
		if (v1[cnt] != v2[cnt])
			return false;
	}
	return true;
}

int main (int argc, char **argv) {
	int start[] = {11, 18, 19, 20, 22, 25};
//	int start[] = {6, 9, 11, 12, 13};
	vector<int> stvect(start, start + sizeof(start) / sizeof(int));
	vector<int> lst = generate_start(stvect);
	cout << "start from: "<< endl;
	print_array(lst);
	int add[] = {-3,-3,-3,-3,-3,-3,-3};
	vector<int> addv(add, add + sizeof(add) / sizeof(int));
	int min_sum = 100000;
	vector<int> min_vector;
	vector<SS> sss = sumelems(lst);
	do {
		vector<int> cand = sum(lst,addv);
		vector<SS> ss = sumelems(cand);
		if (test_i(ss) && test_ii(ss) && (S(cand) < min_sum)) {
			print_array(cand);
			min_sum = S(cand);
			min_vector = cand;
		}
	} while (incr(addv,3,-3) != -1);
	vector<SS> ss = sumelems(lst);
	cout << "answer: " << endl;
	print_array(min_vector);
	return 0;	
}
