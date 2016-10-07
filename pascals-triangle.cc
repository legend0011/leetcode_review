//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
   vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        vector<int> tmp(1, 1);
        result.push_back(tmp);
        for (int i = 1; i < numRows; ++i) {
            for (int j = tmp.size() - 1; j > 0; --j)
                tmp[j] = tmp[j-1] + tmp[j];
            tmp.push_back(1) ;
            result.push_back(tmp);
        }
        return result;
    }
};
