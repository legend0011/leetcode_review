//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
       	int min_num = nums[0];
		int left = 0, right = nums.size() - 1, mid;
		while (left < right - 1) {
			mid = (left + right) / 2;
			if (nums[mid] == nums[left]) ++left;
			else if (nums[mid] > nums[left]) {
				min_num = min(min_num, nums[left]);
				left = mid + 1;
			} else {
				min_num = min(min_num, nums[mid]);
				right = mid - 1;
			}
		} 
		min_num = min(min_num, nums[right]);
		min_num = min(min_num, nums[left]);
		return min_num;
    }
};
