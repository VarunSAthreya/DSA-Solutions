class Solution
{
public:
    int m, n;

    int maximumScore(vector<int> &nums, vector<int> &muls)
    {
        n = nums.size();
        m = muls.size();

        vector<vector<int>> memo(1000, vector<int>(1000, INT_MIN));

        return dp(0, 0, nums, muls, memo);
    }
    int dp(int l, int i, vector<int> &nums, vector<int> &muls, vector<vector<int>> &memo)
    {
        if (i == m)
            return 0; // Picked enough m elements

        if (memo[l][i] != INT_MIN)
            return memo[l][i];

        int pickLeft = dp(l + 1, i + 1, nums, muls, memo) + nums[l] * muls[i];            // Pick the left side
        int pickRight = dp(l, i + 1, nums, muls, memo) + nums[n - (i - l) - 1] * muls[i]; // Pick the right side

        return memo[l][i] = max(pickLeft, pickRight);
    }
};
