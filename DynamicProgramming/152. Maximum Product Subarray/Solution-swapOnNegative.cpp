class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // store the result that is the max we have found so far
        int res = nums[0];
        // maxx/minn stores the max/min product of
        // subarray that ends with the current number A[i]
        int maxx = nums[0], minn = nums[0];
        for (int i = 1; i < n; i++)
        {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (nums[i] < 0)
                swap(maxx, minn);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            maxx = max(nums[i], maxx * nums[i]);
            minn = min(nums[i], minn * nums[i]);

            // the newly computed max value is a candidate for our global result
            res = max(res, maxx);
        }

        return res;
    }
};
