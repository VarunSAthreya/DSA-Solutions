class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        if (nums.size() < 1)
            return nums.size();

        unordered_set<int> st;

        for (int i : nums)
            st.insert(i);

        int res = 0;
        for (int num : nums)
        {
            if (st.find(num - 1) == st.end())
            {
                int currNum = num;
                int currStreak = 1;

                while (st.find(currNum++) != st.end())
                    currStreak++;

                res = max(res, currStreak);
            }
        }
        return res;
    }
};
