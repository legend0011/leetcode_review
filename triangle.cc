//https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
        for (int i = triangle.size() - 1; i > 0; --i) {
			for (int j = 0; j <= i - 1; ++j) {
				triangle[i-1][j] = triangle[i-1][j] + min(triangle[i][j], triangle[i][j+1]);
			}
		}
		return triangle[0][0];
    }
};
