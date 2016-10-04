//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
   		int final_max = INT_MIN;
		int now = 0;
		for (int i = 0; i < nums.size(); ++i) {
			now += nums[i];
			final_max = max(final_max, now);
			if (now <= 0) now = 0;
		}
		return final_max;
    }
};
