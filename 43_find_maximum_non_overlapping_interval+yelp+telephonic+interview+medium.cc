// This was a very good question, asked to me in the yelp telephonic interview.
// There are a bunch of time ranges given to us. We have to find the maximum number of non-overlapping ranges.
//
// This is similar to Activity Selection problem, where we select a bunch of non-overlapping activities to 
// perform within a given time frame. Problem is to maximize the number of overlapping activities.
// 
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct sorter {
bool operator() (const pair<int, int>& left, const pair<int, int>& right) {
	return left.second < right.second;
}
};

int findMaximumNonOverlappingRanges(vector<std::pair<int, int>> ranges) {
	sort(ranges.begin(), ranges.end(), sorter());
	int count = 1;
	auto prev = ranges[0];
	for(int i=1; i < ranges.size(); ++i) {
		auto cur = ranges[i];
		if (cur.first > prev.second) {
			prev = cur;
		  ++count;
		}
	}
	return count;
}

int main() {
	cout << findMaximumNonOverlappingRanges({{6, 7}, {1, 2}, {3, 8}, {2, 6}, {8, 11}, {10, 12}}) << endl;
}
