class Solution {
public:
    bool isPalindrome(string s) {
    if (s.size() == 0) {
        return true;
    }
    int l = 0;
    int n = s.length();
    int h = n - 1;
    while (l < h) {
        while (l < h && !isalnum(s[l]))
            l++;
        while (l < h && !isalnum(s[h])) {
            h--;
        }
        if (tolower(s[l++]) != tolower(s[h--]))
            return false;
    }
    return true;
}
};