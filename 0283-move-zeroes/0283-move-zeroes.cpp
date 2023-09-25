class Solution {
public:
    void moveZeroes(vector<int> &nums) {
    if (nums.size() < 2) {
        return;
    }
    int ptr = 0;

    int i = 0;
    while (i < nums.size()) {
        if (nums[i] == 0) {
            i++;
            continue;
        }
        nums[ptr++] = nums[i++];
    }

    for(int i = nums.size()-1 ; i>=ptr ;i--){
        nums[i] = 0;
    }
}
};