class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict);
    }

    bool solve(string s, unordered_set<string> &dict)
    {
        int n = s.size();
        if (n == 0)
            return true;

        for (int i = 1; i <= n; i++)
        {
            if (dict.count(s.substr(0, i)) && solve(s.substr(i), dict))
                return true;
        }

        return false;
    }
};
