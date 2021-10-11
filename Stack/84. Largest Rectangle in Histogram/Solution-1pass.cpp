class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        int n = heights.size();

        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                res = max(res, height * width);
            }
            st.push(i);
        }

        return res;
    }
};
