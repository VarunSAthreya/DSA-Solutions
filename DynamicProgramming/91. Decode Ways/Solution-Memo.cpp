class Solution
{
public:
    unordered_map<string, int> m;
    int numDecodings(string s)
    {
        if (0 == s.size())
        {
            return 1;
        }
        if (m.count(s))
            return m[s];

        long long tmp = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int num = s[i] - '0';
            tmp = tmp * 10 + num;
            if (tmp == 0)
                return 0;

            if (tmp >= 1 && tmp <= 26)
            {
                res += numDecodings(s.substr(i + 1));
            }
            else if (tmp > 26)
                break;
        }
        m[s] = res;
        return res;
    }
};
