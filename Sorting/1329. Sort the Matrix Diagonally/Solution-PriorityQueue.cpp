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
        priority_queue<int, vector<int>, greater<int>> pq;
        while (r < m && c < n)
        {
            pq.push(mat[r++][c++]);
        }

        r = row, c = col;

        while (r < m && c < n)
        {
            mat[r++][c++] = pq.top();
            pq.pop();
        }
    }
};
