class Solution
{
public:
    int calculate(string s)
    {
        stack<int> nums;
        int res = 0;
        long long curr = 0, sign = 1;

        for (char c : s)
        {
            if (isdigit(c))
            {
                curr = 10 * curr + c - '0';
            }
            else if (c == '+')
            {
                res += curr * sign;
                curr = 0;
                sign = 1;
            }
            else if (c == '-')
            {
                res += curr * sign;
                curr = 0;
                sign = -1;
            }
            else if (c == '(')
            {
                nums.push(res);
                nums.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                res += curr * sign;
                curr = 0;

                res = res * nums.top();
                nums.pop();
                res = res + nums.top();
                nums.pop();
            }
        }

        res += curr * sign;
        return res;
    }
};
