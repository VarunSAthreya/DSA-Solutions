class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;
        vector<int> vec;
        for (auto i : nums)
        {
            mpp[i]++;
            if (mpp[i] > nums.size() / 3)
            {
                if (find(vec.begin(), vec.end(), i) == vec.end())
                {
                    vec.push_back(i);
                }
            }
        }

        return vec;
    }
};
