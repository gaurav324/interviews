#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool helper(vector<int>& nums, vector<int>& visited, int K, int S, int kk,
              int SUM) {
    int N = nums.size();
    // cout << "\n\nk = " << K << " and S = " << S << endl;
    if (K == 0 && S == 0) {
      return true;
    }
    if (!S) {
      S = SUM;
    }
    for (int i = 0; i < N; ++i) {
      // Check if the index is already used up.
      // cout << "visited[i] = " << visited[i] << endl;
      if (visited[i]) {
        continue;
      }
      //cout << "Matching i = " << i << ", S = " << S << ", nums[i]= " << nums[i]
      //     << " and S - nums[i] = " << S - nums[i] << endl;
      visited[i] = 1;
      if (((S - nums[i]) > 0 &&
           helper(nums, visited, K, S - nums[i], kk, SUM)) ||
          ((S - nums[i]) == 0 && helper(nums, visited, K - 1, 0, kk, SUM))) {
        return true;
      }
      visited[i] = 0;
    }
    return false;
  }

  bool canPartitionKSubsets(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    long total_sum = 0;
    for (auto n : nums) {
      total_sum += n;
    }
    if (total_sum % k != 0) {
      return false;
    }
    int S = total_sum / k;
    int N = nums.size();
    vector<int> visited;
    for (int i = 0; i < N; ++i) {
      if (nums[i] > S) { return false; } 
      visited.push_back(0);
    }
    return helper(nums, visited, k, S, k, S);
  }
};

// Return true if we can partition a vector into k subsets of same sum.
// 1 <= k <= len(nums) <= 16
// 0 < nums[i] < 10000
int main() {
  Solution s;
  vector<int> input {85,35,40,64,86,45,63,16,5364,110,5653,97,95};
  //vector<int> input{605, 454, 322,  218, 8,   19,   651, 2220,
  //                  175, 710, 2666, 350, 252, 2264, 327, 1843};
  // vector<int> input{4, 3, 2, 3, 5, 2, 1};
  cout << s.canPartitionKSubsets(input, 7) << endl;
}
