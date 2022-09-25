class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<string> res;
        string s = "";

        for (int i = 1; i <= n; i++)
            s += to_string(i);

        solve(s, res, 0);

        sort(res.begin(), res.end());

        return res[k - 1];
    }

    void solve(string &s, vector<string> &res, int ind)
    {
        if (s.size() == ind)
        {
            res.push_back(s);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            swap(s[i], s[ind]);
            solve(s, res, ind + 1);
            swap(s[i], s[ind]);
        }
    }
};
