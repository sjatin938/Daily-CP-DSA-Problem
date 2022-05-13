class Solution {
public:
   
string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1) {
        return strs[0];
    }
    int n = strs.size();
    sort(strs.begin(), strs.end());
    string s = "";
    int i = 0;
    int j = 0;
    while (i < strs[0].size() && j < strs[n - 1].size()) {
        if (strs[0][i] == strs[n - 1][j]) {
            s += strs[0][i];
            i++;
            j++;
        } else {
            break;
        };

    }
    return s;

}
};