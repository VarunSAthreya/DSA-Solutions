class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int r = INT_MIN; // or r = 1000000000 (limit) and skip max(p)
        for (int p : piles)
            r = max(r, p);
        int l = 1;
        while (l < r)
        {
            int m = (l + r) / 2, total = 0;
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
