class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &v : prerequisites)
        {
            adj[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
            if (degree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            n--;
            for (int next : adj[curr])
            {
                degree[next]--;
                if (degree[next] == 0)
                    q.push(next);
            }
        }

        return n == 0;
    }
};
