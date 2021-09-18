class Solution
{
public:
    int findMin(vector<int> &dp, int i, int n, int limit)
    {

        int minn = INT_MAX - 1;
        for (int j = i + 1; j <= i + n && j < limit; j++)
        {
            minn = min(minn, dp[j]);
        }
        return minn;
    }

    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        vector<int> dp(n, INT_MAX);

        dp[n - 1] = 0;
        if (nums[n - 2] == 0)
            dp[n - 1] = INT_MAX;
        else
            dp[n - 2] = 1;

        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] >= (n - 1 - i))
                dp[i] = 1;
            else
                dp[i] = findMin(dp, i, nums[i], n) + 1;
        }
        return dp[0];
    }
};
