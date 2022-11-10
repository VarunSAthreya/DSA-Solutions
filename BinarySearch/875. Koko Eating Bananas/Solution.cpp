class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r)
        {
            int m = (l + r) / 2;
            long total = 0;
            for (int p : piles)
                total += ceil((double)p / m); // or (p + m - 1) / m;

            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
