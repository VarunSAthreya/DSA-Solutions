class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int pos = 0, neg = 0, res = 0;
        for (int x : nums)
        {
            if (x == 0)
            {
                pos = 0, neg = 0;
            }
            else if (x > 0)
            {
                pos++;
                neg = neg ? neg + 1 : 0;
            }
            else
            {
                int temp = pos;
                pos = neg ? neg + 1 : 0;
                neg = temp + 1;
            }
            res = max(res, pos);
        }
        return res;
    }
};
