//https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
  		int start = 0, end = 0;
		int sum = 0, min_size = INT_MAX, size = nums.size();
		while (start < size && end < size) {
			while (sum < s && end < size) {
				sum += nums[end++];
			}
			while (sum >= s && start <= end) {
				min_size = min(min_size, end - start) ;
				sum -= nums[start++];
			}
		}
		return min_size == INT_MAX ? 0 : min_size;
    }
};
