class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        if (candidates.size() == 0)
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        solve(candidates, target, res, ds, 0);
        return res;
    }
    void solve(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &ds, int ind)
    {

        if (target == 0)
        {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve(candidates, target - candidates[i], res, ds, i + 1);
            ds.pop_back();
        }
    }
};
