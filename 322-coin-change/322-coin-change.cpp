class Solution {
public:
    int coinChange(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0 || idx < 0) {
        return INT32_MAX - 1;
    }
    if (dp[idx][amount] != -1) {
        return dp[idx][amount];
    }
    int take = 1 + coinChange(coins, amount - coins[idx], idx, dp);
    int dontTake = coinChange(coins, amount, idx - 1, dp);
    return dp[idx][amount] = min(take, dontTake);
}

int coinChange(vector<int> &coins, int amount) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int ans = coinChange(coins, amount, coins.size() - 1, dp);
    if (ans == INT32_MAX - 1) {
        return -1;
    }
    return ans;
}
};