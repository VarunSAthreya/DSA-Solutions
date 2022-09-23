class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        vector<vector<int>> dp(7000 + 1, vector<int>(2, -1));
        unordered_set<int> s(forbidden.begin(), forbidden.end());

        int res = helper(s, a, b, x, dp, 0, 0);
        return res >= 1e9 ? -1 : res;
    }

    int helper(unordered_set<int> &s, int a, int b, int x, vector<vector<int>> &dp, int ind, bool back)
    {
        if (ind == x)
            return 0;

        if (ind < 0 || s.count(ind) || ind > 6000)
            return 1e9;

        if (dp[ind][back] != -1)
            return dp[ind][back];

        // forward
        dp[ind][back] = 1 + helper(s, a, b, x, dp, ind + a, 0);

        // back
        if (!back)
        {
            dp[ind][back] = min(dp[ind][back], 1 + helper(s, a, b, x, dp, ind - b, 1));
        }

        return dp[ind][back];
    }
};
