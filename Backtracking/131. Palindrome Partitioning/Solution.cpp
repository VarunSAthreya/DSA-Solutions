class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> ds;
        solve(s, res, ds, 0);
        return res;
    }
    void solve(string s, vector<vector<string>> &res, vector<string> &ds, int ind)
    {
        if (ind == s.size())
        {
            res.push_back(ds);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                ds.push_back(s.substr(ind, i - ind + 1));
                solve(s, res, ds, i + 1);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
};
