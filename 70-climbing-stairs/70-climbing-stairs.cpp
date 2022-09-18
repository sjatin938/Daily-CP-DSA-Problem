class Solution {
public:
   int climbStairs(int n, vector<int> &dp) {
    if (n < 0) {
        return 0;
    }
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int l1 = climbStairs(n - 1, dp);
    int l2 = climbStairs(n - 2, dp);
    return dp[n] = l1 + l2;
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairs(n, dp);
}
};