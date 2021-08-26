class Solution
{
public:
    void find(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        find(ind + 1, nums, ans, ds);
        ds.pop_back();
        find(ind + 1, nums, ans, ds);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        find(0, nums, ans, ds);

        return ans;
    }
};
