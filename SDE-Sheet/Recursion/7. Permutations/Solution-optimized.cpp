class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ds(nums.begin(), nums.end());
        vector<bool> freq(nums.size());
        solve(nums, res, ds, 0);
        return res;
    }
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &ds, int ind)
    {
        if (ind == nums.size())
        {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {

            swap(ds[i], ds[ind]);
            solve(nums, res, ds, ind + 1);
            swap(ds[i], ds[ind]);
        }
    }
};
