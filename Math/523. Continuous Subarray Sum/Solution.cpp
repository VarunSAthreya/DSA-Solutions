class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2)
            return false;
        unordered_map<int, int> m;
        m[0] = -1; // for the edge case if the sum of whole array is equal to K
        int runningSum = 0;
        for (int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            if (k > 0)
                runningSum %= k;

            if (m.count(runningSum))
            {
                if (i - m[runningSum] > 1)
                    return true;
            }
            else
            {
                m[runningSum] = i;
            }
        }

        return false;
    }
};
