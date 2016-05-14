#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> twoSum(const vector<int>& arr, int n)
{
	unordered_map<int, int> seen;
	for(int i=0; i < arr.size(); ++i) {
		int x = n - arr[i];
		if (seen.find(x) != seen.end()) {
			return pair<int, int>(i, seen[x]);
		}
		seen[arr[i]] = i;
	}	
}


int main() {
	vector<int> arr = {2, 7, 11, 15};
	auto ans = twoSum(arr, 9);
	cout << ans.first << " " << ans.second;
}
