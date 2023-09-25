class Solution {
public:
   long long totalCost(vector<int> &costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    int n = costs.size();
    int i = 0;
    int j = n - 1;
    long long ans = 0;
    while (k) {
        while (pq1.size() < candidates && i <= j) {
            pq1.push(costs[i++]);
        }
        while (pq2.size() < candidates && j >= i) {
            pq2.push(costs[j--]);
        }

        int a = pq1.size() > 0 ? pq1.top() : INT32_MAX;
        int b = pq2.size() > 0 ? pq2.top() : INT32_MAX;

        if (a <= b) {
            ans += a;
            pq1.pop();
        } else {
            ans += b;
            pq2.pop();
        }
        k--;
    }
    return ans;
}
};