//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] < nums[right]) {
                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target < nums[mid]) {
                    if (nums[mid] >= nums[left]) {
                        if (target >= nums[left]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (nums[mid] >= nums[left]) {
                        left = mid + 1;
                    } else {
                        if (target > nums[right]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
