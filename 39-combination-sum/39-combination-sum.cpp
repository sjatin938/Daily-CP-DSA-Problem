class Solution {
public:
vector<vector<int>> ans;
void combinationSum(vector<int> temp, vector<int> &candidates, int target, int idx) {

    if (target <= 0 ) {
        if (target == 0) {
            ans.push_back(temp);
        }
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        temp.push_back(candidates[i]);
        combinationSum(temp, candidates, target - candidates[i], i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> temp;
    combinationSum(temp, candidates, target, 0);
    return ans;

}
};