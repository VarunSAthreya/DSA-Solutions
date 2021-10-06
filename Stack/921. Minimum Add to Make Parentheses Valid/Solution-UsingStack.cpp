class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        stack<int> st;
        int cnt = 0;
        for (char ch : s)
        {
            if (ch == '(')
                st.push('(');
            else
            {
                if (!st.empty())
                    st.pop();
                else
                    cnt++;
            }
        }
        return cnt + st.size();
    }
};
