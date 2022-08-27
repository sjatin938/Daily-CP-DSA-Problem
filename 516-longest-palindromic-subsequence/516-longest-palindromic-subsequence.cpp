class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2, int m, int n, vector<vector<int>> &memo) {
        if (m >= text1.length() || n >= text2.length()) {
            return 0;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        if (text1[m] == text2[n]) {
            return memo[m][n] = 1 + longestCommonSubsequence(text1, text2, m + 1, n + 1, memo);
        } else {
            return memo[m][n] = max(longestCommonSubsequence(text1, text2, m + 1, n, memo),
                                    longestCommonSubsequence(text1, text2, m, n + 1, memo));
        }
    }

    int longestPalindromeSubseq(string s) {
        int m = s.size();
        string w = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> memo(m+1, vector<int>(m+1, -1));

        return longestCommonSubsequence(s, w, 0, 0, memo);
    }
};