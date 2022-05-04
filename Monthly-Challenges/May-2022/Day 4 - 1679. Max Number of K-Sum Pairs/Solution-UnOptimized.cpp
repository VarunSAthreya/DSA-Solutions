class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        map<int, vector<int>> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]].push_back(i);
        }

        int cnt = 0;
        for (auto pr : mpp)
        {
            int rem = k - pr.first;
            if (mpp.find(rem) != mpp.end())
            {
                auto v = mpp[rem];
                int add = min(pr.second.size(), v.size());
                if (rem == pr.first)
                    add /= 2;
                cnt += add;
                while (add--)
                {
                    pr.second.pop_back();
                    v.pop_back();
                }
                mpp[pr.first] = pr.second;
                mpp[rem] = v;
            }
        }
        return cnt;
    }
};
