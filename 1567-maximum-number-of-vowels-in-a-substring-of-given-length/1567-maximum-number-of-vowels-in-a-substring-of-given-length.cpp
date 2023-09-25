class Solution {
public:
  int maxVowels(string s, int k) {
    if (s.length() < k)
        return 0;

    int start = 0;
    int ptr = 0;
    int count = 0;
    int ans = 0;
    while (ptr < s.length()) {
        if (ptr >= k) {
            ans = max(ans, count);
            if (s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u') {
                count--;
            }
            start++;
        }
        if (s[ptr] == 'a' || s[ptr] == 'e' || s[ptr] == 'i' || s[ptr] == 'o' || s[ptr] == 'u') {
            count++;
        }
        
        ptr++;
    }
    ans = max(ans, count);
    return ans;
}
};