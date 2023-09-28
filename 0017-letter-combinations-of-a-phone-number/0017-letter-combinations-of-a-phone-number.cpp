class Solution {
public:
    vector<string> temp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void helper(string digits , string &res , int i){
        if(i== digits.length()){
        ans.push_back(res);
        return; 
        }
        int t = digits[i]-'0';
        for(int j =0 ; j < temp[t].length(); j++){
            char c  = temp[t][j];
            res = res+c;
            helper(digits , res , i+1);
            res.pop_back();
        }
}
    vector<string> letterCombinations(string digits) {
       if(digits.length()==0)
       return {};

    string res;
    helper(digits , res , 0); 
    return ans;
    }
};