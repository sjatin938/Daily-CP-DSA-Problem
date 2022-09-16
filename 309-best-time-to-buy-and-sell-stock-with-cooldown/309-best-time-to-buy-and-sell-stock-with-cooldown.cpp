class Solution {
public:
   int solve(vector<int> &prices, int day, int transtitionLeft, vector<vector<int>> &dp) {
    if (day == prices.size()) {
        return 0;
    }
    if (dp[day][transtitionLeft] != -1) {
        return dp[day][transtitionLeft];
    }
    int ans2 = 0;
    int ans = solve(prices, day + 1, transtitionLeft, dp);
    if (transtitionLeft == 0) {
        ans2 = -prices[day] + solve(prices, day + 1, 1, dp);
    }
    if (transtitionLeft == 1) {
        ans2 = prices[day] + solve(prices, day + 1, 2, dp);
    }
    if (transtitionLeft == 2) {
        ans2 = solve(prices, day + 1, 0, dp);
    }
    return dp[day][transtitionLeft] = max(ans2, ans);
}

int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(3, -1));
    return solve(prices, 0, 0, dp);

}
};