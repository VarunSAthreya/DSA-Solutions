class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        int x, y, z;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (x = 1; x <= n; ++x)
            for (z = target; z >= (x == n ? target : 0); --z)
                for (y = z - 1, dp[z] = 0; y >= max(0, z - k); --y)
                    dp[z] = (dp[z] + dp[y]) % 1000000007;

        return dp[target];
    }
};
