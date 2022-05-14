class Solution {
public:
    
int countSubstrings(string s) {
    int len = 0;
    bool dp[s.length()][s.length()];
    for (int diag = 0; diag < s.length(); diag++) {
        for (int i = 0, j = diag; j < s.length(); i++, j++) {
            if (diag == 0) {
                dp[i][j] = true;
            } else if (diag == 1) {
                if (s[i] == s[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            } else {
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] =false;
                }
            }
            if (dp[i][j]) {
                len++;
            }
        }
    }
    return len;
}
};