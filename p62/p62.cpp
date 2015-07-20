#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

bool check_root3(int num) {
	int root = (int)(cbrt(num));
	return ((int)(pow(root,3)) == num);
}

long double fact(int N) {
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}

vector<int> decompose_number(int num) {
	vector<int> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	return digits;
}

int compose_number(vector<int> digits) {
	int num = 0;
	for (int cnt = digits.size() -1; cnt >= 0; cnt--) {
		num = 10*num + digits[cnt];
	}
	return num;
}

void output_vector(vector<int> vc) {
	cout << "--------------output_vector--------------" << endl;
	for (int cnt = vc.size()-1; cnt >= 0; cnt--) {
		cout << vc[cnt] << " ";
	}
	cout << endl; 
	cout << "--------------/output_vector--------------" << endl;
}

bool myfunction (int i, int j) {
	return (i == j);
}


void another_test() {
	int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
	std::vector<int> myvector (myints,myints+9);
	// using default comparison:
	std::vector<int>::iterator it;
	it = std::unique(myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
	myvector.resize(std::distance(myvector.begin(), it)); // 10 20 30 20 10
	// using predicate comparison:
	std::unique(myvector.begin(), myvector.end(), myfunction);   // (no changes)
	// print out content:
	std::cout << "myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}


void delete_same(vector<int> &vec) {
	/*
	sort(vc.begin(), vc.end());
	output_vector(vc);
	cout << "vc.end() - vc.begin(): " << vc.end() - vc.begin() << endl;
	vector<int>::iterator it = unique(vc.begin(), vc.end());;
	vc.resize(std::distance(vc.begin(),it)); 
	cout << "it - vc.begin(): " << it - vc.begin() << endl;
	*/
	sort(vec.begin(), vec.end());
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
	cout << "delete_same::vec.size() = " << vec.size() << endl;
	// output_vector(vc);
}

void test_vector() {
	// here we test unique function
	vector<int> vc;
	vc.push_back(2); vc.push_back(1); vc.push_back(3); vc.push_back(3);
	cout << "vc.size() before sort operation is " << vc.size() << endl;
	cout << "------------------------------" << endl;
	cout << "before unique operation " << endl;
	output_vector(vc);
	vector<int>::iterator it = unique(vc.begin(), vc.end());;
	vc.resize(std::distance(vc.begin(),it)); 
	cout << "after unique operation " << endl;
	output_vector(vc);
	cout << "vc.size() after sort and before unique operation is " << vc.size() << endl;
	cout << "------------------------------" << endl;
}

int main() {
	cout << check_root3(28) << endl;
	/*
	string xss = NumberToString(42);
	char xs[] = "123";
	while (next_permutation(xs, xs + sizeof(xs) - 1)) {
		cout << xs << endl;
	}
	cout << "s = " << xs << endl;
	*/
	vector<int> allperms;
	cout << "vector from the scratch " << endl;
	// output_vector(allperms);
	int num = 1;
	while (true) {
		int tmp = 0;
		vector<int> vc = decompose_number(num);
		//cout << "initial number = " << num << endl;
		// cout << "number of permutations: " << fact(vc.size()) << endl;
		sort(vc.begin(),vc.end());
		// output_vector(vc);
		int cubes_num = 0;
		// for (int cnt = 0; cnt < fact(vc.size()); cnt++) {
		do {
			tmp = compose_number(vc);
			allperms.push_back(tmp);
			// cout << "new num " << tmp << endl;
			if (check_root3(tmp)) {
				// cout << tmp  << "'s cubic root is " << (int)cbrt(tmp) << endl;
				cubes_num++;
			}
		} while (next_permutation(vc.begin(), vc.end()));
		
		if (cubes_num == 3) {
			break;
		}
		if (cubes_num != 0)
			cout << cubes_num << endl;
		
			cout << num << endl;
		num++;
	}
	cout << "num = " << num << endl;
	//}
	
	/*
		cout << "allperms size before " << allperms.size() << endl;
		delete_same(allperms);
		cout << "allperms size after " << allperms.size() << endl;
		
		int myints[] = {10,20,20,20,30,30,20,20,10};
		std::vector<int> myvector (myints,myints + 9);
		cout << "main::myvector.size() = " << myvector.size() << endl;
		delete_same(myvector);
		cout << "main::myvector.size() = " << myvector.size() << endl;
	*/
	
	// output_vector(allperms);

	/*
		cout << "vector size: " << allperms.size() << endl;
		test_vector();
		another_test();
	*/

	// delete_same(allperms);
	// output_vector(allperms);

	/*
		int myints[] = {10,20,20,20,30,30,20,20,10};
		std::vector<int> myvector (myints,myints + 9);
		cout << "myvector before cleaning" << endl;
		output_vector(myvector);
		delete_same(myvector);
		cout << "myvector after cleaning" << endl;
		output_vector(myvector);
	*/
	
	/*
	cout << "allperms: ";
	for (int cnt = 0; cnt < allperms.size(); cnt++) {
		cout << allperms[cnt] << " ";
	}
	*/
	
	/*
		1) generate and check permutations
		2) loop until we have the desired output
		3) end
	*/
	return 0;
}