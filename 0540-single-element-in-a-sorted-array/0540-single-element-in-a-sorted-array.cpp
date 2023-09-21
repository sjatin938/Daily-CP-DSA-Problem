class Solution {
public:
   int singleNonDuplicate(vector<int> &nums) {
    if (nums.size() < 2)
        return nums[0];
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }

    return ans;
}
};