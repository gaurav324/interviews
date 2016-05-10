//--- WARM-UP ---
//
//There is compressed string like this:
//3[abc]4[ab]c
//and we want to decompress it into form like this:
//abcabcabcababababc
//
//here number[string] decompresses to string written number times.

//--- POSSIBLE QUESTIONS FROM CANDIDATE ---
//
//Q. Does number can have more than one digit?
//-> yes
//10[a] is allowed and just means aaaaaaaaaa
//
//Q. Can one repetition be inside another one?
//-> yes
//For example 2[3[a]b] decompresses into aaabaaab
//
//Q. What characters are allowed as input?
//-> digits, small English letters and brackets [ ]
//Digits are only to represent amount of repetitions
//Letters are just letters
//Brackets are only part of syntax of writing repeated substring
//
//Q. Is input always valid?
//-> yes
//No need for checking anything.


// --- Follow up question ----
// 1) How to get the k-th letter of output?
// >> I am not sure what exactly needs to be done here, so I would not ask this question.

// De-compression. Smallest decompression.
// If there are multiple decompression strings, chose any.

#include <iostream>

using namespace std;

string decompress(const string& str, int& index) {
	string ans = "";
	string no = "";
	for(; index < str.length();) {
		char c = str[index];
		if (c-'0' >= 0 && c-'9' <= 9) {
			index += 1;
			no.append(1, c);
		} else if (c == '[') {
			index += 1;
			string temp = decompress(str, index);
			for(int j=0; j < stoi(no); ++j) { ans = ans.append(temp); }
			no.clear();
		} else if (c == ']') {
			index += 1;
			return ans;
		} else {
			index += 1;
			ans.append(1, c);
		}
	}
	return ans;
}

bool check_if_good_split(string str, int temp) {
	string s1 = str.substr(0, temp);
	for (int i=temp; i < str.length(); i += temp) {
		if(s1.compare(str.substr(i, temp)) != 0) {
			return false;
		}
	}
	return true;
}

string compress(string str) {
	int l1, l2, l3;
	string s1, s2, s3;
	l1 = str.size();
	s1 = str;

	l2 = 100000;
	int temp = l1/2;
	while(temp >= 1) {
		if (l1 % temp == 0) {
			if (check_if_good_split(str, temp)) {
				string compressed = compress(str.substr(0, temp));
				int l2_ret = 3 + compressed.length();
				if (l2_ret < l2) { l2 = l2_ret; s2 = to_string(l1/temp) + "[" + compressed + "]"; }
			}
		}
		--temp;
	}

	l3 = 100000;
	for(int i=1; i < l1-1; ++i) {
		string x1 = compress(str.substr(0, i));
		string x2 = compress(str.substr(i, l1-i));
		string x3 = x1 + x2;
		if (x3.size() < l3) {
			s3 = x3;
			l3 = x3.size();
		}
	}

	if (l1 < l2) {
		if (l1 < l3) {
			return s1;
		} else {
			return s3;
		}
	} else {
		if (l2 < l3) {
			return s2;
		} else {
			return s3;
		}
	}
}


int main() {
	string str("abc");
	int index = 0;
	//cout << decompress(str, index)	<< endl;
	cout << compress("abcabcabcdefdefdef") << endl;
}
