class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        map<int, int> m;
        for (int i : nums)
        {
            if (i % 2 == 0)
                m[i]++;
        }
        if (m.size() == 0)
            return -1;

        int res = -1, cnt = 0;
        for (auto pr : m)
        {
            if (cnt < pr.second)
            {
                cnt = pr.second;
                res = pr.first;
            }
        }

        return res;
    }
};
