class Solution {
public:
    
void combinationalSum3(int k, int n, vector<int>& temp, vector<vector<int>> &ans, int &sum, int idx) {
    if (k <= temp.size()) {
        if (sum == n)
            ans.push_back(temp);
        return;
    }

    for (int i = idx; i <= 9; i++) {
        if(sum > n)
            return ; 
        sum = sum + i;
        temp.push_back(i);
        combinationalSum3(k, n, temp, ans, sum , i+1);
        temp.pop_back();
        sum -= i;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> s;
    vector<vector<int>> v;
    int sum =0;
    combinationalSum3(k, n, s, v, sum , 1);
    return v;
}
};