class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 3)
            return nums[0] + nums[1] + nums[2];

        int first, second, third;
        int res = nums[0] + nums[1] + nums[2];  // sum of first 3 as initial result
        for (first = 0; first < n - 2; first++) // n-2 as last 2 places can only be occupied by second and third
        {
            second = first + 1, third = n - 1;
            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                if (abs(target - res) > abs(target - sum))
                    res = sum;

                if (sum < target)
                    second++;
                else if (sum > target)
                    third--;
                else
                    return sum;
            }
        }

        return res;
    }
};
