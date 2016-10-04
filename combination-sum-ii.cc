//https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        sort(candidates.begin(), candidates.end());
        vector<int>  answer;
        dfs(candidates, -1, 0, target, &answer, &result);
        return result;
    }
    void dfs(const vector<int>& candidates,
             int start, int sum, int target,
             vector<int>* answer,
             vector<vector<int>>* result) {
        if (sum > target) return;
        if (sum == target) {
            if (!exists(*answer, *result))
                result->push_back(*answer);
            return;
        }
        for (int i = start + 1; i < candidates.size(); ++i) {
            answer->push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target, answer, result);
            answer->pop_back();
        }
    }
    bool exists(const vector<int>& answer, const vector<vector<int>>& result) {
        if (result.empty()) return false;
        for (int i = result.size() - 1; i >= 0; --i) {
            if (checkSame(result[i], answer)) return true;
        }
        return false;
    }
    bool checkSame(const vector<int>& v1, const vector<int>& v2) {
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};
