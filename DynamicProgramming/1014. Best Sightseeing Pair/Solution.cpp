class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int curr = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, curr + values[i] - i); // find difference and store
            curr = max(curr, i + values[i]);      // maximize the values[i] and i sum
            // Expanded form:
            // int temp = curr + values[i] - i;
            // res = max(res, temp);
            // if (i + values[i] > curr)
            // {
            //     curr = i + values[i];
            // }
        }
        return res;
    }
};
