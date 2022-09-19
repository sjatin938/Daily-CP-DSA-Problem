class Solution {
public:
    int lengthOfLIS(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp) {
    if (idx == nums.size()) {
        return 0;
    }
    if (dp[idx][prev + 1] != -1) {
        return dp[idx][prev + 1];
    }
    int take = INT32_MIN;
    if (prev == -1 || nums[idx] > nums[prev]) {
        take = 1 + lengthOfLIS(nums, idx + 1, idx, dp);
    }
    int dontTake = lengthOfLIS(nums, idx + 1, prev, dp);
    return dp[idx][prev + 1] = max(take, dontTake);
}

int lengthOfLIS(vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return lengthOfLIS(nums, 0, -1, dp);
}

};