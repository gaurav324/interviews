// Standard DP problem to find the length of longest non-decreasing subsequence.
// e.g: 0, 8, 4, 12, 2, 10, 6, 14, 1, 9 : [0, 4, 10, 14] LEN(4).
//
// SOLUTION:
// 1) Simple DP based solution: O(n^2), for every number, go and check back for all numbers, and find max among them.
// 2) GREEDY + Binary Search: Simply Keep adding larger number to solution. However, if we find smaller than larger number in solution, we go and find the that number in ccurrent ans, which is just greater than a[i] under consideration and replace that with a[i]. i.e. upper_bound(a[i], a); This way we would not probably be able to return back the actual ans correctly but the length returned would be correct.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <size_t N>
int longestSubSequenceDP(int (&arr)[N]) {
	int ans = 0;
	int temp[N];
	for (int i = 0; i < N; ++i) {
		int t_ans = 1;
		for (int j=0; j < i; ++j) {
			if (temp[j] + 1 >= t_ans && arr[i] >= arr[j]) {
			  t_ans = temp[j] + 1;
			}
		}
		temp[i] = t_ans;
		if (t_ans > ans) { ans = t_ans; }
	}
	return ans;
}

template <size_t N>
vector<int> longestSubSequenceNotLength(int (&arr)[N]) {
	vector<int> ans;
	int max_l = 0;

	int temp[N];
	vector<int> prev;
	int max_index;
	for (int i = 0; i < N; ++i) {
		int t_ans = 1;
		prev.push_back(-1);
		for (int j=0; j < i; ++j) {
			if (temp[j] + 1 >= t_ans && arr[i] >= arr[j]) {
				prev[i] = j;
			  t_ans = temp[j] + 1;
			}
		}
		temp[i] = t_ans;
		if (t_ans > max_l) { max_l = t_ans; max_index = i;}
	}

	do {
		ans.push_back(arr[max_index]);
		max_index = prev[max_index];
	} while(max_index != -1);
	return ans;
}

template <size_t N>
int longestSubSequenceGreedy(int (&arr)[N]) {
	vector<int> ans;
	for (int i=0; i < N; ++i) {
		auto it = upper_bound(ans.begin(), ans.end(), arr[i]);
		if (it  == ans.end()) {
			ans.push_back(arr[i]);
		} else {
			*it = arr[i];
		}
	}
	return ans.size();
}

int main() {
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
	cout << "Longest non-decreasing Length using DP: " << longestSubSequenceDP(arr) << endl;
	cout << "Longest non-decreasing Length using Greedy: " << longestSubSequenceGreedy(arr) << endl;
	
	cout << "Longest sequence is: " << endl;
	vector<int> ans = longestSubSequenceNotLength(arr);
	for (int i=ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << "\t";
	}
}
