class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ele = nums[0], count = 0;

        for (auto i : nums)
        {
            if (i == ele)
            {
                count++;
                if (count > (nums.size() / 2))
                    return i;
            }
            else
            {
                count = 1;
                ele = i;
            }
        }
        return -1;
    }
};
