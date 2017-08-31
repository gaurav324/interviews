//
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i1 = 0;
    int i2 = 0;
    int read = 0;
    int sum = nums1.size() + nums2.size();
    int v0, v1;
    while (read != ((sum / 2) + 1)) {
      v0 = v1;
      if (i1 < nums1.size() && i2 < nums2.size()) {
        if (nums1[i1] < nums2[i2]) {
          v1 = nums1[i1++];
        } else {
          v1 = nums2[i2++];
        }
      } else if (i1 < nums1.size()) {
        v1 = nums1[i1++];
      } else if (i2 < nums2.size()) {
        v1 = nums2[i2++];
      }
      ++read;
    }
    if (sum % 2 == 0) {
      return (v1 + v0) / 2.0;
    } else {
      return v1;
    }
  }
};
