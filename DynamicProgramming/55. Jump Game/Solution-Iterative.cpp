// Solution 1
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        int step = nums[0];
        for (int i = 1; i < size; ++i)
        {
            step--;
            if (step < 0)
                return false;
            if (nums[i] > step)
                step = nums[i];
        }
        return true;
    }
};

// Solution 2
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
    }
};
