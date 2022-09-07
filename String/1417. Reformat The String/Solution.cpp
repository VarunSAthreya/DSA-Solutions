class Solution
{
public:
    string reformat(string s)
    {
        vector<char> alpha, num;
        for (char ch : s)
        {
            if (isdigit(ch))
                num.push_back(ch);
            else
                alpha.push_back(ch);
        }
        int n = alpha.size(), m = num.size();
        if (std::abs(n - m) > 1)
            return "";
        if (n > m)
            swap(alpha, num);

        string res = "";
        int i;
        for (i = 0; i < alpha.size(); i++)
        {
            res += num[i];
            res += alpha[i];
        }

        if (i < num.size())
            res += num[i];
        return res;
    }
};
