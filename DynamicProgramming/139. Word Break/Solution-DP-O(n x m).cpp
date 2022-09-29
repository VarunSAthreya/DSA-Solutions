class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (auto ss : wordDict)
            {
                if (i + ss.size() - 1 < n && s.substr(i, ss.size()) == ss)
                {
                    dp[i] = 1 && dp[i + ss.size()];
                    if (dp[i])
                        break;
                }
            }
        }

        return dp[0];
    }
};
