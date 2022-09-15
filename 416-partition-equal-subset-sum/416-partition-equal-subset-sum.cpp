class Solution {
public:
   bool helper(vector<int> &nums, int sum, int idx, vector<vector<int>> &dp) {
    if (sum < 0) {
        
        return false;
    }
    if (sum == 0) {
        return true;
    }
    if (idx >= nums.size()) {
        return false;
    }
    if (dp[sum][idx] != -1) {
        return dp[sum][idx];
    }
    int include = helper(nums, sum - nums[idx], idx + 1, dp);
    int exclude = helper(nums, sum, idx + 1, dp);
    return dp[sum][idx] = exclude | include;
}

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto &x: nums) {
        sum += x;
    }
    if (sum % 2 != 0) {
        return false;
    }
    vector<vector<int>> dp(sum+1, vector<int>(nums.size(), -1));
   return  helper(nums, sum / 2, 0, dp);
}
};