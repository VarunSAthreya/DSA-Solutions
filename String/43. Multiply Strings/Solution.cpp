class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int p1 = i + j, p2 = i + j + 1;
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[p2] - '0');
                ans[p2] = sum % 10 + '0';
                ans[p1] += sum / 10;
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            if (ans[i] != '0')
            { // first non 0 digit
                return ans.substr(i);
            }
        }
        return "0";
    }
};
