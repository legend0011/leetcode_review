//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int days = prices.size();
        vector<int> pre_profit(days, 0);
        vector<int> post_profit(days, 0);
        int low = INT_MAX;
        for (int i = 0; i < days; ++i) {
            pre_profit[i] = max(prices[i] - low, (i == 0) ? 0 : pre_profit[i-1]);
            low = min(low, prices[i]);
        }
        //int high = INT_MIN; OVERFLOW!
        int high = 0;
        for (int i = days - 1; i >= 0; --i) {
            post_profit[i] = max(high - prices[i], (i == days - 1) ? 0 : post_profit[i+1]);
            high = max(high, prices[i]);
        }
        for (int i = 0; i < days; ++i) {
            max_profit = max(max_profit, pre_profit[i] + post_profit[i]);
        }
        return max_profit;
    }
};
