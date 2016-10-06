//https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums2.empty()) return;
		if (nums1.empty()) {nums1 = nums2; return;}
  		int now = m + n - 1;
		int i1 = m - 1, i2 = n - 1;
		while (i1 >= 0 && i2 >= 0) {
			if (nums1[i1] > nums2[i2]) {
				nums1[now--] = nums1[i1--];
			} else {
				nums1[now--] = nums2[i2--];
			}
		}      
		while (i1 >= 0) nums1[now--] = nums1[i1--];
		while (i2 >= 0) nums1[now--] = nums2[i2--];
		return;
    }
};
