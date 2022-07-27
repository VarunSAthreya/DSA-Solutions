class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        int n = intervals.size();

        if (n == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector<int> temp{intervals[0][0], intervals[0][1]};

        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] <= temp[1])
            {
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else
            {
                res.push_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }

        res.push_back(temp);

        return res;
    }
};
