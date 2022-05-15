class Solution {
public:
void nextPermutation(vector<int> &nums) {
    if (nums.size() == 0)
        return;
    int n = nums.size();
    int j = n - 1;
    while (j > 0) {
        if (nums[j] > nums[j - 1]) {
            break;
        }
        j--;
    }
    if (j == 0) {
        reverse(nums.begin(), nums.end());
        return ; 
    }
    int last = j ;
    int i = j;
    while (j < n) {
        if (nums[i] > nums[j] && nums[j] > nums[i - 1]) {
            last = j;
        }
        j++;
    }
    swap(nums[i - 1], nums[last]);
    sort(nums.begin() + i, nums.end());
    }
};