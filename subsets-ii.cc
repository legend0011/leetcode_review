//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector<int> dummy;
        result.push_back(dummy);
        sort(nums.begin(), nums.end());
        vector<int> pre;
        dfs(nums, 0, nums.size(), &pre, &result);
        return result;
    }
    void dfs(const vector<int>& nums, int start, int size,
             vector<int>* pre, vector<vector<int>>* result) {
        for (int now = start; now < size; ++now) {
            if (now != start && nums[now] == nums[now - 1]) continue;
            pre->push_back(nums[now]);
            result->push_back(*pre);
            dfs(nums, now + 1, size, pre, result);
            pre->pop_back();
        }
    }
};
