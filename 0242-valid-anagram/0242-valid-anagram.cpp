class Solution {
public:
bool isAnagram(string s, string t) {
    vector<int> s1(26, 0);
    vector<int> t1(26, 0);
    for (auto &x: s) {
        s1[x - 'a']++;
    }
    for (auto &x: t) {
        t1[x - 'a']++;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != t1[i]) {
            return false;
        }
    }
    return true;
}
};