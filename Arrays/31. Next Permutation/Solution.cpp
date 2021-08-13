class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int ind1 = -1, ind2 = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                ind1 = i - 1;
                break;
            }
        }
        // OR:
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     if (nums[i] < nums[i + 1])
        //     {
        //         ind1 = i - 1;
        //         break;
        //     }
        // }

        if (ind1 != -1)
        {
            for (int i = n - 1; i > 0; i--)
            {
                if (nums[i] > nums[ind1])
                {
                    ind2 = i;
                    break;
                }
            }
            swap(nums[ind1], nums[ind2]);
        }
        int left = ind1 + 1, right = n - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
