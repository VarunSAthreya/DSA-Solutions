class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return;
        k = k % n;

        // Reverse start to n-k elements
        reverse(nums.begin(), nums.end() - k);
        // Reverse n-k  elements to n elements
        reverse(nums.end() - k, nums.end());
        // Reverse complete array
        reverse(nums.begin(), nums.end());
    }
};
