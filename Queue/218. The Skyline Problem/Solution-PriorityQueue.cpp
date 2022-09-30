class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        int cur = 0, cur_X, cur_H = -1, len = buildings.size();
        priority_queue<vector<int>> liveBlg;

        while (cur < len || !liveBlg.empty())
        {
            cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top()[1];

            if (cur >= len || buildings[cur][0] > cur_X)
            {
                while (!liveBlg.empty() && (liveBlg.top()[1] <= cur_X))
                    liveBlg.pop();
            }
            else
            {
                cur_X = buildings[cur][0];
                while (cur < len && buildings[cur][0] == cur_X)
                {
                    liveBlg.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            }

            cur_H = liveBlg.empty() ? 0 : liveBlg.top()[0];
            if (res.empty() || (res.back()[1] != cur_H))
                res.push_back({cur_X, cur_H});
        }

        return res;
    }
};
