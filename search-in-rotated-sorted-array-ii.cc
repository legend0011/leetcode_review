//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) return true;
            if (nums[mid] > nums[left]) {
                if (target < nums[mid] && target >= nums[left]) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            } else {
                ++left;
            }
        }
        return false;
    }
};
