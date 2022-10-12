class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 3; i >= 0; i--) // n-3 as we sum (i,i+1,i+2)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2]) // condition for valid perimeter of a triangle
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0; // if no valid triangle found
    }
};
