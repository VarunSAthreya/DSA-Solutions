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

// OR:

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int i : nums)
        {
            mpp[i]++;
        }

        int n = nums.size();
        vector<int> res;
        for (auto pr : mpp)
        {
            if (pr.second > n / 3)
            {
                res.push_back(pr.first);
            }
        }

        return res;
    }
};
