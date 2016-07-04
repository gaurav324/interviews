// Given an abs-sorted array A and a number K, find all pairs of indics with sum = K, else (-1, 1)//
// Algo, should be Time-O(n) and space O(1). 

// SOLUTION:
// 1) Solve for pair of numbers being of same sign.
// 2) Solve for pair of numbers being of opposite sign.
// When same sign, we move from left and right, using standard algorithm.
// When opp sign, we start both from right. If (positive + negative) > K, then we reduce +ive component. If < K, we increase -ive component (by going left).
#include <iostream>
#include <vector>

using namespace std;

template <typename Comp>
void solveSameSign(const vector<int>& nos, vector<pair<int, int>>& ans, int K, Comp comp) {
	int left = 0;
	int right = nos.size() - 1;
	while (left <= right && !comp(nos[left], 0)) {
		++left;
	}

	while (left <= right && !comp(nos[right], 0)) {
		--right;
	}
	
	while(left < right) {
		if (nos[left] + nos[right] == K) {
			ans.push_back(pair<int, int>(left, right));			
			break;
		}

		// BE WATCH-FULL HERE.
		if (comp(nos[left] + nos[right], K)) {
			do {
				--right;
			} while(left <= right && !comp(nos[right], 0));
		} else {
			do {
				++left;
			} while(left <= right && !comp(nos[left], 0));
		}
	}	
}

// This is really classy.
void solveOppSign(const vector<int>& nos, vector<pair<int, int>>& ans, int K) {
	int positive = nos.size();
	int negative = nos.size();
	do {
		--positive; 
	} while(positive >= 0 && nos[positive] < 0);
	
	do {
		--negative;
	}	while(negative >= 0 && nos[negative] > 0);

	while(positive >=0 && negative >= 0) {
		if (nos[positive] + nos[negative] == K) {
			ans.push_back(pair<int, int>(positive, negative));			
			do {
				--negative;
			} while(negative >= 0 && nos[negative] > 0);
			do {
				--positive;
			} while(positive >= 0 && nos[positive] < 0);


		} else if (nos[positive] + nos[negative] < K) {
			do {
				--negative;
			} while(negative >= 0 && nos[negative] > 0);
		} else {
			do {
				--positive;
			} while(positive >=0 && nos[positive] < 0);
		}
	}
}

vector<pair<int, int>> getAllPairsSumK(const vector<int>& nos, int K) {
	vector<pair<int, int>> ans;
	if (K > 0) { 
		solveSameSign(nos, ans, K, std::greater_equal<int>()); 
	} else { 
		solveSameSign(nos, ans, K, std::less<int>()); 
	}
	solveOppSign(nos, ans, K);

	if (ans.size() > 0) {
	 return ans;
	} else { 
		return {{-1, -1}};
	}
}

int main() {
	vector<int> input = {-1, 2, 3, -4, -5, 6, 7, 8, 9};

	vector<pair<int, int>> ans = getAllPairsSumK(input, 5);
	cout << "Found " << ans.size() << " answers for " << 5 << endl;
	for (int i=0; i < ans.size(); ++i) {cout << ans[i].first << " " << ans[i].second << endl; }

	ans = getAllPairsSumK(input, -9);
	cout << ans[0].first << " " << ans[0].second << endl;

}
