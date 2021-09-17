class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = 10001;
        vector<int> buckets(n);
        for (int num : nums)
        {
            buckets[num] += num;
        }
        vector<int> dp(n, 0);
        dp[1] = buckets[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(buckets[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
