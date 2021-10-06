class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        int op = 0, cnt = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                op++;
            }
            else
            {
                if (op > 0)
                {
                    op--;
                }
                else
                {
                    cnt++;
                }
            }
        }
        return cnt + op;
    }
};
