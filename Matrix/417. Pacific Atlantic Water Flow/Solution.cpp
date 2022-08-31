class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        set<pair<int, int>> pac, atl;
        int rows = heights.size(), cols = heights[0].size();

        for (int c = 0; c < cols; c++)
        {
            dfs(0, c, pac, heights, heights[0][c]);
            dfs(rows - 1, c, atl, heights, heights[rows - 1][c]);
        }

        for (int r = 0; r < rows; r++)
        {
            dfs(r, 0, pac, heights, heights[r][0]);
            dfs(r, cols - 1, atl, heights, heights[r][cols - 1]);
        }

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
                if (pac.count({r, c}) && atl.count({r, c}))
                    res.push_back({r, c});
        }

        return res;
    }

    vector<vector<int>> directions{{0, +1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int r, int c, set<pair<int, int>> &visited, vector<vector<int>> &heights, int prevHeight)
    {
        if (visited.count({r, c}) || r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || heights[r][c] < prevHeight)
            return;

        visited.insert({r, c});
        for (auto dir : directions)
        {
            dfs(r + dir[0], c + dir[1], visited, heights, heights[r][c]);
        }
    }
};
