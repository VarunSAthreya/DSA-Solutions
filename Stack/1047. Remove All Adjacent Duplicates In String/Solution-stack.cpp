class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        int i = 0;
        int j = res.size() - 1;
        while (i < j)
        {
            swap(res[i++], res[j--]);
        }
        return res;
    }
};
