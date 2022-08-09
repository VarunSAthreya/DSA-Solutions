class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;
        for (auto i : nums)
        {
            mpp[i]++;
            if (mpp[i] > nums.size() / 2)
                return i;
        }

        return -1;
    }
};
