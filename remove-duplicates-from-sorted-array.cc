//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
  		sort(nums.begin(), nums.end());
		int change_idx = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i-1] == nums[i]) continue;
			nums[change_idx] = nums[i];
			++change_idx;
		}      
		return change_idx;
    }
};
