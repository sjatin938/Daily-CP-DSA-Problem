class Solution {
public:
    int minCostClimbingStairs(vector<int> &cos, int n, vector<int> &dp) {
    if (n >= cos.size()) {
        return 0;
    }
    if (n == cos.size() - 1)
        return cos[n];
    if (dp[n] != -1) {
        return dp[n];
    }
    int l1 = cos[n] + minCostClimbingStairs(cos, n + 1, dp);
    int l2 = cos[n] + minCostClimbingStairs(cos, n + 2, dp);
    return dp[n] = min(l1, l2);
}

int minCostClimbingStairs(vector<int> &cos) {
    vector<int> dp(cos.size() + 1, -1);
    int l1 = minCostClimbingStairs(cos, 1, dp);
    int l2 = minCostClimbingStairs(cos, 0, dp);
    return min(l1, l2);
}
};