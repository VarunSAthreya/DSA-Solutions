class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dict.count(s.substr(j, i - j)) && dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
