#include <bits/stdc++.h>

class NumMatrix
{
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
                // current prefix = current cell value + left prefix value + top prefix cell - top left prefix value as it is counted twice
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1++, row2++, col1++, col2++;
        int bottomRight = prefix[row2][col2];
        int above = prefix[row1 - 1][col2];
        int left = prefix[row2][col1 - 1];
        int topLeft = prefix[row1 - 1][col1 - 1];

        return bottomRight - above - left + topLeft;
    }
};
