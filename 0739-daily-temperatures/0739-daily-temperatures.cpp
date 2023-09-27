class Solution {
public:
 vector<int> dailyTemperatures(vector<int> &temperatures) {
    if (temperatures.size() < 2)
        return {0};
    int n = temperatures.size();
    stack<int> s{};
    s.push(n-1);
    vector<int> ans(n, 0);
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {

        while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
            s.pop();
        }
         if(!s.empty()) {
            ans[i] = s.top()- i;
        }
        s.push(i);
    }
    return ans;
}
};