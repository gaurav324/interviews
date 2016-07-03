// Given an 2-D array, which is sorted along both rows and columns.
// You have to tell whether any element K exists in array or not.
//
// SOLUTION:
// Basically keep checking with the right upper corner of the array.
// If element is smaller than corner, then discard the right most column, because all values there would be larger than right upper corner.
// Else, if ele > corner, discard the top row, as all would be smaller than that.
//
// This way, at each step we keep discarding one row or column and in the process, we can find our element.
// Complexity: At each step, one row or column is dropped. i.e. at max 2N elements to be checked. O(N).

#include <iostream>
using namespace std;

template <size_t rows, size_t cols>
bool search(int (&arr)[rows][cols], int n, int k) {
	int R = 0, C = n;
	while (R <= n && C >= 0) {
		if (arr[R][C] == k) {
			return true;			
		}
		else if (k < arr[R][C]) {
			C -= 1;
		} else {
			R += 1;
		}	
	}
	return false;		
}

int main() {
	int arr[4][4] = { {1, 3, 4, 10}, {4, 5, 17, 20}, {9, 10, 19, 25}, {12, 14, 26, 35}};
	cout << "Searching for 19 = " << search(arr, 3, 19) << endl;
	cout << "Searching for 18 = " << search(arr, 3, 18) << endl;
	cout << "Searching for 12 = " << search(arr, 3, 12) << endl;
}
