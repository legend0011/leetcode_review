//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
   		if (heights.empty()) return 0;
		stack<int> s;
		int max_area = 0;
		int left, right, lwidth, rwidth;
		for (int i = 0; i < heights.size(); ++i) {
			while (!s.empty() && heights[i] < s.top()) {
				int top = s.top();
				s.pop();
				lwidth = s.empty() ? top + 1 : top - s.top();
				rwidth = i - top - 1;
				max_area = max(max_area, heights[top] * lwidth + heights[top] * rwidth);
			}
			s.push(heights[i]);
		}     
		return max_area;
    }
};
