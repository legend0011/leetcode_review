//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if (nums.empty()) return 0;
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return max(left, right);
    }
};
