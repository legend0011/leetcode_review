//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
		int max_area = 0;
		if (height.empty()) return max_area;
		int left = 0, right = height.size() - 1; 
		max_area = max(max_area, min(height[left], height[right]) * (right - left));
		while (left < right) {
			if (height[left] < height[right]) {
				++left;
			} else {
				--right;
			}
			max_area = max(max_area, min(height[left], height[right]) * (right - left));
		}
		return max_area;
    }
};

