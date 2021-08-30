class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ds;
        vector<bool> freq(nums.size());
        solve(nums, res, ds, freq);
        return res;
    }
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &ds, vector<bool> &freq)
    {
        if (ds.size() == nums.size())
        {
            res.push_back(ds);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = true;
                solve(nums, res, ds, freq);
                freq[i] = false;
                ds.pop_back();
            }
        }
    }
};
