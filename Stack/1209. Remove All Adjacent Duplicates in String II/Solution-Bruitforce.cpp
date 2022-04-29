class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        string res = s;
        int n = res.size();
        int i = 0;
        while (i < n)
        {
            bool flag = true;
            char ch = res[i];
            for (int j = i + 1; j < i + k; j++)
            {
                if (res[j] != ch)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res = res.substr(0, i) + res.substr(i + k);
                i = 0;
                n = res.size();
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};
