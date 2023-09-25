class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0;
        int h = height.size()-1;
        int maxArea = INT32_MIN;
        while(l<h){
            area = min(height[l], height[h]) * (abs(h - l));
            maxArea = max(area, maxArea);
            if(height[l] < height[h])
            l++;
            else{
                h--;
            }
        }
        return maxArea;
    }
};