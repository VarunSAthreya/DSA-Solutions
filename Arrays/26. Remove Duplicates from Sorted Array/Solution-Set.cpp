class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        for (auto i : nums)
            st.insert(i);

        int i = 0;
        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            nums[i] = *itr;
            i++;
        }

        return st.size();
    }
};
