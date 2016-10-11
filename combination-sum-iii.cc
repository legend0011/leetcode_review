//https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k == 0) return result;
        vector<int> v;
        dfs(0, 0, k, n, v, result) ;
        return result;
    }
    void dfs(int start, int sum, const int& k, const int n, vector<int>& v, vector<vector<int>>& result) {
        if (v.size() >= k) return;
        for (int i = start + 1; i <= 9; ++i) {
            v.push_back(i);
            sum += i;
            if (sum == n && v.size() == k) result.push_back(v);
            else if (sum < n && v.size() < k) dfs(i, sum, k, n, v, result);
            sum -= i;
            v.pop_back();
        }
    }
};
