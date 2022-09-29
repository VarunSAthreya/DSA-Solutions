class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        string tmp;

        solve(s, dict, tmp, res);

        return res;
    }

    void solve(string s, unordered_set<string> &dict, string tmp, vector<string> &res)
    {

        int n = s.size();
        if (n == 0)
            res.push_back(tmp.substr(0, tmp.size() - 1));

        for (int i = 1; i <= n; i++)
        {
            if (dict.count(s.substr(0, i)))
                solve(s.substr(i), dict, tmp + s.substr(0, i) + " ", res);
        }
    }
};
