class Solution {
public:
   vector<string> s{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

void helper(string digits, string res, int i) {
    if (i == digits.length()) {
        ans.push_back(res);
        return;
    }

    for (int j = 0; j < s[digits[i] - '0'].length(); j++) {
        res.push_back(s[digits[i] - '0'][j]);
        helper(digits, res, i + 1);
        res.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
     if (digits == "")
     return {};
    string res = "";
    helper(digits, res, 0);
    return ans;
}
};