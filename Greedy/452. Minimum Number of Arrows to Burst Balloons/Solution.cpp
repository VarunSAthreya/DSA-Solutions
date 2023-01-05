class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int res = 0, arrow = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (res == 0 || points[i][0] > arrow)
            {
                res++;
                arrow = points[i][1];
            }
        }
        return res;
    }
};
