#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;
// using std::ifstream;



const int MAX_CHARS_PER_LINE = 50000;
const int MAX_TOKENS_PER_LINE = 50000;
const char* const DELIMITER = ",";

int main() {
	// create a file-reading object
	ifstream fin;
	fin.open("p022_names.txt"); // open a file
	if (!fin.good()) 
		return 1; // exit if file not found

	// read each line of the file
	while (!fin.eof()) {
		// read an entire line into memory
		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);
//		cout << "/" << buf << endl;
//		cout << "_" << buf << "_" << endl;
// 		break;
		// parse the line into blank-delimited tokens
		int n = 0; // a for-loop index

		// array to store memory addresses of the tokens in buf
//		const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
		string token[MAX_TOKENS_PER_LINE];
		string tmp;		
		
		// parse the line
		// parse the line		
//		cout << "token length = " << sizeof(token)/sizeof(*token) << endl;

		
		const char *tm = strtok(buf, DELIMITER);
		const char *s = "Hello, World!";
		cout << "tm = " << tm << endl;
		if (tm == NULL)
			cout << "tm = NULL" << endl;
		else
			cout << "string(tm) = " << string(tm) << endl;
			
		string str(tm);
//		cout << "str = " << str << endl;
		
		//token[0] = string(); // first token
		if (token[0].length()) { // zero if line is blank
			for (n = 1; n < MAX_TOKENS_PER_LINE; n++) {
//				tmp = string(strtok(0, DELIMITER)); // subsequent tokens
//				cout << "tmp = " << tmp << endl;
//				cout << "tmp reduced = " << (tmp.substr(1,tmp.length()-2)) <<  endl;
//				token[n] = tmp.substr(1,tmp.length()-2);
//				if (!token[n].length()) break; // no more tokens
			}
		}
		cout << "preved" << endl;
		// process (print) the tokens
		for (int i = 0; i < n; i++) { // n = #of tokens 
			cout << "Token[" << i << "] = " << token[i] << endl;
		}
		cout << endl;
	}
}
