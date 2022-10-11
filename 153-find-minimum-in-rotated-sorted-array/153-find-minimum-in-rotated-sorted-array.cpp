class Solution {
public:

int findMin(vector<int> &nums) {
    int n = nums.size();
    if (nums[0] < nums[n - 1])
        return nums[0];
    int ans = INT32_MAX;
    int l = 0;
    int h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (nums[mid] > nums[h]) {
            l = mid + 1;
        } else {
            ans = min(ans, nums[mid]);
            h = mid - 1;
        }

    }
    return ans;
}
};