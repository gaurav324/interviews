//--- WARM-UP ---
//
//There is compressed string like this:
//3[abc]4[ab]c
//and we want to decompress it into form like this:
//abcabcabcababababc
//
//here number[string] decompresses to string written number times.
//
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

#include <iostream>

using namespace std;

string expand(const string& str, int& index) {
	string ans = "";
	string no = "";
	for(; index < str.length();) {
		char c = str[index];
		if (c-'0' >= 0 && c-'9' <= 9) {
			index += 1;
			no.append(1, c);
		} else if (c == '[') {
			index += 1;
			string temp = expand(str, index);
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

int main() {
	string str("2[a10[b]2[c]]");
	int index = 0;
	cout << expand(str, index)	<< endl;
}
