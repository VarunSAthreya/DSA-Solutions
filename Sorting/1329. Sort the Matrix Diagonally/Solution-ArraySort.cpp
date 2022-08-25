class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        // row = 0
        for (int col = 0; col < n; col++)
        {
            sort(mat, 0, col, m, n);
        }

        // col = 0
        for (int row = 1; row < m; row++)
        {
            sort(mat, row, 0, m, n);
        }

        return mat;
    }

    void sort(vector<vector<int>> &mat, int row, int col, int m, int n)
    {
        int r = row, c = col;
        vector<int> v;
        while (r < m && c < n)
        {
            v.push_back(mat[r++][c++]);
        }

        std::sort(v.begin(), v.end());

        int ind = 0;
        r = row, c = col;

        while (r < m && c < n)
        {
            mat[r++][c++] = v[ind++];
        }
    }
};
