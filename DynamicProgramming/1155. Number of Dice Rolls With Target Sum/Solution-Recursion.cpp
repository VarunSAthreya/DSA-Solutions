class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        int res = 0;
        if (n == 0 || target <= 0)
            return n == target;
        for (auto i = 1; i <= k; ++i)
            res = (res + numRollsToTarget(n - 1, k, target - i)) % 1000000007;
        return res;
    }
};
