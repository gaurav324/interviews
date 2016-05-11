// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// What did I learn?
// 1) When think of storing in map/set. always remember that we can store "VALUE" in map. 
//		So, check whether you could leverage that fact or not. 

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// O(n) Solution.
	int optimalSolution(string s) {
		unordered_map<char, int> seen;
		int start = 0;
		int len = 0;
		for (int i=0; i < s.size(); ++i) {
			auto itr = seen.find(s[i]);
			if (itr != seen.end()) {
				int prev_seen_index = (*itr).second;
				// This is where the *SPECIAL* logic is.
				if (prev_seen_index >= start) {
					start = prev_seen_index + 1;
				}
			}
			seen[s[i]] = i;
			if ((i - start + 1) > len) {
				len = i - start + 1;
			}
		}
		return len;
	}

	// O(n^2)worst case and O(n) best case.
	int lengthOfLongestSubstring(string s) {
		int start = 0;
		int len = 0;
		for(int i=0; i < s.size(); ++i) {
			for(int j=start; j < i; ++j) {
				if (s[j] == s[i]) {
					start = j + 1;
					break;
				}
			}
			if ((i - start + 1) > len) {
				len = i - start + 1;
			}
		}
		return len;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}

