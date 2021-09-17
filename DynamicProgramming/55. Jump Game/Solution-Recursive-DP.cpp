class Solution
{
public:
    int find(vector<int> &nums, vector<int> &dp, int ind)
    {
        if (ind >= nums.size() - 1)
            return 1;
        if (nums[ind] == 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        for (int i = 1; i <= nums[ind]; i++)
        {
            int res = find(nums, dp, ind + i);
            if (res == 1)
            {
                dp[ind] = 1;
                return dp[ind];
            }
        }
        dp[ind] = 0;

        return dp[ind];
    }

    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return true;
        vector<int> dp(n, -1);
        return find(nums, dp, 0) == 1;
    }
};
