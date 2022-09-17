class Solution {
public:
   vector<int> runningSum(vector<int> &nums) {

    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += ans;
        ans = nums[i];
    }
    return nums;


}
};