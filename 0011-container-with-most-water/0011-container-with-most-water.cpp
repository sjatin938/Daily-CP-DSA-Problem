class Solution {
public:
    int maxArea(vector<int> &height) {
    int l = 0;
    int h = height.size()-1;
    int ans = 0;
    int maxArea = INT32_MIN;
    while (l < h) {
        ans = min(height[l], height[h]) * (h - l);
        maxArea = max(ans, maxArea);
        if (height[l] < height[h]) {
            l++;
        } else {
            h--;
        }
    }
    return maxArea;
  }
};