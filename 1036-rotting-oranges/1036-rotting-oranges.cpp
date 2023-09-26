class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2)
                q.push({i, j});
            if (grid[i][j] == 1)
                fresh++;
        }
    int ans = -1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto x = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int r = x.first + dir[i];
                    int c = x.second + dir[i + 1];
                    if (r < m && r >= 0 && c < n && c >= 0 && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r, c});
                    }
                }
            }
        }
        ans++;
    }
    if (fresh != 0)
        return -1;
    if (ans == -1)
        return 0;
    return ans;
}
};