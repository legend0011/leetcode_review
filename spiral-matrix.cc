//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int h = matrix.size(), w = matrix[0].size();
        travel(matrix, 0, h - 1, 0, w - 1, result);
        return result;
    }

    void travel(vector<vector<int>>& matrix,
           int up_h, int down_h, int left_w, int right_w,
           vector<int>& result) {
        if (up_h > down_h || left_w > right_w) return;
        for (int i = left_w; i <= right_w; ++i)
            result.push_back(matrix[up_h][i]);
        for (int j = up_h + 1; j <= down_h; ++j)
            result.push_back(matrix[j][right_w]);
        if (down_h - up_h >= 1) {
            for (int i = right_w - 1; i >= left_w; --i)
                result.push_back(matrix[down_h][i]);
        }
        if (right_w - left_w >= 1) {
            for (int j = down_h - 1; j >= up_h + 1; --j)
                result.push_back(matrix[j][left_w]);
        }
        travel(matrix, up_h + 1, down_h - 1, left_w + 1, right_w - 1, result);
    }
};
