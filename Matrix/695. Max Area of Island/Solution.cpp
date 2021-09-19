// using direction array and sen matrix

class Solution
{
public:
    vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int dfs(vector<vector<int>> &grid, vector<vector<int>> &seen, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || seen[r][c] || grid[r][c] != 1)
        {
            return 0;
        }
        int maxArea = 1;
        seen[r][c] = 1;
        for (auto dir : directions)
        {
            int newR = r + dir[0];
            int newC = c + dir[1];
            maxArea += dfs(grid, seen, newR, newC);
        }
        return maxArea;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), 0));
        if (grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && !seen[i][j])
                {
                    res = max(res, dfs(grid, seen, i, j));
                }
            }
        }

        return res;
    }
};

// Barebones
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    max_area = max(max_area, AreaOfIsland(grid, i, j));
        return max_area;
    }

    int AreaOfIsland(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i + 1, j) + AreaOfIsland(grid, i - 1, j) + AreaOfIsland(grid, i, j - 1) + AreaOfIsland(grid, i, j + 1);
        }
        return 0;
    }
};
