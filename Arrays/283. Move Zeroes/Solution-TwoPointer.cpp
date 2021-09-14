//  Find 0 and swap
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return;

        int p1 = 0, p2 = 0;
        while (p2 < n)
        {
            if (nums[p1] == 0)
            {
                swap(nums[p1], nums[p2]);
                p2++;
            }
            else
            {
                p1++;
                if (p1 > p2) // To make sure p1 dosent cross p2 on consecutive non-zero numbers
                {
                    p2 = p1 + 1;
                }
            }
        }
    }
};

// Swap at every instance

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return;

        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] == 0)
                j++;
            else
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};
