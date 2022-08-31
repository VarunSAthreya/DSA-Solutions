class Solution
{
public:
    vector<vector<int>> directions{{-1, 0}, {0, +1}, {1, 0}, {0, -1}};

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    solve(grid, i, j, n, m);
                }
            }
        }

        return cnt;
    }

    void solve(vector<vector<char>> &grid, int r, int c, int n, int m)
    {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0')
            return;

        grid[r][c] = '0';
        for (auto dir : directions)
        {
            solve(grid, r + dir[0], c + dir[1], n, m);
        }
    }
};
