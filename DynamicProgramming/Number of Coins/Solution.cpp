class Solution
{

public:
    int minCoins(int coins[], int m, int v)
    {
        vector<int> dp(v + 1, v + 1);
        dp[0] = 0;

        for (int i = 1; i <= v; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[v] > v ? -1 : dp[v];
    }
};
