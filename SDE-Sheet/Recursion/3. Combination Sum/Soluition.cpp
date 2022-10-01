class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        if (candidates.size() == 0)
            return res;

        vector<int> ds;

        solve(candidates, target, res, ds, 0);
        return res;
    }
    void solve(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &ds, int ind)
    {

        if (ind == candidates.size() || target <= 0)
        {
            if (target == 0)
            {
                res.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], res, ds, ind);

        ds.pop_back();
        solve(candidates, target, res, ds, ind + 1);
    }
};
