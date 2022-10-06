class Solution {
public:
   vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> leftMaxPro(nums.size(), 1);
    int rightMaxPro = 1;
    for (int i = 1; i < nums.size(); i++) {
        leftMaxPro[i] = leftMaxPro[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
        leftMaxPro[i] = leftMaxPro[i] * (rightMaxPro * nums[i+1]);
        rightMaxPro = rightMaxPro * nums[i+1];
    }
    return leftMaxPro;
}
};