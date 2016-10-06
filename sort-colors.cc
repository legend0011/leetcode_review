//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
		if (nums.empty()) return;
  		int two = nums.size() - 1, zero = 0;      
		for (int i = 0; i <= two;) {
			if (nums[i] == 0) swap(nums[i++], nums[zero++]);
			else if (nums[i] == 2) swap(nums[i],nums[two--]);
			else i++;
		}
    }
};
