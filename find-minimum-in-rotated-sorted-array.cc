//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
  		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			if (nums[left] <= nums[right]) return nums[left];
			mid = (left + right) / 2;
			if (mid == left) return nums[left+1];
			if (nums[left] < nums[mid]) left = mid + 1;
			else right = mid;
		}
    }
};
