class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> st;
        int curMin = nums[0];

        for (int i : nums)
        {
            while (!st.empty() && i >= st.top().first)
                st.pop();

            if (!st.empty() && i > st.top().second)
                return true;

            st.push({i, curMin});
            curMin = min(curMin, i);
        }
        return false;
    }
};
