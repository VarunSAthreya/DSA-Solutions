class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;

        int n = s.length();
        int left = 0, right = 0;
        int count = 0;

        while (left < n && right < n)
        {
            if (st.find(s[right]) == st.end())
            {
                st.insert(s[right]);
                count = max(count, right - left + 1);
                right++;
            }
            else
            {
                while (st.find(s[right]) != st.end())
                {
                    st.erase(s[left]);
                    left++;
                }
                count = max(count, right - left + 1);
            }
        }

        return count;
    }
};
