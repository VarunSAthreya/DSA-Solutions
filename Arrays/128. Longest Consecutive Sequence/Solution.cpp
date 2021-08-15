class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 1)
            return n;
        set<int> st;
        for (int i : nums)
        {
            st.insert(i);
        }

        int ans = 1;
        for (int num : nums)
        {
            if (st.find(num - 1) == st.end())
            {
                int currNum = num;
                int currStreak = 1;

                while (st.find(currNum + 1) != st.end())
                {
                    currNum++;
                    currStreak++;
                }
                ans = max(ans, currStreak);
            }
        }
        return ans;
    }
};
