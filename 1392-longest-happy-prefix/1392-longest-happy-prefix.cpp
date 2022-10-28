class Solution {
public:
    string longestPrefix(string s) {

    int len = 0;
    vector<int> lps(s.length(), 0);
    for (int i = 1; i < s.length();) {
        if (s[i] == s[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else {
            if (len == 0) {
                i++;
            } else {
                len = lps[len - 1];


            }
        }
    }
    return s.substr(0, lps[s.length() - 1]);
}
};