//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result(2, 0);
  		int left = 0, right = numbers.size() - 1;
		while(left < right) {
			if (numbers[left] + numbers[right] == target) {
				result[0] = left + 1;
				result[1] = right + 1;
				return result;
			} else if (numbers[left] + numbers[right] > target) {
				--right;
			} else {
				++left;
			}
		}      
		return result;
    }
};
