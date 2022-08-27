class Solution {
public:
   int minDistance(string &t1, string t2, vector<vector<int>> &dp, int i, int j) {


    if (i >= t1.length()) {
        return t2.length() - j;
    }
    if (j >= t2.length()) {
        return t1.length() - i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (t1[i] == t2[j]) {
        return dp[i][j] = minDistance(t1, t2, dp, i + 1, j + 1);
    } else {
        return dp[i][j] = 1 + min(minDistance(t1, t2, dp, i + 1, j), min(minDistance(t1, t2, dp, i, j + 1),
                                                                         minDistance(t1, t2, dp, i + 1, j + 1)));
    }

}

int minDistance(string word1, string word2) {

    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    int ans = minDistance(word1, word2, dp, 0, 0);
    return ans;
}
};