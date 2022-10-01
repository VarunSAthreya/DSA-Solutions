class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        vector<int> sub;
        helper(nums, n, st, sub, 0);

        vector<vector<int>> res;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            res.push_back(*it);
        }

        return res;
    }

    void helper(vector<int> &nums, int n, set<vector<int>> &st, vector<int> sub, int ind)
    {
        if (ind == n)
        {
            st.insert(sub);
            return;
        }

        sub.push_back(nums[ind]);
        helper(nums, n, st, sub, ind + 1);
        sub.pop_back();
        helper(nums, n, st, sub, ind + 1);
    }
};
