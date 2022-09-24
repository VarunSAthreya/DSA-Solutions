class Solution
{
public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, int> m;
        int n = tasks.size();
        long long res = 0;
        if (!n) // if 0 tasks
            return res;

        space++; // space between same tasks is space therefore we need to add 1 to space

        for (int i = 0; i < n; i++)
        {
            if (m.find(tasks[i]) == m.end()) // not present
            {
                res++;
                m[tasks[i]] = i;
            }
            else if (i - m[tasks[i]] >= space) // present and space is enough
            {
                res++;
                m[tasks[i]] = i;
            }
            else // present and space is not enough
            {
                int breaks = space - (i - m[tasks[i]]); // breaks needed
                res += breaks + 1;                      // add breaks and 1 for current task
                for (auto [k, v] : m)
                {
                    m[k] -= breaks; // reduce all previous tasks index by breaks as we added breaks
                }
                m[tasks[i]] = i; // update current task index
            }
        }

        return res;
    }
};
