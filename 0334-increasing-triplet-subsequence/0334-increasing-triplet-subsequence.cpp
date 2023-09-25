class Solution {
public:
   bool increasingTriplet(vector<int> &nums) {
    if (nums.size() < 3)
        return false;
    int f = INT32_MAX;
    int s = INT32_MAX;
    for (auto &x: nums) {
        if (x <= f)f = x;
        else if (x <= s)s = x;
        else return true;
    }
    return false;
}
};