//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
        int min_neg = nums[0], max_pos = nums[0];
        int max_product = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp_min_neg = min_neg;
            min_neg = min(min(min_neg * nums[i], max_pos * nums[i]), nums[i]);
            max_pos = max(max(tmp_min_neg * nums[i], max_pos * nums[i]), nums[i]);
            max_product = max(max_product, max_pos);
        }
        return max_product;
    }
};
