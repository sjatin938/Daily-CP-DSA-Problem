class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &dp) {

    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1 && obstacleGrid[row][col] != 1) {
        return 1;
    }
    if (row >= obstacleGrid.size()) {
        return 0;
    }
    if (col >= obstacleGrid[0].size()) {
        return 0;
    }
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    if (obstacleGrid[row][col] == 1) {
        return 0;
    }
    if (obstacleGrid[row][col] == INT32_MAX) {
        return 0;
    }
    obstacleGrid[row][col] = INT32_MAX;
    int ans = uniquePathsWithObstacles(obstacleGrid, row + 1, col, dp) +
              uniquePathsWithObstacles(obstacleGrid, row, col + 1, dp);
    obstacleGrid[row][col] = 0;
    return dp[row][col] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    return uniquePathsWithObstacles(obstacleGrid, 0, 0, dp);

}
};