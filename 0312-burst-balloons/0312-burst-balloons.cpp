class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
    
    // Pad the nums array with 1s at the beginning and end
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Calculate the maximum coins for each subarray of balloons
    for (int len = 1; len <= n; ++len) {
        for (int left = 1; left <= n - len + 1; ++left) {
            int right = left + len - 1;
            for (int k = left; k <= right; ++k) {
                dp[left][right] = std::max(dp[left][right], 
                                          dp[left][k - 1] + dp[k + 1][right] + nums[left - 1] * nums[k] * nums[right + 1]);
            }
        }
    }
    
    return dp[1][n];
}
};