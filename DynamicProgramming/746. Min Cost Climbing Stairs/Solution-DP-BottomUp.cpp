class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int fir = cost[0];
        int sec = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(fir, sec);
            fir = sec;
            sec = curr;
        }

        return min(fir, sec);
    }
};
