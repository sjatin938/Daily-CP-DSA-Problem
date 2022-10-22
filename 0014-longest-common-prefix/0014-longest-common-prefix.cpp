class Solution {
public:
   string longestCommonPrefix(vector<string> &strs) {
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string top = strs[0];
    string last = strs[n - 1];
    int i = 0;
    for (; i < top.length(); i++) {
        if (top[i] != last[i])
            break;
    }
    return top.substr(0, i);
}
};