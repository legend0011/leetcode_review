//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
		if (height.empty()) return 0;
  		int top_idx = 0, top = 0;
		//find top
		for (int i = 0; i < height.size(); ++i) {
			if (height[i] > top) {
				top = height[i];
				top_idx = i;
			}
		}
		int total_area = 0;
		int pos = 0, root = height[0];
		while (pos < top_idx) {
			if (height[pos] > root) root = height[pos];
			else total_area += root - height[pos];
			++pos;
		}
		pos = height.size() - 1, root = height[pos];
		while (pos > top_idx) {
			if (height[pos] > root) root = height[pos];
			else total_area += root - height[pos];
			--pos;
		}
		return total_area;
    }
};
