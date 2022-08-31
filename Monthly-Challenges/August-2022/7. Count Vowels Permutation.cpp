class Solution
{
public:
    int countVowelPermutation(int n)
    {
        vector<vector<long>> dp(n + 1, vector<long>(5, 0));
        int MOD = 1e9 + 7;
        int a = 0, e = 1, i = 2, o = 3, u = 4;

        /* dp[i][j] denotes the number of valid strings of length i */

        dp[1] = {1, 1, 1, 1, 1};

        for (int x = 2; x <= n; x++)
        {
            dp[x][a] = (dp[x - 1][e] + dp[x - 1][i] + dp[x - 1][u]) % MOD;
            dp[x][e] = (dp[x - 1][a] + dp[x - 1][i]) % MOD;
            dp[x][i] = (dp[x - 1][e] + dp[x - 1][o]) % MOD;
            dp[x][o] = dp[x - 1][i];
            dp[x][u] = (dp[x - 1][i] + dp[x - 1][o]) % MOD;
        }

        int res = 0;
        for (int i : dp[n])
            res = (res + i) % MOD;

        return res;
    }
};
