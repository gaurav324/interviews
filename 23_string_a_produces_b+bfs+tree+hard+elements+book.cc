// There is dictionary of words(D) and given two strings s and t. Determine whether if s produces t or not.
// Produces: s0, s1, ... t
// All strings in dictionary are of same length and all s(i)s are only one character apart.
// Return min length of the sequence.
// 

// THINGS LEARNT:
// 1) Whenever think of min steps of converting A -> B, string  or something else, where I might try to use all combinations, 
//    think of BFS.
// 2) BFS by its structure is very useful for shortest paths. 

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int min_len_produce(const unordered_set<string>& D, string s, string t) {
	queue<pair<string, int>> q;
	q.push(pair<string, int>(s, 0));

	unordered_set<string> seen;
	seen.insert(s);

	while(!q.empty()) {
		auto ele = q.front(); q.pop();
		if (strcmp(ele.first.c_str(), t.c_str()) == 0) {
			return ele.second;
		}
		for (int i=0; i < s.size(); ++i) {
			string temp = ele.first;
			for (int j=0; j < 26; ++j) {
				temp[i] = 'a' + j;
				if ((seen.find(temp) == seen.end()) && (D.find(temp) != D.end())) {
					q.push(pair<string, int>(temp, ele.second + 1));	
					seen.insert(temp);
				}
			}
		}
	}
	return -1;
}

int main() {
	unordered_set<string> dict = {"cat", "mow", "bat", "bet", "lat","lot", "mot"};

	cout << min_len_produce(dict, "cat", "mow") << endl;	
	cout << min_len_produce(dict, "cat", "alh") << endl;	
	cout << min_len_produce(dict, "mow", "mot") << endl;	
}
