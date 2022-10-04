class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++)
        {
            int ind = 0;
            int high = INT_MIN;
            for (int ind = 0; ind < k; ind++)
            {
                high = max(high, nums[i + ind]);
            }
            res.push_back(high);
        }

        return res;
    }
};
