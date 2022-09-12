class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        if (k == 0 || n == 0)
            return 0;

        long mod = 1e9 + 7;
        vector<pair<int, int>> per(n);

        for (int i = 0; i < n; i++)
            per[i] = {efficiency[i], speed[i]};

        sort(per.begin(), per.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        long sumS = 0, res = 0;
        for (auto &[e, s] : per)
        {
            pq.push(s);
            sumS += s;
            if (pq.size() > k)
            {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9 + 7);
    }
};
