class Solution {
public:
    
int minFallingPathSum(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp) {

    if (col < 0 || col >= matrix[0].size()) {
        return 1e9;
    }
    if (row == matrix.size() - 1)
        return matrix[row][col];
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    int down = matrix[row][col] + minFallingPathSum(matrix, row + 1, col, dp);
    int diag = matrix[row][col] + minFallingPathSum(matrix, row + 1, col - 1, dp);
    int right = matrix[row][col] + minFallingPathSum(matrix, row + 1, col + 1, dp);
    return dp[row][col] = min(down, min(diag, right));

}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT32_MAX;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix[0].size(); i++) {
        ans = min(minFallingPathSum(matrix, 0, i ,dp), ans);
    }
    return ans; 
    }
};