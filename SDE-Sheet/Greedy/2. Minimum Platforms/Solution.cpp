// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int p1 = 0, p2 = 0;
        int count = 0, ans = 0;
        while (p1 < n && p2 < n)
        {
            if (arr[p1] <= dep[p2])
            {
                count++;
                ans = max(ans, count);
                p1++;
            }
            else
            {
                count--;
                p2++;
            }
        }

        return ans;
    }
};
