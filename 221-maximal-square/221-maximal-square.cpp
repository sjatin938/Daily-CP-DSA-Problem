class Solution {
public:
   int helper(vector<vector<char>>& matrix, int row, int col, vector<vector<int>> &dp) {

    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == '0') {
        return 0;
    }
    if (dp[row][col] != -1) {

        return dp[row][col];
    }
    int left = helper(matrix, row, col - 1, dp);
    int up = helper(matrix, row - 1, col, dp);
    int diag = helper(matrix, row - 1, col - 1, dp);
    int ans = min(left, min(up, diag)) + 1;
    return dp[row][col] = ans;
}

int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxM = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                int ans = helper(matrix, i, j, dp);
                maxM = max(ans, maxM);
            }

        }
    }
    return maxM * maxM;
}
};