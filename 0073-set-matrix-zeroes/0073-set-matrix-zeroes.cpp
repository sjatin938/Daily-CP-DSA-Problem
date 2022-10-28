class Solution {
public:
  
void setZeroes(vector<vector<int>> &matrix) {
    vector<bool> col(matrix[0].size(), 1);
    vector<bool> row(matrix.size(), 1);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                col[j] = 0;
                row[i] = 0;
            }
        }
    }
    for (int i = 0; i < row.size(); i++) {
        if (row[i] == 0) {
            for (int k = 0; k < matrix[0].size(); k++)
                matrix[i][k] = 0;
        }
    }
    for (int j = 0; j < col.size(); j++) {
        if (col[j] == 0) {
            for (auto &k: matrix) {
                k[j] = 0;
            }
        }
    }
}
};