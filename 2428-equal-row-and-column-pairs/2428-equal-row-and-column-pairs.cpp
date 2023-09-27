class Solution {
public:

    //READ THIS CAREFULLY
   // unordered_map does not support vector;
   // in first store

    int equalPairs(vector<vector<int>> &grid) {
    map<vector<int>, int> m;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        m[grid[i]]++;
    }
    int count = 0;
    for (int c = 0; c < n; c++) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back(grid[i][c]);
        }
        count += m[temp];
    }
    return count;
}
};