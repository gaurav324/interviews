// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

// Notes:
// It took me some time to solve this problem.
// Why? I don't think there is some special reason. It was on the easier side actually.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int i=0, j=0, temp = nums[0];
        int min_len = INT_MAX;
        while (i != nums.size()) {
            if (temp >= s) {
                min_len = min(min_len, j - i + 1);
                temp -= nums[i++];
            } else if (j == nums.size() - 1) {
                break;
            } else {
                temp += nums[++j];
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};
