class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<vector<int>> q;

        // {x,y,path,k remaining}
        q.push({0, 0, 0, k});

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            int x = v[0], y = v[1];

            if (x >= n || x < 0 || y >= m || y < 0) // out of bounds
                continue;

            if (x == n - 1 && y == m - 1) // reached destination
                return v[2];

            if (grid[x][y] == 1) // obstacle present
            {
                if (v[3] > 0) // k remaining
                    v[3]--;
                else // no k remaining
                    continue;
            }

            if (visited[x][y] >= v[3]) // already visited with more k remaining
                continue;

            visited[x][y] = v[3];

            for (auto dir : directions)
                q.push({x + dir[0], y + dir[1], v[2] + 1, v[3]});
        }

        return -1;
    }
};
