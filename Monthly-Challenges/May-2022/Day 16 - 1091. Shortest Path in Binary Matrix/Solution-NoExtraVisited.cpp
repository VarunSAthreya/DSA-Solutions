class Solution
{
public:
    bool isValid(vector<vector<int>> &grid, int i, int j, int n)
    {

        return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == 0);
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        int res = 0;
        int n = grid.size();

        if (grid[0][0] == 0)
        {
            q.push({0, 0});
            grid[0][0] = 1;
        }

        while (!q.empty())
        {
            int size = q.size();
            res++;

            for (int i = 0; i < size; i++)
            {
                auto pr = q.front();
                q.pop();

                int f = pr.first;
                int s = pr.second;

                // NOTE: Just faster execution no actual difference in logic
                grid[f][s] = 1;

                if (f == n - 1 && s == n - 1)
                    return res;

                for (int j = f - 1; j <= f + 1; j++)
                {
                    for (int k = s - 1; k <= s + 1; k++)
                    {
                        if (isValid(grid, j, k, n))
                        {
                            q.push({j, k});
                            grid[j][k] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
