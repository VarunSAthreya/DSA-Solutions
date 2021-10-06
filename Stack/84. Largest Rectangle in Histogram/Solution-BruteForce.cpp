class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (heights[l] >= heights[i] && l > 0)
                l--;
            while (heights[r] >= heights[i] && r < n - 1)
                r++;

            if (heights[l] < heights[i])
                l++;
            if (heights[r] < heights[i])
                r--;

            res = max(res, heights[i] * (r - l + 1));
        }
        return res;
    }
};
