class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0, minn = INT_MAX;
        for (int p : prices)
        {
            minn = min(minn, p);
            res = max(res, p - minn);
        }
        return res;
    }
};
