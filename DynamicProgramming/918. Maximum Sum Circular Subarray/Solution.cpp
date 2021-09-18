class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int currMax = 0, maxx = INT_MIN, currMin = 0, minn = INT_MAX, total = 0;

        for (int a : nums)
        {
            currMax = max(a, currMax + a);
            maxx = max(maxx, currMax);
            currMin = min(a, currMin + a);
            minn = min(minn, currMin);
            total += a;
        }

        return maxx > 0 ? max(maxx, total - minn) : maxx;
    }
};
