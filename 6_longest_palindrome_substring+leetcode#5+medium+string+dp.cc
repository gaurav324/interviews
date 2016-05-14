// Given a string S, find the longest palindromic substring in S. 
// You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring. 
//
// THINGS LEARNT:
// 1) If you think, you are able to express solution in terms of sub problem,
//    then you must give it a thought that what are the base cases. Mostly
//    you should be able to solve by DP then.
// 2) Don't think that every problem can be solved in O(n). Solve properly
//    with whatever best complexity first.

#include <iostream>
using namespace std; 

string palindrome(string s) {
	bool ans[len][len];
	for (int i=0; i < len; ++i) for (int j=0; j < len; ++j) ans[i][j] = false;
	
	int l1 = 0, l2 = 0, max = 0;

	for (int i=0; i < len; ++i) {
		ans[i][i] = true;
		l1 = l2 = i;
		max = 1;
	}
	
	for (int i=0; i < len-1; ++i) {
		if (s[i] == s[i+1]) {	
			ans[i][i+1] = true;
			l1 = i, l2 = i + 1;
			max = 2;
		} 
	}

	for (int i=1; i < len; ++i) {
		for (int j=i-2; j >= 0; --j) {
			ans[j][i] = (s[i] == s[j]) && ans[j+1][i-1];
			if (ans[j][i] && (i - j + 1 > max)) {
				max = i - j + 1;
				l1 = j, l2 = i;
			}
		}
	}

	return s.substr(l1, max);
}

int main() {
string s;
s = "abcdcba"; cout << s << "=" << palindrome(s) << endl; 
s = "a"; cout << s << "=" << palindrome(s) << endl; 
s = "aaa"; cout << s << "=" << palindrome(s) << endl; 
s = "aaaba"; cout << s << "=" << palindrome(s) << endl; 
s = "abcdefgfed"; cout << s << "=" << palindrome(s) << endl; 
}
