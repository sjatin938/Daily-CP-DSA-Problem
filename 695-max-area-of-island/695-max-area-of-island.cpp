class Solution {
public:
   int helper(int row, int col, vector<vector<int>> &grid)
{
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || !grid[row][col])
        return 0;
    grid[row][col] = 0;
    return 1 + helper(row + 1, col, grid) + helper(row, col + 1, grid) + helper(row - 1, col, grid) + helper(row, col - 1, grid);
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int farMax = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j])
            {
                int currMax = helper(i, j, grid);
                farMax = max(currMax, farMax);
            }
        }
    }
    return farMax;
}
};