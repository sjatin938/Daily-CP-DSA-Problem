class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    if (word1.length() == 0)
        return word2;
    if (word2.length() == 0)
        return word1;
    int i = 0, j = 0;
    int n = word1.length();
    int m = word2.length();

    string ans;
    bool flag = 0;
    while (i < n && j < m) {
        if (flag) {
            ans += word2[j++];
            flag = !flag;
        } else {
            ans += word1[i++];
            flag = !flag;
        }
    }
    if (i != n) {
        ans = ans + word1.substr(i);
    }
    if (j != m) {
        ans = ans + word2.substr(j);
    }
    return ans;
}
};