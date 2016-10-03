//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				int to_find = target - nums[i] - nums[j];
				int left = j + 1, right = nums.size() - 1;
				int sum;
				while (left < right) {
					sum = nums[left] + nums[right];
					if (sum < to_find) ++left;
					else if (sum > to_find) --right;
					else {
						vector<int> tmp(4, 0);
						tmp[0] = nums[i];
						tmp[1] = nums[j];
						tmp[2] = nums[left];
						tmp[3] = nums[right];
						result.push_back(tmp);	
						while (left < right && nums[left] == tmp[2]) ++left;
					}
				}
				while (j + 1 < nums.size() && nums[j+1] == nums[j]) ++j;
			}
			while (i + 1 < nums.size() && nums[i+1] == nums[i]) ++i;
		}   
		return result;
    }
};
