class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        // dp[i] = the least number of perfect square numbers
        // which sum to i. Since dp is a static vector, if
        // dp.size() > n, we have already calculated the result
        // during previous function calls and we can just return the result now.
        static vector<int> dp({0});

        // While dp.size() <= n, we need to incrementally
        // calculate the next result until we get the result for n.
        while (dp.size() <= n)
        {
            int m = dp.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i * i <= m; i++)
                cntSquares = min(cntSquares, dp[m - i * i] + 1);

            dp.push_back(cntSquares);
        }

        return dp[n];
    }
};
