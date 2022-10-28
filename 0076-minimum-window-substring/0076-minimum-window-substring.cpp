class Solution {
public:
  
string minWindow(string s, string t) {
    if (s.length() < t.length())
        return "";

    vector<int> count(123, 0);
    for (auto &x: t)
        count[x]++;

    int len = t.length();
    int minLen = INT32_MAX;
    int start = 0;
    int idx = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (len == 0) {
            count[s[start]]++;
            if (minLen > i - start) {
                minLen = i - start;
                idx = start;
            }
            if (count[s[start]] > 0) {
                len++;
            }
              i--;
            start++;
        } else {
            if (i == s.length())
                break;
            count[s[i]]--;
            if (count[s[i]] >= 0) {
                len--;
            }
        }
    }
    return  minLen == INT32_MAX ? "" : s.substr(idx, minLen);
}
};