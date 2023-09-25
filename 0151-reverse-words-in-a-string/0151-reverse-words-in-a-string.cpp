class Solution {
public:
string reverseWords(string s) {
    if (s.length() == 0)
        return "";


    string ans;
    int i = 0;
    int start = 0;
    while (i < s.length()) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        start = i;
        while ( i< s.length() && s[i] != ' ') {
            i++;
        }
        ans = ' ' + s.substr(start, i-start) + ans;
    }
    return ans.substr(1);
}
};