//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
  		int now_val = nums[0];
		int now_count = 1;
		int total = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (now_val == nums[i]) {
				++now_count;
				if (now_count <= 2) nums[total++] = nums[i];
			} else {
				now_val = nums[i];
				now_count = 1;
				nums[total++] = nums[i];
			}
		}
		return total;
    }
};
