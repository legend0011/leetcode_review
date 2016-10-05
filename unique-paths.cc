//https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for (int i = 0; i < m; ++i) {
            vector<int> v(n, 1);
            dp.push_back(v);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m-1][n-1];
    }
};
