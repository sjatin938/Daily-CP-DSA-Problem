class Solution {
public:
   bool isMatch(std::string s, std::string p) {
    int m = s.length();
    int n = p.length();
    
    // Initialize a 2D vector to store the matching status
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    
    // Empty pattern matches an empty string
    dp[0][0] = true;
    
    // Handle patterns with '*' as the first character
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }
    
    // Fill the dp table based on the pattern and string
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    
    // Return true if the entire string matches the pattern
    return dp[m][n];
}
};