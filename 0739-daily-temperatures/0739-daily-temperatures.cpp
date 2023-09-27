class Solution {
public:
 vector<int> dailyTemperatures(vector<int> &temperatures) {
    if (temperatures.size() < 2)
        return {0};
    int n = temperatures.size();
    stack<pair<int, int>> s;
    s.push({temperatures[n - 1], n - 1});
    vector<int> ans(n, 0);
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {

        while (!s.empty() && s.top().first <= temperatures[i]) {
            s.pop();
         
        }
        if (s.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = s.top().second - i;
        }
        s.push({temperatures[i], i});
    }
    return ans;
}
};