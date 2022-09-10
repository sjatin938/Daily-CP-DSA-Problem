class Solution {
public:
   int rob(vector<int> &nums,  int idx, vector<int> &dp) {

    if (idx >= nums.size()) {
        return 0;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }

    int inc = nums[idx] + rob(nums, idx + 2, dp);
    int exc = rob(nums,  idx + 1, dp);

    return dp[idx] = max(inc, exc);


}

int rob(vector<int> &nums) {
    vector<int> dp(nums.size()+1, -1);
    return rob(nums, 0, dp);

}
};