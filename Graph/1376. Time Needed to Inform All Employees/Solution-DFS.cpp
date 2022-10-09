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

        return dfs(headID, informTime, graph);
    }

    int dfs(int headID, vector<int> &informTime, vector<vector<int>> &graph)
    {
        int res = 0;
        for (int i : graph[headID])
        {
            res = max(res, dfs(i, informTime, graph));
        }

        return res + informTime[headID];
    }
};
