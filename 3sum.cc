//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] < target) {
                    ++left;
                } else if (nums[left] + nums[right] > target) {
                    --right;
                } else {
                    vector<int> tmp(3, 0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    result.push_back(tmp);
                    while (left < right && nums[left] == tmp[1]) ++left;
                    while (left < right && nums[right] == tmp[2]) --right;
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};
