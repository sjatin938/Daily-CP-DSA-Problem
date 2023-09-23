class Solution {
public:
int numDistinct(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if (j == t.length())
        return 1;
    if (i == s.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s[i] == t[j])
        ans = numDistinct(s, t, i + 1, j + 1, dp);

    ans += numDistinct(s, t, i + 1, j, dp);
    return dp[i][j] = ans;

}

int numDistinct(string s, string t) {
    if (s.length() < t.length())
        return 0;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return numDistinct(s, t, 0, 0, dp);
}
};