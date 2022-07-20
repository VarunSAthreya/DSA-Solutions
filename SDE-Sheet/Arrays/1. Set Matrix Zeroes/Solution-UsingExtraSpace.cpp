class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> rows(row);
        vector<int> cols(col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                if (rows[i] == 1 || cols[j] == 1)
                {
                    matrix[i][j] = 0;
                }
        }
    }
};
