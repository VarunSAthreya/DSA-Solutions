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
        vector<int> visited(10e5 + 1, 0);
        int res = 0;

        for (auto v : events)
        {
            if (visited[v[0]] == 0)
            {
                res++;
                visited[v[0]]++;
            }
            else
            {
                for (int i = v[0] + 1; i <= v[1]; i++)
                {
                    if (visited[i] == 0)
                    {
                        visited[i]++;
                        res++;
                        break;
                    }
                }
            }
        }

        return res;
    }
};
