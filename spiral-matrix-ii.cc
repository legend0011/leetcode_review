//https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if (n <= 0) return result;
        for (int i = 0; i < n; ++i) {
            vector<int> v(n, 0);
            result.push_back(v);
        }
        int loop = 0;
        int now_count = 1;
        int r = n / 2;

        while (loop < r) {
            for (int y = loop; y <= n - loop - 1; ++y) result[loop][y] = now_count++;
            for (int x = loop + 1; x <= n - loop - 1; ++x) result[x][n - loop - 1] = now_count++;
            for (int y = n - loop - 2; y >= loop; --y) result[n - loop - 1][y]  = now_count++;
            for (int x = n - loop - 2; x >= loop + 1; --x) result[x][loop] = now_count++;
            ++loop;
        }
        if (n % 2 == 1) {
            result[loop][loop] = now_count;
            return result;
        }
        return result;
    }
};
