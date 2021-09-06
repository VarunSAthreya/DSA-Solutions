// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double multiply(int num, int n)
    {
        double ans = 1.0;
        for (int i = 1; i <= n; i++)
            ans *= num;

        return ans;
    }

    int NthRoot(int n, int m)
    {
        if (m == 1 || n == 1)
            return m;
        int low = 1, high = m;
        double mid;

        while (high - low > 1)
        {
            mid = low + (high - low) / 2.0;

            double mm = multiply(mid, n);

            if (mm == m)
                return mid;
            if (mm < m)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
