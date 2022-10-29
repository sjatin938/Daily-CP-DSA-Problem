//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   void numIslands(vector<vector<char>> &grid, int row, int col) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1') {
        return;
    }
    grid[row][col] = '0';
    numIslands(grid, row + 1, col);
    numIslands(grid, row, col + 1);
    numIslands(grid, row - 1, col);
    numIslands(grid, row, col - 1);
    numIslands(grid, row + 1, col + 1);
    numIslands(grid, row + 1, col - 1);
    numIslands(grid, row - 1, col + 1);
    numIslands(grid, row - 1, col - 1);
    return;


}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != '0') {
                numIslands(grid, i, j);
                count++;
            }

        }
    }
    return count;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends