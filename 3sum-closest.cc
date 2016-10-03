//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
		int result;
		int min_distance = INT_MAX;
		for (int i = 0; i < nums.size(); ++i) {
			int to_find = target - nums[i];
			int left = i + 1, right = nums.size() - 1;
			int sum, distance;
			while (left < right) {
				sum = nums[left] + nums[right];
				distance = sum - to_find;
				if (abs(distance) < min_distance) {
					result = sum + nums[i];
					min_distance = abs(distance);
				}
				if (distance > 0) --right;
				else if (distance < 0) ++left;
				else {
					return target;
				}
			}	
		}    
		return result;
    }
};
