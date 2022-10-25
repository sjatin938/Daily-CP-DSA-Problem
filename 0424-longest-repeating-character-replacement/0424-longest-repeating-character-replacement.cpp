class Solution {
public:
   int characterReplacement(string s, int k) {
    int len = 0;
    int maxLen = 0;
    int j = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.length(); i++) {
        maxLen = max(maxLen, ++mp[s[i]]);
        if (len < maxLen + k) {
            len++;
        } else {
            mp[s[j++]]--;
        }
    }
    return len;
}
};