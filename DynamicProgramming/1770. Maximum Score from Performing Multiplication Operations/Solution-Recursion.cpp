class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int res = 0, n = nums.size(), m = multipliers.size();
        return helper(nums, multipliers, 0, 0, m, 0, n - 1);
    }

    int helper(vector<int> &nums, vector<int> &multipliers, int sum, int ind, int m, int l, int r)
    {
        if (ind >= m)
            return sum;

        int tmp1 = sum + nums[l] * multipliers[ind];
        int tmp2 = sum + nums[r] * multipliers[ind];
        sum = max(helper(nums, multipliers, tmp1, ind + 1, m, l + 1, r), helper(nums, multipliers, tmp2, ind + 1, m, l, r - 1));
        return sum;
    }
};
