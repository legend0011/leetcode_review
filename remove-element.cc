//https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int change_idx = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == val) continue;
			nums[change_idx++] = nums[i];
		}    
		return change_idx;
    }
};
