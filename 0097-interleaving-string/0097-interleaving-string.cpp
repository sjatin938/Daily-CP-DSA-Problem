class Solution {
public:
    bool isInterleave(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp) {
    if (i >= s1.length() && j >= s2.length()) {
        return 1;

    }

    if (dp[i][j] != -1)
        return dp[i][j];

    bool take1 = s1[i] == s3[i + j] ? isInterleave(s1, s2, s3, i + 1, j, dp) : 0;
    bool take2 = s2[j] == s3[i + j] ? isInterleave(s1, s2, s3, i, j + 1, dp) : 0;
    return dp[i][j] = take1 | take2;

}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())
        return 0;
    vector<vector<int>> dp(101, vector<int>(101, -1));
    return isInterleave(s1, s2, s3, 0, 0, dp);
}
};