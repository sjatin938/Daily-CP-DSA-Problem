class Solution
{
    public:
        void rotate(vector<vector < int>> &matrix)
        {
            int n = matrix.size() - 1;
            for (int i = 0; i < matrix.size() / 2; i++)
            {
                swap(matrix[i], matrix[n - i]);
            }
            for (int row = 0; row < matrix.size(); row++)
            {
                for (int col = 0; col <= row; col++)
                {
                    swap(matrix[row][col], matrix[col][row]);
                }
            }
        }
};