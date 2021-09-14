class Solution
{
public:
    int solve(vector<int> &nums, vector<int> &dp, int ind)
    {
        if (ind == nums.size() - 1)
            return nums[ind];
        else if (ind >= nums.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        dp[ind] = max(solve(nums, dp, ind + 1), solve(nums, dp, ind + 2) + nums[ind]);
        return dp[ind];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return max(solve(nums, dp, 0), solve(nums, dp, 1));
    }
};
