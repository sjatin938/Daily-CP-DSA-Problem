class Solution {
public:
string reverseWords(string s) {
    
    string ans;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')continue;
        start = i;
        while (i < s.length() && s[i] != ' ')i++;
        ans = ' ' + s.substr(start, i - start) + ans;
    }
    return ans.substr(1);
}
};