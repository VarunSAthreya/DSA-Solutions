class Solution
{
public:
    double myPow(double x, int n)
    {
        long long nn = n;
        double ans = 1.0;
        if (n < 0) // if -ve
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2 == 1) // odd
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else // even
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) // if -ve
            ans = 1.0 / ans;

        return ans;
    }
};
