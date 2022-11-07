class Solution {
public:
   bool subset(vector<int> &nums, int sum, int idx, vector<vector<int>> &dp) {
    if (sum < 0) {
        return false;
    }
    if (sum == 0)
        return true;
    if (idx >= nums.size())
        return false;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    return dp[idx][sum] = subset(nums, sum - nums[idx], idx + 1, dp) | subset(nums, sum, idx + 1, dp);
}

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto &x: nums)
        sum += x;
    if (sum % 2 != 0) {
        return false;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
    return subset(nums, sum / 2, 0, dp);
}
};