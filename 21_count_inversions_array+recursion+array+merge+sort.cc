// Given array of n numbers, find number of inverted index pairs in it.
// An inverted index is such that (i < j && A[i] > A[j]) or (i > j && A[i] < A[j]).
//
// Things learnt:
// 1) Inversion should trigger the thought of merge sort.
// 2) Merge Sort use extra space. Doing inplace is hard, and we can skip that. 
// 
#include <iostream>
#include <vector>
using namespace std;

int merge(int* arr, int l1, int l2, int r1, int r2) {
	int inversions = 0;
	std::vector<int> merged;
	int o_l1 = l1;
	while(l1 <= l2 && r1 <= r2) {
		if (arr[l1] <= arr[r1]) {
			merged.push_back(arr[l1++]);
		} else {
			merged.push_back(arr[r1++]);
			inversions += (l2 - l1 + 1);
		}
  }
	while (l1 <= l2) {
		merged.push_back(arr[l1++]);
	}
	while(r1 <= r2) {
		merged.push_back(arr[r1++]);
	}
	for(int i=0; i < merged.size(); ++i) {
		arr[o_l1+i] = merged[i];
	}
	return inversions;
}

int countInversion(int* arr, int start, int end) {
	if (start == end) { return 0; }
	
	int mid = start + (end - start) / 2;
	return countInversion(arr, start, mid) + countInversion(arr, mid + 1, end) + merge(arr, start, mid, mid + 1, end);
}

int main() {
	int arr[] = {12, 3, 10, 20, 15, 5, 1};
	cout << countInversion(arr, 0, 6) << endl;
  for (int i=0; i < 7; ++i) {
		cout << arr[i] << "\t";
	}
}
