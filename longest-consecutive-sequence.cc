//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int max_count = 0;
		unordered_set<int> exists_set;
		unordered_set<int> visited_set;
		for (int i = 0; i < nums.size(); ++i) {
			exists_set.insert(nums[i]);
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited_set.find(nums[i]) != visited_set.end()) continue;
			int count = 1, left = nums[i] - 1, right = nums[i] + 1;
			while(exists_set.find(left) != exists_set.end()) {
				visited_set.insert(left);
				--left;
				++count;
			}
			while(exists_set.find(right) != exists_set.end()) {
				visited_set.insert(right);
				++right;
				++count;
			}
			max_count = max(max_count, count);
		}
		return max_count;
    }
};
