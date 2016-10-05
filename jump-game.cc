//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
		int now_max = 0, tmp;
  		for (int i = 0; i < nums.size(); ++i) {
			if (now_max < i) return false;
			tmp = i + nums[i];
			now_max = max(tmp, now_max);
		}      
		return true;
    }
};
