class Solution {
public:
   int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, solve(matrix, mem, i, j));
            }
        }
        return res * res;
    }
    
    int solve(vector<vector<char>>& matrix, vector<vector<int>>& mem, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        if (matrix[i][j] == '0') return mem[i][j] = 0;
        mem[i][j] = min(min(solve(matrix, mem, i+1, j), solve(matrix, mem, i, j+1)),
                        solve(matrix, mem, i+1, j+1)) + 1;
        return mem[i][j];
    }
};