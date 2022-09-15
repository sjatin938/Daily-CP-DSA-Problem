class Solution {
public:
   
int maxProfit(vector<int> &prices) {

    int ans = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        ans = min(ans, prices[i]);
        if (prices[i] - ans > 0) {
            profit += prices[i] - ans;
            ans = prices[i];
        }
    }
    return profit;
}
};