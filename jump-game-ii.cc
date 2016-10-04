//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
		int paces = 0;
		int last_pace = 0;
		int cur_pace = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > last_pace) {
				++paces;
				last_pace = cur_pace;
			}
			cur_pace = max(cur_pace, i + nums[i]);
		}
		return paces;
    }
};
