class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int maxCandies = 0;
    for (int i = 0; i < candies.size(); i++) {
        maxCandies = max(maxCandies, candies[i]);
    }

    vector<bool> ans(candies.size(), 0);
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            ans[i] = 1;
        }
    }
    return ans;
}
};