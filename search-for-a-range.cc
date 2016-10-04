//https://leetcode.com/problems/search-for-a-range/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.empty()) return result;
        result[0] = binarySearch(nums, target, true);
        result[1] = binarySearch(nums, target, false);
        return result;
    }

    int binarySearch(vector<int>& nums, int target, bool is_left_range) {
        int result = -1;
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (is_left_range) right = mid -1;
                else left = mid + 1;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
