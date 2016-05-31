// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> nums) {
    int ans = nums[0];
    for (int i=1; i < nums.size(); ++i) {
        ans ^= nums[i];
    }
    return ans;
}

int main() {
	cout << singleNumber({1, 3, 3});
}
