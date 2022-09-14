class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());

        int total_days = 0;
        for (int i = 0; i < events.size(); i++)
        {
            total_days = max(total_days, events[i][1]);
        }

        int day = 1, count = 0, event_id = 0;
        int len = events.size();

        while (day <= total_days)
        {
            if (event_id < events.size() && (pq.empty()))
            {
                day = events[event_id][0];
            }

            while (event_id < len && events[event_id][0] <= day)
            {
                pq.push(events[event_id][1]);
                event_id += 1;
            }

            while (!pq.empty() && pq.top() < day)
                pq.pop();

            if (!pq.empty())
            {
                pq.pop();
                count += 1;
            }
            else if (event_id >= len)
                break;

            day += 1;
        }

        return count;
    }
};
