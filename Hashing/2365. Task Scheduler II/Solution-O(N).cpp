class Solution
{
public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, long long> m;
        int n = tasks.size();
        long long res = 0;

        if (!n) // no tasks
            return res;

        for (int i : tasks)
        {
            if (m.find(i) == m.end()) // not present
            {
                m[i] = 1 + space + res; // the next index for which this task can be scheduled
                res++;
            }
            else
            {
                if (m[i] > res) // if the next index for which this task can be scheduled is greater than current index
                {
                    res = m[i]; // update current index
                }

                m[i] = res + 1 + space; // update next index for which this task can be scheduled
                res++;
            }
        }

        return res;
    }
};
