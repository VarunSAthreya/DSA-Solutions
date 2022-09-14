class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }

    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), cmp);
        set<int> days;
        int n = events.size();
        int mx = events[n - 1][1];

        for (int i = 1; i <= mx; i++)
            days.insert(i);
        int res = 0;

        for (auto event : events)
        {
            int s = event[0], e = event[1];
            auto it = days.lower_bound(s);
            if (!(it == days.end() || *it > e))
            {
                res++;
                days.erase(it);
            }
        }

        return res;
    }
};
