class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) == 0)
                m[nums[i]] = i;
            else if (i - m[nums[i]] <= k)
                return true;
            else
                m[nums[i]] = i;
        }

        return false;
    }
};
