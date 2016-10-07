//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int low = INT_MAX;
		int result = 0;
  		for (int i = 0; i < prices.size(); ++i) {
			result = max(prices[i] - low, result);
			low = min(prices[i], low);
		}      
		return result;
    }
};
