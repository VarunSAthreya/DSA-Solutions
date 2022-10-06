class Solution
{
public:
    int MOD = 1e9 + 7;
    int n, m;

    int count(int r, int c, int cuts, vector<vector<int>> &apples, vector<vector<vector<int>>> &dp)
    {
        if (dp[r][c][cuts] != -1)
            return dp[r][c][cuts];

        if (cuts == 0) // when there is no more 'cuts' remaining to do then if the current cell has an apple then we can cut it
            return dp[r][c][cuts] = apples[r][c] > 0 ? 1 : 0;

        long long int rowsum = 0, colsum = 0;

        // Row Sum
        for (int i = r + 1; i < n; i++)
        {
            if (apples[r][c] - apples[i][c] > 0)
            {
                // the submatrix should conatain some apples && the number of apples presnet in the submatrix should be >= the number of cuts that will be made.
                rowsum = (rowsum + count(i, c, cuts - 1, apples, dp)) % MOD;
            }
        }

        // Col Sum
        for (int j = c + 1; j < m; j++)
        {
            if (apples[r][c] - apples[r][j] > 0)
            {
                colsum = (colsum + count(r, j, cuts - 1, apples, dp)) % MOD;
            }
        }

        return dp[r][c][cuts] = rowsum + colsum;
    }

    int ways(vector<string> &pizza, int k)
    {
        n = pizza.size(), m = pizza[0].size();

        vector<vector<int>> apples(n + 1, vector<int>(m + 1, 0));
        vector<vector<vector<int>>> dp = vector(n, vector(m, vector(k, -1)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                apples[i][j] = apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
                apples[i][j] += (pizza[i][j] == 'A'); // is apples presnet in the current cell
            }
        }

        return count(0, 0, k - 1, apples, dp);
    }
};
