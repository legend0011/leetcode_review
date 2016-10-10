//https://leetcode.com/contest/1/problems/lexicographical-numbers/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        if (n <= 0) return result;
        int i = 0;
        dfs(n, i, result);
        return result;
    }
    void dfs(const int& n, int now, vector<int>& result) {
        int tmp;
        for (int i = 0; i <= 9; ++i) {
            tmp = now * 10 + i;
            if (tmp == 0) continue;
            if (tmp > n) return;
            result.push_back(tmp);
            dfs(n, tmp, result);
        }
    }
};
