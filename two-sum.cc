//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
		vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
			if (m.find(target - nums[i]) != m.end()) {
				result.push_back(m[target - nums[i]]);
				result.push_back(i);
				break;
			}
			m[nums[i]] = i;
		}
		return result;
    }
};
