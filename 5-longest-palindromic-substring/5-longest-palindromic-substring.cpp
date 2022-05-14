class Solution {
public:
    string longestPalindrome(string s) {
    bool dp[s.length()][s.length()];
    int a = -1;
    int b = -1;
    for (int diagonal = 0; diagonal < s.length(); diagonal++) {
        for (int row = 0, col = diagonal; col < s.length(); row++, col++) {
            if (diagonal == 0) {
                dp[row][col] = true;
            } else if (diagonal == 1) {
                if (s[row] == s[col]) {
                    dp[row][col] = true;
                } else {
                    dp[row][col] = false;
                }
            } else {
                if (s[row] == s[col] && dp[row + 1][col - 1]) {
                    dp[row][col] = true;
                } else {
                    dp[row][col] = false;
                }
            }
            if (dp[row][col]) {
                a = row;
                b = diagonal + 1;
            }
        }
    }
    return s.substr(a,b);
}
};