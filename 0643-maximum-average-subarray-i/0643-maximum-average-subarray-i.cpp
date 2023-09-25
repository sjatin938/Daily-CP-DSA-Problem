class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
    if (nums.size() < k)
        return 0;
    
    int start = 0;
    int i = 0;
    double maxAns = INT32_MIN;
    double ans = 0;
    while (i < nums.size()) {
        if (i >= k) {
            maxAns = max(ans / k, maxAns);
            ans = ans - nums[start++];
        }
        ans = ans+nums[i];
        i++;
    }
    maxAns = max(ans / k, maxAns);
    return maxAns;
}
};