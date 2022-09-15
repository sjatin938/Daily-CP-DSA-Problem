class Solution {
public:
   int maxProfit(vector<int> &prices) {
    int ans = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        ans = min(ans, prices[i]);
        profit = max(profit, prices[i] - ans);
    }
    return profit;
}
};