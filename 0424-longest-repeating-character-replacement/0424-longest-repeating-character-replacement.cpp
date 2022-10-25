class Solution {
public:
   int characterReplacement(string s, int k) {
    // k =  non-SameCharacter
    int len = 0;
    int sameCharacter = 0;
    int j = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.length(); i++) {
        sameCharacter = max(sameCharacter, ++mp[s[i]]);
        if (len - sameCharacter < k) {
            len++;
        } else {
            mp[s[j++]]--;
        }
    }
    return len;
}
};