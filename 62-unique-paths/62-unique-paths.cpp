class Solution {
public:
    int helper(int m, int n, vector<vector<bool>> &path, int row, int col, vector<vector<int>> &dp) {
    if (row == m - 1 && col == n - 1) {
        return 1;
    }
    if (row >= m) {
        return 0;
    }
    if (col >= n) {
        return 0;
    }
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    if (path[row][col] == 0) {
        return 0;
    }
    path[row][col] = 0;
    int l = helper(m, n, path, row + 1, col, dp);
    int r = helper(m, n, path, row, col + 1, dp);
    path[row][col] = 1;
    return dp[row][col] = l + r;

}

int uniquePaths(int m, int n) {
    vector<vector<bool>> path(m, vector<bool>(n, 1));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m, n, path, 0, 0, dp);

}
};