// Elements Boook 17.15 DP problem, chose coins from either end and while doing so maximize the margin
// of victory.
//
// Solution is to come up with the recurrence relation and base case first and then try to solve that using DP.
// max_rec(arr, a, b) = max (arr[a] + min(max_rec(arr, a+2, b), max_rec(arr, a+1, b-1)), 
//                           arr[b] + min(max_rec(arr, a+1, b-1), max_rec(arr, a, b-2)));
//
// Termination Condition: If a == b: return a, 
//                        If b - a = 1: return max(a, b)
#include <iostream>
#include <vector>

using namespace std;

// Things learnt:
// 1) If we are able to nail down the recurrence relation, we have got the solution.
// 2) We could have let it be a recursive solution, where base condition would be if (a > b) { return 0;}
//    - We also did not have to worry of about cases like if subproblem tries to access a+1 and b+1 both, ain't gonaa happen. Because we never check beyond b.
// 3) In simple iterative solution, we handled, two base cases, set value for diagonals and places where i and j differ by 1. Rest is then simple.
int max_rec(const vector<int>& arr) {
	int n = arr.size();
	int sol[n][n];
	for(int i=0; i < n; ++i) {
		sol[i][i] = arr[i];
	}
	for(int i=0; i < n - 1; ++i) {
  	sol[i][i+1] = max(arr[i], arr[i+1]);
	}

	for(int i=n-3; i>=0; --i) {
		for (int j=i+2; j<n; ++j) {
			// This is the main logic here.
			sol[i][j] = max(arr[i] + min(sol[i+2][j], sol[i+1][j-1]), arr[j] + min(sol[i+1][j-1], sol[i][j-2]));
		}
	}
	
	for (int i=0;i < n; ++i) {
		cout << "\n";
		for (int j=0; j < n; ++j) {
			cout << sol[i][j] << "\t";
		}
	}
	return sol[0][arr.size()-1];
}

int main() {
	vector<int> arr = {25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10};
	cout << max_rec(arr);
}
