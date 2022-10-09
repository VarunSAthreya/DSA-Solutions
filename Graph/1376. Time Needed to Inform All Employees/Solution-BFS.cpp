class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                graph[manager[i]].push_back(i);
            }
        }

        int res = 0;
        queue<vector<int>> q;
        q.push({headID, 0});
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            int head = v[0], time = v[1];
            res = max(res, time);

            for (int child : graph[head])
                q.push({child, time + informTime[head]});
        }

        return res;
    }
};
