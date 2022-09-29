class Solution {
public:
   
int maxProfit(vector<int> &prices) {
    int ans = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - ans > 0) {
            maxProfit = max(maxProfit, prices[i] - ans);
        } else {
            ans = prices[i];
        }
    }
    return maxProfit;
}
};