class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (d > n)
            return -1;
        vector<vector<int>> dp(d + 1, vector<int>(n, -1));

        return dfs(jobDifficulty, dp, d, 0);
    }

    int dfs(vector<int> &jobDifficulty, vector<vector<int>> &dp, int d, int ind)
    {
        if (d == 1)
        {
            return *max_element(jobDifficulty.begin() + ind, jobDifficulty.end());
        }

        if (dp[d][ind] != -1)
            return dp[d][ind];

        int lmx = 0;
        int rmx = 0, res = INT_MAX;
        for (int i = ind; i < jobDifficulty.size() - d + 1; i++)
        {
            lmx = max(lmx, jobDifficulty[i]);
            rmx = dfs(jobDifficulty, dp, d - 1, i + 1);
            res = min(res, lmx + rmx);
        }

        return dp[d][ind] = res;
    }
};
