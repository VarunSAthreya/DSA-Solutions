class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        vector<vector<int>> visited(7000 + 1, vector<int>(2, 0));
        unordered_set<int> s(forbidden.begin(), forbidden.end());

        queue<vector<int>> q;
        q.push({0, 0}); // 0 == false

        visited[0][0] = 1;
        visited[0][1] = 1;
        int res = 0;

        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto v = q.front();
                q.pop();
                int ind = v[0], flag = v[1];

                if (ind == x)
                    return res;

                int forward = ind + a, backward = ind - b;

                if (forward < 6000 && !s.count(forward) && visited[forward][0] == 0)
                {
                    q.push({forward, 0}); // 0 == false
                    visited[forward][0] = 1;
                }
                if (backward >= 0 && !s.count(backward) && visited[backward][1] == 0 && !flag)
                {
                    q.push({backward, 1}); // 1 == true
                    visited[backward][1] = 1;
                }
            }

            res++;
        }

        return -1;
    }
};
