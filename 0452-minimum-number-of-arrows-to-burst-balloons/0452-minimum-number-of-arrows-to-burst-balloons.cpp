
bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <2)
            return 1;
        sort(points.begin(), points.end(), cmp);
            int ans =1, arrow_pointer =points[0][1] , n = points.size();
            for(int i = 1 ;i < n; i++){
                if( points[i][0] > arrow_pointer){
                    ans++;
                    arrow_pointer = points[i][1];
                }
            }

            return ans;
    }
};