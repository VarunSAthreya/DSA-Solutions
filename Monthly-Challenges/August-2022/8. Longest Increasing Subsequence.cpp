class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n);
        ans[n - 1] = 1;
        int res = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int cnt = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                    cnt = max(cnt, ans[j]);
            }
            ans[i] = cnt + 1;
            res = max(res, ans[i]);
        }
        return res;
    }
};
