class Solution {
public:
   int helper(vector<int> &nums, int curr_idx, vector<int> &dp) {
        if (curr_idx >= nums.size() - 1) {
            return 0;
        }

        if (dp[curr_idx] != 100000) return dp[curr_idx];
        for (int i = 1; i <= nums[curr_idx]; i++)
            dp[curr_idx] = min(dp[curr_idx], helper(nums, i + curr_idx, dp) + 1);

        return dp[curr_idx];
    }

    int jump(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        vector<int> dp(nums.size(), 100000);
        return helper(nums, 0, dp);
    }
};