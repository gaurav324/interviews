// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].

// Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
///////////////////////////////////////////////////////
//
// Notes:
// So what all we had to think.
// 1) Linear scan from left to right, that brings us to divide based solution.
// 2) Left to right and right to left.
// 3) Hashes one can think of.
// 4) Sorting.
// 5) XORs or other bit operations. 

#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    result.resize(nums.size(), 0);
    result[0] = 1;
    int temp = nums[0];
    for(int i=1; i < nums.size(); ++i) {
        result[i] = temp;
        temp = temp * nums[i];
    }
    temp = nums[nums.size() - 1];
    for(int i=nums.size() - 2; i >=0 ; --i) {
        result[i] *= temp;
        temp = temp * nums[i];
    }
    return result;
}

int main() {
	vector<int> v = {1, 2, 3, 4};
	productExceptSelf(v);
}
