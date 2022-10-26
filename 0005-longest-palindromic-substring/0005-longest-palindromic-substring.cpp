class Solution {
public:
    string longestPalindrome(string s) {
    vector<vector<bool>> palin(s.length(), vector<bool>(s.length(), 0));
    int idx = -1, len = -1;
    for (int diag = 0; diag < s.length(); diag++) {
        for (int row = 0, col = diag; col < s.length(); row++, col++) {
            if (s[row] == s[col])
                if (diag == 0 || diag == 1 || palin[row + 1][col - 1] == 1)
                    palin[row][col] = 1;
            if (palin[row][col] == 1) {
                idx = row;
                len = diag + 1;
            }
        }
    }
    return s.substr(idx, len);
}
};