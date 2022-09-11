class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0)
                    tot++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            while (k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if (!rotten.empty())
                days++;
        }

        return tot == cnt ? days : -1;
    }
};

//  Different style of BFS

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int fresh = 1, rotten = 2;
        int res = 0, freshCnt = 0;

        queue<vector<int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == fresh)
                    freshCnt++;
                else if (grid[i][j] == rotten)
                    q.push({i, j});
            }
        }

        if (freshCnt == 0)
            return 0;

        while (!q.empty())
        {
            int size = q.size();
            res++;

            while (size--)
            {
                auto curr = q.front();
                q.pop();

                for (auto dir : directions)
                {
                    int r = curr[0] + dir[0], c = curr[1] + dir[1];
                    if (r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == fresh)
                    {
                        freshCnt--;
                        grid[r][c] = rotten;
                        q.push({r, c});
                    }
                }
            }
        }

        return freshCnt == 0 ? res - 1 : -1;
    }
};
