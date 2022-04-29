class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.size();
        vector<pair<char, int>> st = {{'#', 0}};

        for (char c : s)
        {
            if (st.back().first == c)
            {
                st.back().second++;
                if (st.back().second == k)
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back({c, 1});
            }
        }
        string res = "";
        for (auto pr : st)
        {
            while (pr.second--)
            {
                res += pr.first;
            }
        }

        return res;
    }
};
