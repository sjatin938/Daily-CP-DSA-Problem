class Solution {
public:
   long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    if (k > nums1.size())
        return 0;
    
    int n = nums1.size();

    vector<pair<int, int>> v(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        v[i] = {nums1[i], nums2[i]};
    }
    auto lambda = [&](auto &P1, auto &P2) {
        return P1.second > P2.second;
    };
    sort(begin(v), end(v), lambda);

    long long sum = 0;
    for (int i = 0; i <= k-1; i++) {
        sum += v[i].first;
        pq.push(v[i].first);
    }

    long long result = sum * v[k-1].second;

    for (int i = k; i < n; i++) {
        sum += v[i].first - pq.top();
        pq.pop();
        result = max(result, sum * v[i].second);
        pq.push(v[i].first);
    }
    return result;
}
};