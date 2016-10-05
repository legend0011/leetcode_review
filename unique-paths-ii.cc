//https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        bool block = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                obstacleGrid[i][j] = (obstacleGrid[i][j] == 1) ? 0 : 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (block) obstacleGrid[i][0] = 0;
            else if (obstacleGrid[i][0] == 0) block = true;
        }
        block = false;
        for (int j = 0; j < n; ++j) {
            if (block) obstacleGrid[0][j] = 0;
            else if (obstacleGrid[0][j] == 0) block = true;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) continue;
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
