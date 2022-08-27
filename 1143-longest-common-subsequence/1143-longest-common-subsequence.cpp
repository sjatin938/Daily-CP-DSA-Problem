class Solution {
public:
   int longestCommonSubsequence(string &t1, string &t2, int i, int j, vector<vector<int>> &dp) {

    if (i >= t1.length()) {
        return 0;
    }
    if (j >= t2.length()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = INT32_MIN;
    if (t1[i] == t2[j]) {
        return dp[i][j] = 1 + longestCommonSubsequence(t1, t2, i + 1, j + 1, dp);

    } else {
        return dp[i][j] = max(longestCommonSubsequence(t1, t2, i + 1, j, dp),
                              longestCommonSubsequence(t1, t2, i, j + 1, dp));
    }

}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1 , -1));
    return longestCommonSubsequence(text1, text2, 0, 0, dp);

}
};