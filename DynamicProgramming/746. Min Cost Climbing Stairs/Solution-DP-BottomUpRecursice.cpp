class Solution
{
public:
    int solve(vector<int> &cost, vector<int> &dp, int ind)
    {
        if (ind >= cost.size())
            return 0;
        if (ind == cost.size() - 1)
            return cost[ind];

        if (dp[ind] != -1)
            return dp[ind];

        dp[ind] = cost[ind] + min(solve(cost, dp, ind + 1), solve(cost, dp, ind + 2));

        return dp[ind];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1, -1);
        return min(solve(cost, dp, 0), solve(cost, dp, 1));
    }
};
