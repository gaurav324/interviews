// Elements of programming: 13.8
// Let D be a set of strings and S be a string, find the shortest prefix of s, which is not a prefix of any string in D.
// 
// Solution:
// Easy one actually, just create a map of prefixes and check for prefixes of s. That is it.

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string findShortestPrefix(unordered_set<string> D, string s) {
	unordered_set<string> prefix_set;
	for (auto str : D) {
		for (int i = 1; i <= str.size(); ++i) {
			prefix_set.insert(str.substr(0, i));
		}
	}
	
	for (int i = 1; i <= s.size(); ++i) {
		if (prefix_set.find(s.substr(0, i)) == prefix_set.end()) {
			return s.substr(0, i);
		}
	}
	
	return "-1";
}

int main() {
	unordered_set<string> D1 = {"dog", "car", "cat"};
	unordered_set<string> D2 = {"dog", "car"};
	unordered_set<string> D3 = {"dog", "sit", "cut"};

	cout << "Shortest prefix " << findShortestPrefix(D1, "cat") << endl;
	cout << "Shortest prefix " << findShortestPrefix(D2, "cat") << endl;
	cout << "Shortest prefix " << findShortestPrefix(D3, "cat") << endl;
}
