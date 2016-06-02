// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

// NOTES:
// Idea here is that at any point in time, sum that we carry forward should be not -ive. Unless we can keep on moving 
// forward with the array indices. Once we hit negative, we reset.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int temp = 0;
        for (auto n : nums) {
            temp += n;
            if (temp > max) {
                max = temp;
            }
            if (temp < 0) {
                temp = 0;
            }
        }
        return max;
    }
};

// Test cases:
// [1]
// [1, 2, 3]
// [-5, -1, -2, -4]
