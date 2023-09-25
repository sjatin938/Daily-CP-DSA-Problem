class Solution {
public:
string reverseWords(string s) {
    int n = s.length();
    string ans;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ')continue;
        start = i;
        while (i < n && s[i] != ' ')i++;
        ans = ' ' + s.substr(start, i - start) + ans;
    }
    return ans.substr(1);
}
};