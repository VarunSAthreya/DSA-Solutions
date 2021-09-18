class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prefix = 0, suffix = 0, res = nums[0];
        for (int i = 0; i < n; i++)
        {
            prefix = (prefix == 0 ? 1 : prefix) * nums[i];
            suffix = (suffix == 0 ? 1 : suffix) * nums[n - i - 1];

            res = max(res, max(prefix, suffix));
        }

        return res;
    }
};
