class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return;

        k = k % n;

        vector<int> temp = nums;
        int ind = 0;

        for (int i = n - k; i < n; i++)
        {
            nums[ind++] = temp[i];
        }
        for (int i = 0; i < n - k; i++)
        {
            nums[ind++] = temp[i];
        }
    }
};
