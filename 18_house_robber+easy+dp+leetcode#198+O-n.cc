// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
      vector<int> rob;
      if (nums.size() == 0) {
          return 0;
      } else if (nums.size() == 1) {
          return nums[0];
      } else if (nums.size() == 2) {
          return max(nums[0], nums[1]);
      } else {
          rob.push_back(nums[0]);
          rob.push_back(max(nums[0], nums[1]));
          for (int i = 2; i < nums.size(); ++i) {
              rob.push_back(max(rob[i-1], rob[i-2] + nums[i]));
          }
          return rob[nums.size() - 1];
      }
    }
};
