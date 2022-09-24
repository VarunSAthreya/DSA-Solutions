class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for (auto v : prerequisites)
        {
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);
        vector<bool> dp(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!dfs(adj, i, visited, dp))
                return false;
        }

        return true;
    }

    bool dfs(vector<vector<int>> &adj, int course, vector<bool> &visited, vector<bool> &dp)
    {
        if (visited[course])
            return dp[course];

        visited[course] = true;

        for (auto v : adj[course])
        {
            if (!dfs(adj, v, visited, dp))
                return false;
        }

        dp[course] = true;
        return true;
    }
};
