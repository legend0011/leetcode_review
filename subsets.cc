//https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
  		vector<vector<int>> result;
		if (nums.empty()) return result;
		vector<int> pre;
		result.push_back(pre);
		dfs(nums, 0, nums.size() - 1, &pre, &result);      
		return result;
    }
	void dfs(const vector<int>& nums, const int& now_idx, const int& total, 
			 vector<int>* pre, vector<vector<int>>* result) {
		if (now_idx > total) return;
		for (int i = now_idx; i <= total; ++i) {
			pre->push_back(nums[i]);
			result->push_back(*pre);
			dfs(nums, i+1, total, pre, result);
			pre->pop_back();
		}
	}
};
