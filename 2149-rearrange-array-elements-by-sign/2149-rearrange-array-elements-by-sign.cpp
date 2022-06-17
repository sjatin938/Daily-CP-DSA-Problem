class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
 
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            pos.push_back(nums[i]);
        } else {
            neg.push_back(nums[i]);
        }
    }
    bool flag = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (flag == 0) {
            nums[i] = pos[j++];
            flag = 1;
        } else {
            nums[i] = neg[k++];
            flag = 0;
        }
    }
    return nums;
}
};