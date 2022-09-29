
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comparator);

        int maxDeadline = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        vector<int> slots(maxDeadline + 1, -1);
        // fill(slots.begin(), slots.end(),-1);

        int jobCount = 0, jobProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = arr[i].id;
                    jobCount++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans(2);
        ans[0] = jobCount;
        ans[1] = jobProfit;

        return ans;
    }
};
