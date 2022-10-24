class Solution {
public:
 int lengthOfLongestSubstring(string s) {
    vector<int> indx(256, -1);
    int start = -1;
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
        if (indx[s[i]] > start)
            start = indx[s[i]];
        indx[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
};