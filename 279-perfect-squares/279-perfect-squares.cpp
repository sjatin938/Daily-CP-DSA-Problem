class Solution {
public:
  int numSquares(int n, vector<int> &dp) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT32_MAX;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int mini = INT32_MAX;
    for (int i = 1; i * i <= n; i++) {
        int ans = numSquares(n - i * i, dp);
        if (ans != INT32_MAX) {
            mini = min(mini, ans + 1);
        }
    }
    return dp[n] = mini;
}

int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    int ans = numSquares(n, dp);
    return ans;
}
};