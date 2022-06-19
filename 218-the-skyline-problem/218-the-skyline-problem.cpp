class Solution {
public:
vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<vector<int>> ans;
    vector<pair<int, int>> wall;
    for (auto & building : buildings) {
        wall.emplace_back(building[0], -building[2]);
        wall.emplace_back(building[1], building[2]);
    }
    sort(wall.begin(), wall.end());
    multiset<int> leftWallHeight = {0};
    int top = 0;
    for (auto w: wall) {
        if (w.second < 0) {
            leftWallHeight.insert(-w.second);
        }
        else {
            leftWallHeight.erase(leftWallHeight.find(w.second));
        }
        if (*leftWallHeight.rbegin() != top) {
            top = *leftWallHeight.rbegin();
            ans.push_back({w.first, top});
        }
    }
    return ans;

    }
};