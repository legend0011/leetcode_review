//https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1) return 0;
     	bool flag = true;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i-1]) continue;
			return i-1;
		}
		return nums.size() - 1;
    }
};
