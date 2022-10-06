class Solution {
public:
    int trap(vector<int> &height) {

    int n = height.size();
    if (n < 3) {
        return 0;
    }
    int leftMax = height[0];
    int rightMax = height[n - 1];
    int ans = 0;
    int i = 1;
    int j = n - 2;
    while (i <= j) {
        if (rightMax > leftMax) {
            int currWater = (leftMax - height[i]);
            if (currWater > 0)
                ans = ans + currWater;
            else {
                leftMax = height[i];
            }
            i++;
        } else {
            int currWater = (rightMax - height[j]);
            if (currWater > 0)
                ans = ans + currWater;
            else {
                rightMax = height[j];
            }
            j--;
        }

    }
    return ans;
}
};