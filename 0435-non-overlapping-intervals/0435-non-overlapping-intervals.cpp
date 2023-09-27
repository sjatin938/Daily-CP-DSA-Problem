class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.size() < 2)
        return 0;
    sort(intervals.begin(), intervals.end());
    int ans = 0, arrow = intervals[0][1];
    int n = intervals.size();
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] < arrow) {
            ans++;
             arrow = min (arrow  ,  intervals[i][1]);
        }else{
            arrow = intervals[i][1];
        }
      
    }
    return ans;
}
};