class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> q;
        int total = startFuel, cnt = 0, i = 0;

        while (total < target)
        {
            while (i < stations.size() && stations[i][0] <= total)
            {
                q.push(stations[i++][1]);
            }
            if (q.empty())
                return -1;

            total += q.top();
            q.pop();
            cnt++;
        }

        return cnt;
    }
};
