//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> answer;
        if (candidates.empty()) return result;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, 0, target, &answer, &result);
		return result;
    }
	void dfs(const vector<int>& candidates, int start, int sum, int target,
			 vector<int>* answer, vector<vector<int>>* result) {
		if (sum > target) return;
		if (sum == target) {
			result->push_back(*answer);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			answer->push_back(candidates[i]);
			dfs(candidates, i, sum + candidates[i], target, answer, result);
			answer->pop_back();
		}
	}
};
