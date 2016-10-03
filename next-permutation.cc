//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (auto it = nums.end() - 1; it >= nums.begin(); --it) {
            if (it == nums.begin()) {
                reverse(it, nums.end());
                return;
            }
            if (*it <= *(it - 1)) continue;
            
            reverse(it, nums.end());
            auto replace_it = it - 1;
            while (*replace_it >= *it && (it+1) != nums.end()) ++it;
            swap(*replace_it, *it);
            return;
        }
    }
};
