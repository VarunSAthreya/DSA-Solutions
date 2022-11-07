// Stack
class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);

            while (st.size() && abs(st.top() - s[i + 1]) == 32)
            {
                i++;
                st.pop();
            }
        }

        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};

// String
class Solution
{
public:
    string makeGood(string s)
    {
        string res;

        for (int i = 0; i < s.size(); i++)
        {
            res.push_back(s[i]);

            while (res.size() && abs(res.back() - s[i + 1]) == 32)
            {
                res.pop_back();
                i++;
            }
        }

        return res;
    }
};
