class Solution
{
public:
    int mod = 1e9 + 7;
    int helper(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n == 0 || target <= 0)
            return n == target;

        if (dp[n][target] != -1)
            return dp[n][target];

        dp[n][target] = 0; // as addition is done below, so initialize with 0 & to avoid multiple calls
        for (int i = 1; i <= k; i++)
        {
            dp[n][target] = (dp[n][target] + helper(n - 1, k, target - i, dp)) % mod;
        }

        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // set -1 to avoid multiple calls
        return helper(n, k, target, dp);
    }
};
