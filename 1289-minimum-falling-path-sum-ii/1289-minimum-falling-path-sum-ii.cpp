class Solution {
public:
    
int minFallingPathSum(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp) {

    if (col < 0 || col >= grid[0].size()) {
        return 1e9;
    }
    if (row == grid.size() - 1)
        return grid[row][col];
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    int diag = INT32_MAX;
    for (int i = 0; i < grid[0].size(); i++) {
        if (i == col) {
            continue;
        } else {
            diag = min(grid[row][col] + minFallingPathSum(grid, row + 1, i, dp), diag);
        }
    }
    return dp[row][col] = diag;

}
    int minFallingPathSum(vector<vector<int>>& grid) {
       int ans = INT32_MAX;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    for (int i = 0; i < grid[0].size(); i++) {
        ans = min(minFallingPathSum(grid, 0, i, dp), ans);
    }
        return ans;
    }
};