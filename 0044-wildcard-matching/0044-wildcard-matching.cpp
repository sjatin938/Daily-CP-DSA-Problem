class Solution {
public:
   bool isMatch(const std::string& s, const std::string& p) {
    int m = s.length();
    int n = p.length();

    // Initialize a dynamic programming table
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Handle the '*' in the pattern
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[m][n];
}

};