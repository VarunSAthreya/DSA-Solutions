// * Using vector
class Solution
{
public:
    bool isValid(vector<int> &sm, vector<int> &lg)
    {
        return sm[0] < lg[0] & sm[1] < lg[1];
    }

    int maxEnvelopes(vector<vector<int>> &env)
    {
        sort(env.begin(), env.end());
        int n = env.size();
        vector<int> dp(n, 1);
        int res = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isValid(env[i], env[j]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

//* Using Stack
class Solution
{
public:
    bool isValid(vector<int> &sm, vector<int> &lg)
    {
        return sm[0] < lg[0] & sm[1] < lg[1];
    }

    int maxEnvelopes(vector<vector<int>> &env)
    {
        sort(env.begin(), env.end());
        int n = env.size();
        vector<int> dp(n, 1);
        set<pair<int, int>, greater<pair<int, int>>> st;
        int res = 1;
        st.insert({1, n - 1});

        for (int i = n - 2; i >= 0; i--)
        {
            for (auto itr = st.begin(); itr != st.end(); itr++)
            {
                auto pr = *itr;
                if (isValid(env[i], env[pr.second]))
                {
                    dp[i] = 1 + pr.first;
                    break;
                }
            }
            st.insert({dp[i], i});
            res = max(res, dp[i]);
        }

        return res;
    }
};
