class Solution {
public:
 int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.size() < 2)
        return 0;

    sort(intervals.begin(), intervals.end());
    int ans = 0, arrow = 0, n = intervals.size();

    for (int i = 0; i < n; i++) {
        if (i != 0 && intervals[i][0] < arrow) {
            ans++;
            arrow = min(arrow, intervals[i][1]);
        } else {
            arrow = intervals[i][1];
        }
    }
    return ans;
}
};