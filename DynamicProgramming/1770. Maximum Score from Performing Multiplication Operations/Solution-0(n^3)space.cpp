class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int res = 0, n = nums.size(), m = multipliers.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(m, -1)));
        return helper(nums, multipliers, dp, 0, m, 0, n - 1);
    }

    int helper(vector<int> &nums, vector<int> &multipliers, vector<vector<vector<int>>> &dp, int ind, int m, int l, int r)
    {
        if (ind >= m)
            return 0;
        if (dp[l][r][ind] != -1)
            return dp[l][r][ind];

        int pickLeft = helper(nums, multipliers, dp, ind + 1, m, l + 1, r) + nums[l] * multipliers[ind];  // Pick the left side
        int pickRight = helper(nums, multipliers, dp, ind + 1, m, l, r - 1) + nums[r] * multipliers[ind]; // Pick the right side
        return dp[l][r][ind] = max(pickLeft, pickRight);
    }
};
