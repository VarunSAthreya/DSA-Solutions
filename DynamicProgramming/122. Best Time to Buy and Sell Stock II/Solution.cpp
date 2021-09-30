// Solution 1: (Sort of DP)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0, prev = prices[0];
        int n = prices.size();
        if (n <= 1)
            return 0;
        // prev: contains previous lowest value
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] > prices[i + 1])
            {
                // Checks when there is a peak at price and adds the difference and sets next min ie fall after the peak
                res += max(0, prices[i] - prev);
                prev = prices[i + 1];
            }
        }
        // When the peak is at the end
        res = max(res, res + prices[n - 1] - prev);
        return res;
    }
};

// Solution 2: (Greedy)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            res += max(0, prices[i + 1] - prices[i]); // sells whenever there is price hike
        }

        return res;
    }
};
